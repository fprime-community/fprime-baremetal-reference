// ======================================================================
// \title  Main.cpp
// \brief main program for the F' application.
//
// ======================================================================
// Used to access topology functions
#include <BaremetalReference/Top/BaremetalReferenceTopologyAc.hpp>
#include <BaremetalReference/Top/BaremetalReferenceTopology.hpp>
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
void setup()
{
    // Setup Serial
    Serial.begin(115200);
    Os::setArduinoStreamLogHandler(&Serial);
    delay(1000);
    Fw::Logger::logMsg("Program Started\n");

    // Object for communicating state to the reference topology
    BaremetalReference::TopologyState inputs;
    inputs.uartNumber = 0;
    inputs.uartBaud = 115200;

    // Setup, cycle, and teardown topology
    BaremetalReference::setupTopology(inputs);
    // BaremetalReference::teardownTopology(inputs);
}

void loop()
{
#ifdef USE_BASIC_TIMER
    rateDriver.cycle();
#endif
    taskrunner.run();
}
