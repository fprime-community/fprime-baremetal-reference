// ======================================================================
// \title  LedBlinker/test/ut/GTestBase.cpp
// \author Auto-generated
// \brief  cpp file for LedBlinker component Google Test harness base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include "GTestBase.hpp"

namespace SystemRef {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  LedBlinkerGTestBase ::
    LedBlinkerGTestBase(
        const char *const compName,
        const U32 maxHistorySize
    ) :
        LedBlinkerTesterBase (
            compName,
            maxHistorySize
        )
  {

  }

  LedBlinkerGTestBase ::
    ~LedBlinkerGTestBase()
  {

  }

  // ----------------------------------------------------------------------
  // Commands
  // ----------------------------------------------------------------------

  void LedBlinkerGTestBase ::
    assertCmdResponse_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->cmdResponseHistory->size())
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Size of command response history\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->cmdResponseHistory->size() << "\n";
  }

  void LedBlinkerGTestBase ::
    assertCmdResponse(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CmdResponse response
    )
    const
  {
    ASSERT_LT(__index, this->cmdResponseHistory->size())
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Index into command response history\n"
      << "  Expected: Less than size of command response history ("
      << this->cmdResponseHistory->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const CmdResponse& e = this->cmdResponseHistory->at(__index);
    ASSERT_EQ(opCode, e.opCode)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Opcode at index "
      << __index
      << " in command response history\n"
      << "  Expected: " << opCode << "\n"
      << "  Actual:   " << e.opCode << "\n";
    ASSERT_EQ(cmdSeq, e.cmdSeq)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Command sequence number at index "
      << __index
      << " in command response history\n"
      << "  Expected: " << cmdSeq << "\n"
      << "  Actual:   " << e.cmdSeq << "\n";
    ASSERT_EQ(response, e.response)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Command response at index "
      << __index
      << " in command response history\n"
      << "  Expected: " << response << "\n"
      << "  Actual:   " << e.response << "\n";
  }

  // ----------------------------------------------------------------------
  // Telemetry
  // ----------------------------------------------------------------------

  void LedBlinkerGTestBase ::
    assertTlm_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->tlmSize)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all telemetry histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmSize << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: BlinkingState
  // ----------------------------------------------------------------------

  void LedBlinkerGTestBase ::
    assertTlm_BlinkingState_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_BlinkingState->size(), size)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel BlinkingState\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_BlinkingState->size() << "\n";
  }

  void LedBlinkerGTestBase ::
    assertTlm_BlinkingState(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const Fw::On& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_BlinkingState->size())
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel BlinkingState\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_BlinkingState->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_BlinkingState& e =
      this->tlmHistory_BlinkingState->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telemetry channel BlinkingState\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: LedTransitions
  // ----------------------------------------------------------------------

  void LedBlinkerGTestBase ::
    assertTlm_LedTransitions_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_LedTransitions->size(), size)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel LedTransitions\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_LedTransitions->size() << "\n";
  }

  void LedBlinkerGTestBase ::
    assertTlm_LedTransitions(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U64& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_LedTransitions->size())
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel LedTransitions\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_LedTransitions->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_LedTransitions& e =
      this->tlmHistory_LedTransitions->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telemetry channel LedTransitions\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Events
  // ----------------------------------------------------------------------

  void LedBlinkerGTestBase ::
    assertEvents_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventsSize)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all event histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventsSize << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: InvalidBlinkArgument
  // ----------------------------------------------------------------------

  void LedBlinkerGTestBase ::
    assertEvents_InvalidBlinkArgument_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_InvalidBlinkArgument->size())
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event InvalidBlinkArgument\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_InvalidBlinkArgument->size() << "\n";
  }

  void LedBlinkerGTestBase ::
    assertEvents_InvalidBlinkArgument(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const Fw::On badArgument
    ) const
  {
    ASSERT_GT(this->eventHistory_InvalidBlinkArgument->size(), __index)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event InvalidBlinkArgument\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_InvalidBlinkArgument->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_InvalidBlinkArgument& e =
      this->eventHistory_InvalidBlinkArgument->at(__index);
    ASSERT_EQ(badArgument, e.badArgument)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument badArgument at index "
      << __index
      << " in history of event InvalidBlinkArgument\n"
      << "  Expected: " << badArgument << "\n"
      << "  Actual:   " << e.badArgument << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: SetBlinkingState
  // ----------------------------------------------------------------------

  void LedBlinkerGTestBase ::
    assertEvents_SetBlinkingState_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_SetBlinkingState->size())
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event SetBlinkingState\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_SetBlinkingState->size() << "\n";
  }

  void LedBlinkerGTestBase ::
    assertEvents_SetBlinkingState(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const Fw::On state
    ) const
  {
    ASSERT_GT(this->eventHistory_SetBlinkingState->size(), __index)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event SetBlinkingState\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_SetBlinkingState->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_SetBlinkingState& e =
      this->eventHistory_SetBlinkingState->at(__index);
    ASSERT_EQ(state, e.state)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument state at index "
      << __index
      << " in history of event SetBlinkingState\n"
      << "  Expected: " << state << "\n"
      << "  Actual:   " << e.state << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: LedState
  // ----------------------------------------------------------------------

  void LedBlinkerGTestBase ::
    assertEvents_LedState_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_LedState->size())
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event LedState\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_LedState->size() << "\n";
  }

  void LedBlinkerGTestBase ::
    assertEvents_LedState(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const Fw::On on_off
    ) const
  {
    ASSERT_GT(this->eventHistory_LedState->size(), __index)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event LedState\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_LedState->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_LedState& e =
      this->eventHistory_LedState->at(__index);
    ASSERT_EQ(on_off, e.on_off)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument on_off at index "
      << __index
      << " in history of event LedState\n"
      << "  Expected: " << on_off << "\n"
      << "  Actual:   " << e.on_off << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: BlinkIntervalSet
  // ----------------------------------------------------------------------

  void LedBlinkerGTestBase ::
    assertEvents_BlinkIntervalSet_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_BlinkIntervalSet->size())
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event BlinkIntervalSet\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_BlinkIntervalSet->size() << "\n";
  }

  void LedBlinkerGTestBase ::
    assertEvents_BlinkIntervalSet(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U32 interval
    ) const
  {
    ASSERT_GT(this->eventHistory_BlinkIntervalSet->size(), __index)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event BlinkIntervalSet\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_BlinkIntervalSet->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_BlinkIntervalSet& e =
      this->eventHistory_BlinkIntervalSet->at(__index);
    ASSERT_EQ(interval, e.interval)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument interval at index "
      << __index
      << " in history of event BlinkIntervalSet\n"
      << "  Expected: " << interval << "\n"
      << "  Actual:   " << e.interval << "\n";
  }

  // ----------------------------------------------------------------------
  // From ports
  // ----------------------------------------------------------------------

  void LedBlinkerGTestBase ::
    assertFromPortHistory_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistorySize)
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all from port histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistorySize << "\n";
  }

  // ----------------------------------------------------------------------
  // From port: gpioSet
  // ----------------------------------------------------------------------

  void LedBlinkerGTestBase ::
    assert_from_gpioSet_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_gpioSet->size())
      << "\n"
      << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_gpioSet\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_gpioSet->size() << "\n";
  }

} // end namespace SystemRef
