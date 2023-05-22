// ======================================================================
// \title  Main.cpp
// \brief main program for the F' application. Intended for CLI-based systems (Linux, macOS)
//
// ======================================================================
// Used to access topology functions
#include <SystemRef/Top/SystemRefTopology.hpp>
// Used for command line argument processing
#include <getopt.h>
// Used for printf functions
#include <cstdlib>
// Used for Task Runner
#include <Os/Baremetal/TaskRunner/TaskRunner.hpp>

// Used for logging
#include <Os/Log.hpp>
#include <Arduino/Os/StreamLog.hpp>

// Instantiate a system logger that will handle Fw::Logger::logMsg calls
Os::Log logger;

// Task Runner
Os::TaskRunner taskrunner;

/**
 * \brief execute the program
 *
 * This F´ program is designed to run in standard environments (e.g. Linux/macOs running on a laptop). Thus it uses
 * command line inputs to specify how to connect.
 *
 * @return: 0 on success, something else on failure
 */
int main(void)
{
    Os::setArduinoStreamLogHandler(&Serial);

    // Object for communicating state to the reference topology
    SystemRef::TopologyState inputs;
    inputs.uartNumber = 0;
    inputs.uartBaud = 115200;

    // Setup, cycle, and teardown topology
    SystemRef::setupTopology(inputs);
    while(true)
    {
        taskrunner.run();
    }
    SystemRef::teardownTopology(inputs);
    return 0;
}
