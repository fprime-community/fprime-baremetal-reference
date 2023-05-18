// ======================================================================
// \title  LedBlinker/test/ut/TesterBase.hpp
// \author Auto-generated
// \brief  hpp file for LedBlinker component test harness base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef LedBlinker_TESTER_BASE_HPP
#define LedBlinker_TESTER_BASE_HPP

#include <SystemRef/LedBlinker/LedBlinkerComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <cstdio>
#include <Fw/Port/InputSerializePort.hpp>

namespace SystemRef {

  //! \class LedBlinkerTesterBase
  //! \brief Auto-generated base class for LedBlinker component test harness
  //!
  class LedBlinkerTesterBase :
    public Fw::PassiveComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Initialization
      // ----------------------------------------------------------------------

      //! Initialize object LedBlinkerTesterBase
      //!
      virtual void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

    public:

      // ----------------------------------------------------------------------
      // Connectors for 'to' ports
      // Connect these output ports to the input ports under test
      // ----------------------------------------------------------------------

      //! Connect cmdIn to to_cmdIn[portNum]
      //!
      void connect_to_cmdIn(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::InputCmdPort *const cmdIn /*!< The port*/
      );

      //! Connect run to to_run[portNum]
      //!
      void connect_to_run(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Svc::InputSchedPort *const run /*!< The port*/
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for 'from' ports
      // Connect these input ports to the output ports under test
      // ----------------------------------------------------------------------

      //! Get the port that receives input from cmdRegOut
      //!
      //! \return from_cmdRegOut[portNum]
      //!
      Fw::InputCmdRegPort* get_from_cmdRegOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from cmdResponseOut
      //!
      //! \return from_cmdResponseOut[portNum]
      //!
      Fw::InputCmdResponsePort* get_from_cmdResponseOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from gpioSet
      //!
      //! \return from_gpioSet[portNum]
      //!
      Drv::InputGpioWritePort* get_from_gpioSet(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from logOut
      //!
      //! \return from_logOut[portNum]
      //!
      Fw::InputLogPort* get_from_logOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Get the port that receives input from logTextOut
      //!
      //! \return from_logTextOut[portNum]
      //!
      Fw::InputLogTextPort* get_from_logTextOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );
#endif

      //! Get the port that receives input from prmGetOut
      //!
      //! \return from_prmGetOut[portNum]
      //!
      Fw::InputPrmGetPort* get_from_prmGetOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from prmSetOut
      //!
      //! \return from_prmSetOut[portNum]
      //!
      Fw::InputPrmSetPort* get_from_prmSetOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from timeCaller
      //!
      //! \return from_timeCaller[portNum]
      //!
      Fw::InputTimePort* get_from_timeCaller(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from tlmOut
      //!
      //! \return from_tlmOut[portNum]
      //!
      Fw::InputTlmPort* get_from_tlmOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object LedBlinkerTesterBase
      //!
      LedBlinkerTesterBase(
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
      );

      //! Destroy object LedBlinkerTesterBase
      //!
      virtual ~LedBlinkerTesterBase();

      // ----------------------------------------------------------------------
      // Test history
      // ----------------------------------------------------------------------

    protected:

      //! \class History
      //! \brief A history of port inputs
      //!
      template <typename T> class History {

        public:

          //! Create a History
          //!
          History(
              const U32 maxSize /*!< The maximum history size*/
          ) :
              numEntries(0),
              maxSize(maxSize)
          {
            this->entries = new T[maxSize];
          }

          //! Destroy a History
          //!
          ~History() {
            delete[] this->entries;
          }

          //! Clear the history
          //!
          void clear() { this->numEntries = 0; }

          //! Push an item onto the history
          //!
          void push_back(
              T entry /*!< The item*/
          ) {
            FW_ASSERT(this->numEntries < this->maxSize);
            entries[this->numEntries++] = entry;
          }

          //! Get an item at an index
          //!
          //! \return The item at index i
          //!
          T at(
              const U32 i /*!< The index*/
          ) const {
            FW_ASSERT(i < this->numEntries);
            return entries[i];
          }

          //! Get the number of entries in the history
          //!
          //! \return The number of entries in the history
          //!
          U32 size() const { return this->numEntries; }

        private:

          //! The number of entries in the history
          //!
          U32 numEntries;

          //! The maximum history size
          //!
          const U32 maxSize;

          //! The entries
          //!
          T *entries;

      };

      //! Clear all history
      //!
      void clearHistory();

    protected:

      // ----------------------------------------------------------------------
      // Handler prototypes for typed from ports
      // ----------------------------------------------------------------------

      //! Handler prototype for from_gpioSet
      //!
      virtual void from_gpioSet_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          const Fw::Logic &state 
      ) = 0;

      //! Handler base function for from_gpioSet
      //!
      void from_gpioSet_handlerBase(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          const Fw::Logic &state 
      );

    protected:

      // ----------------------------------------------------------------------
      // Histories for typed from ports
      // ----------------------------------------------------------------------

      //! Clear from port history
      //!
      void clearFromPortHistory();

      //! The total number of from port entries
      //!
      U32 fromPortHistorySize;

      //! Push an entry on the history for from_gpioSet
      void pushFromPortEntry_gpioSet(
          const Fw::Logic &state 
      );

      //! A history entry for from_gpioSet
      //!
      typedef struct {
          Fw::Logic state;
      } FromPortEntry_gpioSet;

      //! The history for from_gpioSet
      //!
      History<FromPortEntry_gpioSet>
        *fromPortHistory_gpioSet;

    protected:

      // ----------------------------------------------------------------------
      // Invocation functions for to ports
      // ----------------------------------------------------------------------

      //! Invoke the to port connected to run
      //!
      void invoke_to_run(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< 
      The call order
      */
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for port counts
      // ----------------------------------------------------------------------

      //! Get the number of to_cmdIn ports
      //!
      //! \return The number of to_cmdIn ports
      //!
      NATIVE_INT_TYPE getNum_to_cmdIn() const;

      //! Get the number of from_cmdRegOut ports
      //!
      //! \return The number of from_cmdRegOut ports
      //!
      NATIVE_INT_TYPE getNum_from_cmdRegOut() const;

      //! Get the number of from_cmdResponseOut ports
      //!
      //! \return The number of from_cmdResponseOut ports
      //!
      NATIVE_INT_TYPE getNum_from_cmdResponseOut() const;

      //! Get the number of from_gpioSet ports
      //!
      //! \return The number of from_gpioSet ports
      //!
      NATIVE_INT_TYPE getNum_from_gpioSet() const;

      //! Get the number of from_logOut ports
      //!
      //! \return The number of from_logOut ports
      //!
      NATIVE_INT_TYPE getNum_from_logOut() const;

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Get the number of from_logTextOut ports
      //!
      //! \return The number of from_logTextOut ports
      //!
      NATIVE_INT_TYPE getNum_from_logTextOut() const;
#endif

      //! Get the number of from_prmGetOut ports
      //!
      //! \return The number of from_prmGetOut ports
      //!
      NATIVE_INT_TYPE getNum_from_prmGetOut() const;

      //! Get the number of from_prmSetOut ports
      //!
      //! \return The number of from_prmSetOut ports
      //!
      NATIVE_INT_TYPE getNum_from_prmSetOut() const;

      //! Get the number of to_run ports
      //!
      //! \return The number of to_run ports
      //!
      NATIVE_INT_TYPE getNum_to_run() const;

      //! Get the number of from_timeCaller ports
      //!
      //! \return The number of from_timeCaller ports
      //!
      NATIVE_INT_TYPE getNum_from_timeCaller() const;

      //! Get the number of from_tlmOut ports
      //!
      //! \return The number of from_tlmOut ports
      //!
      NATIVE_INT_TYPE getNum_from_tlmOut() const;

    protected:

      // ----------------------------------------------------------------------
      // Connection status for to ports
      // ----------------------------------------------------------------------

      //! Check whether port is connected
      //!
      //! Whether to_cmdIn[portNum] is connected
      //!
      bool isConnected_to_cmdIn(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Check whether port is connected
      //!
      //! Whether to_run[portNum] is connected
      //!
      bool isConnected_to_run(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      // ----------------------------------------------------------------------
      // Functions for sending commands
      // ----------------------------------------------------------------------

    protected:

      // send command buffers directly - used for intentional command encoding errors
      void sendRawCmd(FwOpcodeType opcode, U32 cmdSeq, Fw::CmdArgBuffer& args);

      //! Send a BLINKING_ON_OFF command
      //!
      void sendCmd_BLINKING_ON_OFF(
          const NATIVE_INT_TYPE instance, /*!< The instance number*/
          const U32 cmdSeq, /*!< The command sequence number*/
          Fw::On on_off /*!< 
          Indicates whether the blinking should be on or off
          */
      );

    protected:

      // ----------------------------------------------------------------------
      // Command response handling
      // ----------------------------------------------------------------------

      //! Handle a command response
      //!
      virtual void cmdResponseIn(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          const Fw::CmdResponse response /*!< The command response*/
      );

      //! A type representing a command response
      //!
      typedef struct {
        FwOpcodeType opCode;
        U32 cmdSeq;
        Fw::CmdResponse response;
      } CmdResponse;

      //! The command response history
      //!
      History<CmdResponse> *cmdResponseHistory;

    protected:

      // ----------------------------------------------------------------------
      // Event dispatch
      // ----------------------------------------------------------------------

      //! Dispatch an event
      //!
      void dispatchEvents(
          const FwEventIdType id, /*!< The event ID*/
          Fw::Time& timeTag, /*!< The time*/
          const Fw::LogSeverity severity, /*!< The severity*/
          Fw::LogBuffer& args /*!< The serialized arguments*/
      );

      //! Clear event history
      //!
      void clearEvents();

      //! The total number of events seen
      //!
      U32 eventsSize;

#if FW_ENABLE_TEXT_LOGGING

    protected:

      // ----------------------------------------------------------------------
      // Text events
      // ----------------------------------------------------------------------

      //! Handle a text event
      //!
      virtual void textLogIn(
          const FwEventIdType id, /*!< The event ID*/
          Fw::Time& timeTag, /*!< The time*/
          const Fw::LogSeverity severity, /*!< The severity*/
          const Fw::TextLogString& text /*!< The event string*/
      );

      //! A history entry for the text log
      //!
      typedef struct {
        U32 id;
        Fw::Time timeTag;
        Fw::LogSeverity severity;
        Fw::TextLogString text;
      } TextLogEntry;

      //! The history of text log events
      //!
      History<TextLogEntry> *textLogHistory;

      //! Print a text log history entry
      //!
      static void printTextLogHistoryEntry(
          const TextLogEntry& e,
          FILE* file
      );

      //! Print the text log history
      //!
      void printTextLogHistory(FILE *const file);

#endif

    protected:

      // ----------------------------------------------------------------------
      // Event: InvalidBlinkArgument
      // ----------------------------------------------------------------------

      //! Handle event InvalidBlinkArgument
      //!
      virtual void logIn_WARNING_LO_InvalidBlinkArgument(
          Fw::On badArgument 
      );

      //! A history entry for event InvalidBlinkArgument
      //!
      typedef struct {
        Fw::On badArgument;
      } EventEntry_InvalidBlinkArgument;

      //! The history of InvalidBlinkArgument events
      //!
      History<EventEntry_InvalidBlinkArgument>
        *eventHistory_InvalidBlinkArgument;

    protected:

      // ----------------------------------------------------------------------
      // Event: SetBlinkingState
      // ----------------------------------------------------------------------

      //! Handle event SetBlinkingState
      //!
      virtual void logIn_ACTIVITY_HI_SetBlinkingState(
          Fw::On state 
      );

      //! A history entry for event SetBlinkingState
      //!
      typedef struct {
        Fw::On state;
      } EventEntry_SetBlinkingState;

      //! The history of SetBlinkingState events
      //!
      History<EventEntry_SetBlinkingState>
        *eventHistory_SetBlinkingState;

    protected:

      // ----------------------------------------------------------------------
      // Event: LedState
      // ----------------------------------------------------------------------

      //! Handle event LedState
      //!
      virtual void logIn_ACTIVITY_LO_LedState(
          Fw::On on_off 
      );

      //! A history entry for event LedState
      //!
      typedef struct {
        Fw::On on_off;
      } EventEntry_LedState;

      //! The history of LedState events
      //!
      History<EventEntry_LedState>
        *eventHistory_LedState;

    protected:

      // ----------------------------------------------------------------------
      // Event: BlinkIntervalSet
      // ----------------------------------------------------------------------

      //! Handle event BlinkIntervalSet
      //!
      virtual void logIn_ACTIVITY_HI_BlinkIntervalSet(
          U32 interval 
      );

      //! A history entry for event BlinkIntervalSet
      //!
      typedef struct {
        U32 interval;
      } EventEntry_BlinkIntervalSet;

      //! The history of BlinkIntervalSet events
      //!
      History<EventEntry_BlinkIntervalSet>
        *eventHistory_BlinkIntervalSet;

    protected:

      // ----------------------------------------------------------------------
      // Telemetry dispatch
      // ----------------------------------------------------------------------

      //! Dispatch telemetry
      //!
      void dispatchTlm(
          const FwChanIdType id, /*!< The channel ID*/
          const Fw::Time& timeTag, /*!< The time*/
          Fw::TlmBuffer& val /*!< The channel value*/
      );

      //! Clear telemetry history
      //!
      void clearTlm();

      //! The total number of telemetry inputs seen
      //!
      U32 tlmSize;

    protected:

      // ----------------------------------------------------------------------
      // Channel: BlinkingState
      // ----------------------------------------------------------------------

      //! Handle channel BlinkingState
      //!
      virtual void tlmInput_BlinkingState(
          const Fw::Time& timeTag, /*!< The time*/
          const Fw::On& val /*!< The channel value*/
      );

      //! A telemetry entry for channel BlinkingState
      //!
      typedef struct {
        Fw::Time timeTag;
        Fw::On arg;
      } TlmEntry_BlinkingState;

      //! The history of BlinkingState values
      //!
      History<TlmEntry_BlinkingState>
        *tlmHistory_BlinkingState;

    protected:

      // ----------------------------------------------------------------------
      // Channel: LedTransitions
      // ----------------------------------------------------------------------

      //! Handle channel LedTransitions
      //!
      virtual void tlmInput_LedTransitions(
          const Fw::Time& timeTag, /*!< The time*/
          const U64& val /*!< The channel value*/
      );

      //! A telemetry entry for channel LedTransitions
      //!
      typedef struct {
        Fw::Time timeTag;
        U64 arg;
      } TlmEntry_LedTransitions;

      //! The history of LedTransitions values
      //!
      History<TlmEntry_LedTransitions>
        *tlmHistory_LedTransitions;

    protected:

      // ----------------------------------------------------------------------
      // Test time
      // ----------------------------------------------------------------------

      //! Set the test time for events and telemetry
      //!
      void setTestTime(
          const Fw::Time& timeTag /*!< The time*/
      );

    protected:

      // ----------------------------------------------------------------------
      // Parameter: BLINK_INTERVAL
      // ----------------------------------------------------------------------

      void paramSet_BLINK_INTERVAL(
          const U32& val, /*!< The parameter value*/
          Fw::ParamValid valid /*!< The parameter valid flag*/
      );

      void paramSend_BLINK_INTERVAL(
          const NATIVE_INT_TYPE instance, /*!< The instance number*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

      void paramSave_BLINK_INTERVAL(
          const NATIVE_INT_TYPE instance, /*!< The instance number*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

    private:

      // ----------------------------------------------------------------------
      // To ports
      // ----------------------------------------------------------------------

      //! To port connected to cmdIn
      //!
      Fw::OutputCmdPort m_to_cmdIn[1];

      //! To port connected to run
      //!
      Svc::OutputSchedPort m_to_run[1];

    private:

      // ----------------------------------------------------------------------
      // From ports
      // ----------------------------------------------------------------------

      //! From port connected to cmdRegOut
      //!
      Fw::InputCmdRegPort m_from_cmdRegOut[1];

      //! From port connected to cmdResponseOut
      //!
      Fw::InputCmdResponsePort m_from_cmdResponseOut[1];

      //! From port connected to gpioSet
      //!
      Drv::InputGpioWritePort m_from_gpioSet[1];

      //! From port connected to logOut
      //!
      Fw::InputLogPort m_from_logOut[1];

#if FW_ENABLE_TEXT_LOGGING == 1
      //! From port connected to logTextOut
      //!
      Fw::InputLogTextPort m_from_logTextOut[1];
#endif

      //! From port connected to prmGetOut
      //!
      Fw::InputPrmGetPort m_from_prmGetOut[1];

      //! From port connected to prmSetOut
      //!
      Fw::InputPrmSetPort m_from_prmSetOut[1];

      //! From port connected to timeCaller
      //!
      Fw::InputTimePort m_from_timeCaller[1];

      //! From port connected to tlmOut
      //!
      Fw::InputTlmPort m_from_tlmOut[1];

    private:

      // ----------------------------------------------------------------------
      // Static functions for output ports
      // ----------------------------------------------------------------------

      //! Static function for port from_cmdRegOut
      //!
      static void from_cmdRegOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwOpcodeType opCode /*!< 
      Command Op Code
      */
      );

      //! Static function for port from_cmdResponseOut
      //!
      static void from_cmdResponseOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwOpcodeType opCode, /*!< 
      Command Op Code
      */
          U32 cmdSeq, /*!< 
      Command Sequence
      */
          const Fw::CmdResponse &response /*!< 
      The command response argument
      */
      );

      //! Static function for port from_gpioSet
      //!
      static void from_gpioSet_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          const Fw::Logic &state 
      );

      //! Static function for port from_logOut
      //!
      static void from_logOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< 
      Log ID
      */
          Fw::Time &timeTag, /*!< 
      Time Tag
      */
          const Fw::LogSeverity &severity, /*!< 
      The severity argument
      */
          Fw::LogBuffer &args /*!< 
      Buffer containing serialized log entry
      */
      );

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Static function for port from_logTextOut
      //!
      static void from_logTextOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< 
      Log ID
      */
          Fw::Time &timeTag, /*!< 
      Time Tag
      */
          const Fw::LogSeverity &severity, /*!< 
      The severity argument
      */
          Fw::TextLogString &text /*!< 
      Text of log message
      */
      );
#endif

