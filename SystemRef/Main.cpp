// ======================================================================
// \title  Main.cpp
// \brief main program for the F' application. Intended for CLI-based systems (Linux, macOS)
//
// ======================================================================
// Used to access topology functions
#include <SystemRef/Top/SystemRefTopology.hpp>
// Used for signal handling shutdown
#include <signal.h>
// Used for command line argument processing
#include <getopt.h>
// Used for printf functions
#include <cstdlib>

// Used for logging
#include <Os/Log.hpp>
#include <Arduino/Os/StreamLog.hpp>

// Instantiate a system logger that will handle Fw::Logger::logMsg calls
Os::Log logger;

/**
 * \brief print command line help message
 *
 * This will print a command line help message including the available command line arguments.
 *
 * @param app: name of application
 */
void print_usage(const char *app)
{
    (void)printf("Usage: ./%s [options]\n-a\thostname/IP address\n-p\tport_number\n", app);
}

/**
 * \brief shutdown topology cycling on signal
 *
 * The reference topology allows for a simulated cycling of the rate groups. This simulated cycling needs to be stopped
 * in order for the program to shutdown. This is done via handling signals such that it is performed via Ctrl-C
 *
 * @param signum
 */
static void signalHandler(int signum)
{
    SystemRef::stopSimulatedCycle();
}

/**
 * \brief execute the program
 *
 * This F´ program is designed to run in standard environments (e.g. Linux/macOs running on a laptop). Thus it uses
 * command line inputs to specify how to connect.
 *
 * @param argc: argument count supplied to program
 * @param argv: argument values supplied to program
 * @return: 0 on success, something else on failure
 */
int main(void)
{
    Os::setArduinoStreamLogHandler(&Serial);

    U32 port_number = 0;
    char *hostname = nullptr;

    // Object for communicating state to the reference topology
    SystemRef::TopologyState inputs;
    inputs.hostname = hostname;
    inputs.port = port_number;

    // Setup program shutdown via Ctrl-C
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);
    (void)printf("Hit Ctrl-C to quit\n");

    // Setup, cycle, and teardown topology
    SystemRef::setupTopology(inputs);
    SystemRef::startSimulatedCycle(1000); // Program loop cycling rate groups at 1Hz
    SystemRef::teardownTopology(inputs);
    return 0;
}
