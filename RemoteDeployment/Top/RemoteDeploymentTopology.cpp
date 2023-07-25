// ======================================================================
// \title  RemoteDeploymentTopology.cpp
// \brief cpp file containing the topology instantiation code
//
// ======================================================================
// Provides access to autocoded functions
#include <RemoteDeployment/Top/RemoteDeploymentTopologyAc.hpp>
#include <RemoteDeployment/Top/RemoteDeploymentPacketsAc.hpp>

#include <Utils/Hash/HashConfig.hpp>

// Necessary project-specified types
#include <Fw/Types/MallocAllocator.hpp>
#include <Os/Log.hpp>
#include <Svc/FramingProtocol/FprimeProtocol.hpp>

// Used for 1Hz synthetic cycling
#include <Os/Mutex.hpp>

// Allows easy reference to objects in FPP/autocoder required namespaces
using namespace RemoteDeployment;

// Instantiate a system logger that will handle Fw::Logger::logMsg calls
Os::Log logger;

// The reference topology uses a malloc-based allocator for components that need to allocate memory during the
// initialization phase.
Fw::MallocAllocator mallocator;

// The reference topology uses the F´ packet protocol when communicating with the ground and therefore uses the F´
// framing and deframing implementations.
Svc::FprimeFraming framing;
Svc::FprimeDeframing deframing;

// The reference topology divides the incoming clock signal (1Hz) into sub-signals: 1Hz, 1/2Hz, and 1/4Hz
NATIVE_INT_TYPE rateGroupDivisors[Svc::RateGroupDriver::DIVIDER_SIZE] = {1, 100, 1000};

// Rate groups may supply a context token to each of the attached children whose purpose is set by the project. The
// reference topology sets each token to zero as these contexts are unused in this project.
NATIVE_INT_TYPE rateGroup1Context[Svc::ActiveRateGroup::CONNECTION_COUNT_MAX] = {};
NATIVE_INT_TYPE rateGroup2Context[Svc::ActiveRateGroup::CONNECTION_COUNT_MAX] = {};
NATIVE_INT_TYPE rateGroup3Context[Svc::ActiveRateGroup::CONNECTION_COUNT_MAX] = {};

// A number of constants are needed for construction of the topology. These are specified here.
enum TopologyConstants
{
    CMD_SEQ_BUFFER_SIZE = 5 * 1024,
    FILE_DOWNLINK_TIMEOUT = 1000,
    FILE_DOWNLINK_COOLDOWN = 1000,
    FILE_DOWNLINK_CYCLE_TIME = 1000,
    FILE_DOWNLINK_FILE_QUEUE_DEPTH = 10,
    HEALTH_WATCHDOG_CODE = 0x123,
    COMM_PRIORITY = 100,
    // bufferManager constants
    FRAMER_BUFFER_SIZE = FW_MAX(FW_COM_BUFFER_MAX_SIZE, FW_FILE_BUFFER_MAX_SIZE + sizeof(U32)) + HASH_DIGEST_LENGTH + Svc::FpFrameHeader::SIZE,
    FRAMER_BUFFER_COUNT = 30,
    DEFRAMER_BUFFER_SIZE = FW_MAX(FW_COM_BUFFER_MAX_SIZE, FW_FILE_BUFFER_MAX_SIZE + sizeof(U32)),
    DEFRAMER_BUFFER_COUNT = 30,
    COM_DRIVER_BUFFER_SIZE = 3000,
    COM_DRIVER_BUFFER_COUNT = 30,
    BUFFER_MANAGER_ID = 200
};

// Ping entries are autocoded, however; this code is not properly exported. Thus, it is copied here.
Svc::Health::PingEntry pingEntries[] = {
    {PingEntries::r_blockDrv::WARN, PingEntries::r_blockDrv::FATAL, "r_blockDrv"},
    {PingEntries::r_cmdDisp::WARN, PingEntries::r_cmdDisp::FATAL, "r_cmdDisp"},
    {PingEntries::r_fileDownlink::WARN, PingEntries::r_fileDownlink::FATAL, "r_fileDownlink"},
    {PingEntries::r_fileManager::WARN, PingEntries::r_fileManager::FATAL, "r_fileManager"},
    {PingEntries::r_prmDb::WARN, PingEntries::r_prmDb::FATAL, "r_prmDb"},
    {PingEntries::r_rateGroup1::WARN, PingEntries::r_rateGroup1::FATAL, "r_rateGroup1"},
    {PingEntries::r_rateGroup2::WARN, PingEntries::r_rateGroup2::FATAL, "r_rateGroup2"},
    {PingEntries::r_rateGroup3::WARN, PingEntries::r_rateGroup3::FATAL, "r_rateGroup3"},
};