      //! Static function for port from_prmGetOut
      //!
      static Fw::ParamValid from_prmGetOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwPrmIdType id, /*!< 
      Parameter ID
      */
          Fw::ParamBuffer &val /*!< 
      Buffer containing serialized parameter value
      */
      );

      //! Static function for port from_prmSetOut
      //!
      static void from_prmSetOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwPrmIdType id, /*!< 
      Parameter ID
      */
          Fw::ParamBuffer &val /*!< 
      Buffer containing serialized parameter value
      */
      );

      //! Static function for port from_timeCaller
      //!
      static void from_timeCaller_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Time &time /*!< 
      The U32 cmd argument
      */
      );

      //! Static function for port from_tlmOut
      //!
      static void from_tlmOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwChanIdType id, /*!< 
      Telemetry Channel ID
      */
          Fw::Time &timeTag, /*!< 
      Time Tag
      */
          Fw::TlmBuffer &val /*!< 
      Buffer containing serialized telemetry value
      */
      );

    private:

      // ----------------------------------------------------------------------
      // Test time
      // ----------------------------------------------------------------------

      //! Test time stamp
      //!
      Fw::Time m_testTime;

    private:

      // ----------------------------------------------------------------------
      // Parameter validity flags
      // ----------------------------------------------------------------------

      //! True if parameter BLINK_INTERVAL was successfully received
      //!
      Fw::ParamValid m_param_BLINK_INTERVAL_valid;

    private:

      // ----------------------------------------------------------------------
      // Parameter variables
      // ----------------------------------------------------------------------

      //! Parameter BLINK_INTERVAL
      //!
      U32 m_param_BLINK_INTERVAL;

  };

} // end namespace SystemRef

#endif
