// ======================================================================
// \title  SystemRefTopology.cpp
// \brief cpp file containing the topology instantiation code
//
// ======================================================================
// Provides access to autocoded functions
#include <SystemRef/Top/SystemRefTopologyAc.hpp>
#include <SystemRef/Top/SystemRefPacketsAc.hpp>

// Necessary project-specified types
#include <Fw/Types/MallocAllocator.hpp>
#include <Os/Log.hpp>
#include <Svc/FramingProtocol/FprimeProtocol.hpp>

// Used for 1Hz synthetic cycling
#include <Os/Mutex.hpp>

#include <FprimeArduino.hpp>


// Allows easy reference to objects in FPP/autocoder required namespaces
using namespace SystemRef;

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
NATIVE_INT_TYPE rateGroupDivisors[Svc::RateGroupDriver::DIVIDER_SIZE] = {1, 2, 4};

// Rate groups may supply a context token to each of the attached children whose purpose is set by the project. The
// reference topology sets each token to zero as these contexts are unused in this project.
NATIVE_INT_TYPE rateGroup1Context[Svc::ActiveRateGroup::CONNECTION_COUNT_MAX] = {};
// NATIVE_INT_TYPE rateGroup2Context[Svc::ActiveRateGroup::CONNECTION_COUNT_MAX] = {};
// NATIVE_INT_TYPE rateGroup3Context[Svc::ActiveRateGroup::CONNECTION_COUNT_MAX] = {};

// A number of constants are needed for construction of the topology. These are specified here.
enum TopologyConstants {
    CMD_SEQ_BUFFER_SIZE = 5 * 1024,
    FILE_DOWNLINK_TIMEOUT = 1000,
    FILE_DOWNLINK_COOLDOWN = 1000,
    FILE_DOWNLINK_CYCLE_TIME = 1000,
    FILE_DOWNLINK_FILE_QUEUE_DEPTH = 10,
    HEALTH_WATCHDOG_CODE = 0x123,
    COMM_PRIORITY = 100,
    UPLINK_BUFFER_MANAGER_STORE_SIZE = 3000,
    UPLINK_BUFFER_MANAGER_QUEUE_SIZE = 30,
    UPLINK_BUFFER_MANAGER_ID = 200
};

/**
 * \brief configure/setup components in project-specific way
 *
 * This is a *helper* function which configures/sets up each component requiring project specific input. This includes
 * allocating resources, passing-in arguments, etc. This function may be inlined into the topology setup function if
 * desired, but is extracted here for clarity.
 */
void configureTopology() {
    // Command sequencer needs to allocate memory to hold contents of command sequences
    cmdSeq.allocateBuffer(0, mallocator, CMD_SEQ_BUFFER_SIZE);

    // Rate group driver needs a divisor list
    rateGroupDriver.configure(rateGroupDivisors, FW_NUM_ARRAY_ELEMENTS(rateGroupDivisors));

    // Rate groups require context arrays.
    rateGroup1.configure(rateGroup1Context, FW_NUM_ARRAY_ELEMENTS(rateGroup1Context));
    // rateGroup2.configure(rateGroup2Context, FW_NUM_ARRAY_ELEMENTS(rateGroup2Context));
    // rateGroup3.configure(rateGroup3Context, FW_NUM_ARRAY_ELEMENTS(rateGroup3Context));

    // File downlink requires some project-derived properties.
    fileDownlink.configure(FILE_DOWNLINK_TIMEOUT, FILE_DOWNLINK_COOLDOWN, FILE_DOWNLINK_CYCLE_TIME,
                           FILE_DOWNLINK_FILE_QUEUE_DEPTH);

    // Parameter database is configured with a database file name, and that file must be initially read.
    // prmDb.configure("PrmDb.dat");
    // prmDb.readParamFile();

    // Health is supplied a set of ping entires.
    // health.setPingEntries(pingEntries, FW_NUM_ARRAY_ELEMENTS(pingEntries), HEALTH_WATCHDOG_CODE);

    // Buffer managers need a configured set of buckets and an allocator used to allocate memory for those buckets.
    Svc::BufferManager::BufferBins upBuffMgrBins;
    memset(&upBuffMgrBins, 0, sizeof(upBuffMgrBins));
    upBuffMgrBins.bins[0].bufferSize = UPLINK_BUFFER_MANAGER_STORE_SIZE;
    upBuffMgrBins.bins[0].numBuffers = UPLINK_BUFFER_MANAGER_QUEUE_SIZE;
    fileUplinkBufferManager.setup(UPLINK_BUFFER_MANAGER_ID, 0, mallocator, upBuffMgrBins);

    // Framer and Deframer components need to be passed a protocol handler
    downlink.setup(framing);
    uplink.setup(deframing);

    // Note: Uncomment when using Svc:TlmPacketizer
    //tlmSend.setPacketList(SystemRefPacketsPkts, SystemRefPacketsIgnore, 1);
}

// Public functions for use in main program are namespaced with deployment name SystemRef
namespace SystemRef {
void setupTopology(const TopologyState& state) {
    Serial.println("0");
    // Autocoded initialization. Function provided by autocoder.
    initComponents(state);
    Serial.println("1");
    // Autocoded id setup. Function provided by autocoder.
    setBaseIds();
    Serial.println("2");
    // Autocoded connection wiring. Function provided by autocoder.
    connectComponents();
    Serial.println("3");
    // Autocoded command registration. Function provided by autocoder.
    regCommands();
    Serial.println("4");
    // Project-specific component configuration. Function provided above. May be inlined, if desired.
    configureTopology();
    Serial.println("5");
    // Autocoded parameter loading. Function provided by autocoder.
    // loadParameters();
    Serial.println("6");
    // Autocoded task kick-off (active components). Function provided by autocoder.
    startTasks(state);
    Serial.println("7");
    
    rateDriver.configure(1000);
    rateDriver.start();
    Serial.println("8");
}

// Variables used for cycle simulation
Os::Mutex cycleLock;
volatile bool cycleFlag = true;

void startSimulatedCycle(U32 milliseconds) {
    Serial.println("start cycle");
    cycleLock.lock();
    bool cycling = cycleFlag;
    cycleLock.unLock();

    pinMode(13, 1);

    // Main loop
    while (cycling) {
        SystemRef::blockDrv.callIsr();
        // Serial.println(milliseconds);
        digitalWrite(13, 1);
        // Os::Task::delay(milliseconds);   
        delay(milliseconds);  
        digitalWrite(13, 0);  
        delay(milliseconds);  

        cycleLock.lock();
        cycling = cycleFlag;
        cycleLock.unLock();
    }
}

void stopSimulatedCycle() {
    cycleLock.lock();
    cycleFlag = false;
    cycleLock.unLock();
}

void teardownTopology(const TopologyState& state) {
    // Autocoded (active component) task clean-up. Functions provided by topology autocoder.
    stopTasks(state);
    freeThreads(state);

    // Other task clean-up.
    // comm.stopSocketTask();
    // (void)comm.joinSocketTask(nullptr);

    // Resource deallocation
    cmdSeq.deallocateBuffer(mallocator);
    // fileUplinkBufferManager.cleanup();
}
};  // namespace SystemRef
