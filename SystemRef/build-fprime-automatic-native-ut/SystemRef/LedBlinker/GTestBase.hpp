// ======================================================================
// \title  LedBlinker/test/ut/GTestBase.hpp
// \author Auto-generated
// \brief  hpp file for LedBlinker component Google Test harness base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef LedBlinker_GTEST_BASE_HPP
#define LedBlinker_GTEST_BASE_HPP

#include "TesterBase.hpp"
#include "gtest/gtest.h"

// ----------------------------------------------------------------------
// Macros for command history assertions
// ----------------------------------------------------------------------

#define ASSERT_CMD_RESPONSE_SIZE(size) \
  this->assertCmdResponse_size(__FILE__, __LINE__, size)

#define ASSERT_CMD_RESPONSE(index, opCode, cmdSeq, response) \
  this->assertCmdResponse(__FILE__, __LINE__, index, opCode, cmdSeq, response)

// ----------------------------------------------------------------------
// Macros for telemetry history assertions
// ----------------------------------------------------------------------

#define ASSERT_TLM_SIZE(size) \
  this->assertTlm_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_BlinkingState_SIZE(size) \
  this->assertTlm_BlinkingState_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_BlinkingState(index, value) \
  this->assertTlm_BlinkingState(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_LedTransitions_SIZE(size) \
  this->assertTlm_LedTransitions_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_LedTransitions(index, value) \
  this->assertTlm_LedTransitions(__FILE__, __LINE__, index, value)

// ----------------------------------------------------------------------
// Macros for event history assertions
// ----------------------------------------------------------------------

#define ASSERT_EVENTS_SIZE(size) \
  this->assertEvents_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_InvalidBlinkArgument_SIZE(size) \
  this->assertEvents_InvalidBlinkArgument_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_InvalidBlinkArgument(index, _badArgument) \
  this->assertEvents_InvalidBlinkArgument(__FILE__, __LINE__, index, _badArgument)

#define ASSERT_EVENTS_SetBlinkingState_SIZE(size) \
  this->assertEvents_SetBlinkingState_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_SetBlinkingState(index, _state) \
  this->assertEvents_SetBlinkingState(__FILE__, __LINE__, index, _state)

#define ASSERT_EVENTS_LedState_SIZE(size) \
  this->assertEvents_LedState_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_LedState(index, _on_off) \
  this->assertEvents_LedState(__FILE__, __LINE__, index, _on_off)

#define ASSERT_EVENTS_BlinkIntervalSet_SIZE(size) \
  this->assertEvents_BlinkIntervalSet_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_BlinkIntervalSet(index, _interval) \
  this->assertEvents_BlinkIntervalSet(__FILE__, __LINE__, index, _interval)

// ----------------------------------------------------------------------
// Macros for typed user from port history assertions
// ----------------------------------------------------------------------

#define ASSERT_FROM_PORT_HISTORY_SIZE(size) \
  this->assertFromPortHistory_size(__FILE__, __LINE__, size)

#define ASSERT_from_gpioSet_SIZE(size) \
  this->assert_from_gpioSet_size(__FILE__, __LINE__, size)

#define ASSERT_from_gpioSet(index, _state) \
  { \
    ASSERT_GT(this->fromPortHistory_gpioSet->size(), static_cast<U32>(index)) \
    << "\n" \
    << __FILE__ << ":" << __LINE__ << "\n" \
    << "  Value:    Index into history of from_gpioSet\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_gpioSet->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_gpioSet& _e = \
      this->fromPortHistory_gpioSet->at(index); \
    ASSERT_EQ(_state, _e.state) \
    << "\n" \
    << __FILE__ << ":" << __LINE__ << "\n" \
    << "  Value:    Value of argument state at index " \
    << index \
    << " in history of from_gpioSet\n" \
    << "  Expected: " << _state << "\n" \
    << "  Actual:   " << _e.state << "\n"; \
  }

namespace SystemRef {

  //! \class LedBlinkerGTestBase
  //! \brief Auto-generated base class for LedBlinker component Google Test harness
  //!
  class LedBlinkerGTestBase :
    public LedBlinkerTesterBase
  {

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object LedBlinkerGTestBase
      //!
      LedBlinkerGTestBase(
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
      );

      //! Destroy object LedBlinkerGTestBase
      //!
      virtual ~LedBlinkerGTestBase(void);

    protected:

      // ----------------------------------------------------------------------
      // Commands
      // ----------------------------------------------------------------------

      //! Assert size of command response history
      //!
      void assertCmdResponse_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      //! Assert command response in history at index
      //!
      void assertCmdResponse(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          const Fw::CmdResponse response /*!< The command response*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Telemetry
      // ----------------------------------------------------------------------

      //! Assert size of telemetry history
      //!
      void assertTlm_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: BlinkingState
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_BlinkingState_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_BlinkingState(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const Fw::On& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: LedTransitions
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_LedTransitions_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_LedTransitions(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U64& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Events
      // ----------------------------------------------------------------------

      void assertEvents_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: InvalidBlinkArgument
      // ----------------------------------------------------------------------

      void assertEvents_InvalidBlinkArgument_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_InvalidBlinkArgument(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const Fw::On badArgument 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: SetBlinkingState
      // ----------------------------------------------------------------------

      void assertEvents_SetBlinkingState_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_SetBlinkingState(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const Fw::On state 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: LedState
      // ----------------------------------------------------------------------

      void assertEvents_LedState_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_LedState(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const Fw::On on_off 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: BlinkIntervalSet
      // ----------------------------------------------------------------------

      void assertEvents_BlinkIntervalSet_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_BlinkIntervalSet(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U32 interval 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From ports
      // ----------------------------------------------------------------------

      void assertFromPortHistory_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From port: gpioSet
      // ----------------------------------------------------------------------

      void assert_from_gpioSet_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

  };

} // end namespace SystemRef

#endif
