// ======================================================================
// \title  RadioPassthroughTopology.cpp
// \brief cpp file containing the topology instantiation code
//
// ======================================================================
// Provides access to autocoded functions
#include <RadioPassthrough/Top/RadioPassthroughTopologyAc.hpp>
#include <RadioPassthrough/Top/RadioPassthroughPacketsAc.hpp>
#include <config/FppConstantsAc.hpp>

// Necessary project-specified types
#include <Os/Log.hpp>
#include <Svc/FramingProtocol/FprimeProtocol.hpp>

#include  <Components/Radio/RFM69/RFM69.hpp>

// Allows easy reference to objects in FPP/autocoder required namespaces
using namespace RadioPassthrough;

// The reference topology divides the incoming clock signal (1kHz) into sub-signals: 1kHz, 10Hz
Svc::RateGroupDriver::DividerSet rateGroupDivisors = {{ {1, 0}, {100, 0} }};

// Rate groups may supply a context token to each of the attached children whose purpose is set by the project. The
// reference topology sets each token to zero as these contexts are unused in this project.
NATIVE_INT_TYPE rateGroup1Context[FppConstant_PassiveRateGroupOutputPorts::PassiveRateGroupOutputPorts] = {};
NATIVE_INT_TYPE rateGroup2Context[FppConstant_PassiveRateGroupOutputPorts::PassiveRateGroupOutputPorts] = {};

/**
 * \brief configure/setup components in project-specific way
 *
 * This is a *helper* function which configures/sets up each component requiring project specific input. This includes
 * allocating resources, passing-in arguments, etc. This function may be inlined into the topology setup function if
 * desired, but is extracted here for clarity.
 */
void configureTopology() {

    // Rate group driver needs a divisor list
    rateGroupDriver.configure(rateGroupDivisors);

    // Rate groups require context arrays.
    rateGroup1.configure(rateGroup1Context, FW_NUM_ARRAY_ELEMENTS(rateGroup1Context));
    rateGroup2.configure(rateGroup2Context, FW_NUM_ARRAY_ELEMENTS(rateGroup2Context));

}

// Public functions for use in main program are namespaced with deployment name BaremetalReference
namespace RadioPassthrough {
void setupTopology(const TopologyState& state) {
    // Autocoded initialization. Function provided by autocoder.
    initComponents(state);
    // Autocoded id setup. Function provided by autocoder.
    setBaseIds();
    // Autocoded connection wiring. Function provided by autocoder.
    connectComponents();
    // Autocoded command registration. Function provided by autocoder.
    // regCommands();
    // Project-specific component configuration. Function provided above. May be inlined, if desired.
    configureTopology();
    // Autocoded parameter loading. Function provided by autocoder.
    // loadParameters();
    // Autocoded task kick-off (active components). Function provided by autocoder.
    startTasks(state);

    // Configure hardware rate driver
    rateDriver.configure(1);

    // Configure Serial
    commDriver.configure(&Serial);

    // Configure GPIO pins
    gpioDriver.open(Arduino::DEF_LED_BUILTIN, Arduino::GpioDriver::GpioDirection::OUT);
    gpioRadioReset.open(Radio::RFM69::RFM69_RST, Arduino::GpioDriver::GpioDirection::OUT);

    // Start hardware rate driver
    rateDriver.start();
}

void teardownTopology(const TopologyState& state) {
    // Autocoded (active component) task clean-up. Functions provided by topology autocoder.
    stopTasks(state);
    freeThreads(state);

}
};  // namespace RadioPassthrough