/**
 * \brief configure/setup components in project-specific way
 *
 * This is a *helper* function which configures/sets up each component requiring project specific input. This includes
 * allocating resources, passing-in arguments, etc. This function may be inlined into the topology setup function if
 * desired, but is extracted here for clarity.
 */
void configureTopology()
{
    // Buffer managers need a configured set of buckets and an allocator used to allocate memory for those buckets.
    Svc::BufferManager::BufferBins upBuffMgrBins;
    memset(&upBuffMgrBins, 0, sizeof(upBuffMgrBins));
    upBuffMgrBins.bins[0].bufferSize = FRAMER_BUFFER_SIZE;
    upBuffMgrBins.bins[0].numBuffers = FRAMER_BUFFER_COUNT;
    upBuffMgrBins.bins[1].bufferSize = DEFRAMER_BUFFER_SIZE;
    upBuffMgrBins.bins[1].numBuffers = DEFRAMER_BUFFER_COUNT;
    upBuffMgrBins.bins[2].bufferSize = COM_DRIVER_BUFFER_SIZE;
    upBuffMgrBins.bins[2].numBuffers = COM_DRIVER_BUFFER_COUNT;
    r_bufferManager.setup(BUFFER_MANAGER_ID, 0, mallocator, upBuffMgrBins);

    // Framer and Deframer components need to be passed a protocol handler
    r_hubFramer.setup(framing);
    r_hubDeframer.setup(deframing);

    // Rate group driver needs a divisor list
    r_rateGroupDriver.configure(rateGroupDivisors, FW_NUM_ARRAY_ELEMENTS(rateGroupDivisors));

    // Rate groups require context arrays.
    r_rateGroup1.configure(rateGroup1Context, FW_NUM_ARRAY_ELEMENTS(rateGroup1Context));
    r_rateGroup2.configure(rateGroup2Context, FW_NUM_ARRAY_ELEMENTS(rateGroup2Context));
    r_rateGroup3.configure(rateGroup3Context, FW_NUM_ARRAY_ELEMENTS(rateGroup3Context));

    // File downlink requires some project-derived properties.
    r_fileDownlink.configure(FILE_DOWNLINK_TIMEOUT, FILE_DOWNLINK_COOLDOWN, FILE_DOWNLINK_CYCLE_TIME,
                             FILE_DOWNLINK_FILE_QUEUE_DEPTH);

    // Parameter database is configured with a database file name, and that file must be initially read.
    r_prmDb.configure("PrmDb.dat");
    r_prmDb.readParamFile();

    // Health is supplied a set of ping entires.
    r_health.setPingEntries(pingEntries, FW_NUM_ARRAY_ELEMENTS(pingEntries), HEALTH_WATCHDOG_CODE);

    if (r_hubDriver.open("/dev/ttyS0", Drv::LinuxUartDriver::UartBaudRate::BAUD_115K, Drv::LinuxUartDriver::NO_FLOW, Drv::LinuxUartDriver::PARITY_NONE, 1024))
    {
        r_hubDriver.startReadThread(100, Default::STACK_SIZE);
        printf("UART port successfully opened\n");
    }
    else
    {
        printf("Failed to open UART port %s at speed %" PRIu32 "\n", "/dev/ttyS0", "BAUD_115K");
    }
}

// Public functions for use in main program are namespaced with deployment name RemoteDeployment
namespace RemoteDeployment
{
    void setupTopology(const TopologyState &state)
    {
        // Autocoded initialization. Function provided by autocoder.
        initComponents(state);
        // Autocoded id setup. Function provided by autocoder.
        setBaseIds();
        // Autocoded connection wiring. Function provided by autocoder.
        connectComponents();
        // Project-specific component configuration. Function provided above. May be inlined, if desired.
        configureTopology();
        // Autocoded parameter loading. Function provided by autocoder.
        // loadParameters();
        // Autocoded command registration. Function provided by autocoder.
        regCommands();
        // Autocoded task kick-off (active components). Function provided by autocoder.
        startTasks(state);
    }

    // Variables used for cycle simulation
    Os::Mutex cycleLock;
    volatile bool cycleFlag = true;

    void startSimulatedCycle(U32 milliseconds)
    {
        cycleLock.lock();
        bool cycling = cycleFlag;
        cycleLock.unLock();

        // Main loop
        while (cycling)
        {
            RemoteDeployment::r_blockDrv.callIsr();
            Os::Task::delay(milliseconds);

            cycleLock.lock();
            cycling = cycleFlag;
            cycleLock.unLock();
        }
    }

    void stopSimulatedCycle()
    {
        cycleLock.lock();
        cycleFlag = false;
        cycleLock.unLock();
    }

    void teardownTopology(const TopologyState &state)
    {
        // Autocoded (active component) task clean-up. Functions provided by topology autocoder.
        stopTasks(state);
        freeThreads(state);

        // Resource deallocation
        r_bufferManager.cleanup();
    }
}; // namespace RemoteDeployment
