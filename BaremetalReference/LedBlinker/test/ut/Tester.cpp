// ======================================================================
// \title  LedBlinker.hpp
// \author ethan
// \brief  cpp file for LedBlinker test harness implementation class
// ======================================================================

#include "Tester.hpp"

namespace BaremetalReference {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  Tester ::
    Tester() :
      LedBlinkerGTestBase("Tester", Tester::MAX_HISTORY_SIZE),
      component("LedBlinker")
  {
    this->initComponents();
    this->connectPorts();
  }

  Tester ::
    ~Tester()
  {

  }

  // ----------------------------------------------------------------------
  // Tests
  // ----------------------------------------------------------------------

  void Tester ::
    toDo()
  {
    // TODO
  }

  void Tester ::
    testBlinking()
  {
    this->invoke_to_run(0,0); // invoke the 'run' port to simulate running one cycle
    ASSERT_EVENTS_LedState_SIZE(0); // ensure no LedState change events we emitted
    ASSERT_from_gpioSet_SIZE(0); // ensure gpio LED wasn't set
    ASSERT_TLM_LedTransitions_SIZE(0); // ensure no LedTransitions were recorded
  }

  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  void Tester ::
    from_gpioSet_handler(
        const NATIVE_INT_TYPE portNum,
        const Fw::Logic &state
    )
  {
    this->pushFromPortEntry_gpioSet(state);
  }


} // end namespace BaremetalReference
