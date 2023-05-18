// ======================================================================
// \title  ActiveLoggerComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for ActiveLogger component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_ACTIVELOGGER_COMP_HPP_
#define SVC_ACTIVELOGGER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Cmd/CmdString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Types/InternalInterfaceString.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Svc/ActiveLogger/ActiveLogger_EnabledEnumAc.hpp>
#include <Svc/ActiveLogger/ActiveLogger_FilterSeverityEnumAc.hpp>
#include <Fw/Cmd/CmdResponseEnumAc.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Com/ComBuffer.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Fw/Com/ComBuffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Cmd/CmdPortAc.hpp>
#include <Fw/Cmd/CmdRegPortAc.hpp>
#include <Fw/Cmd/CmdResponsePortAc.hpp>
#include <Fw/Com/ComPortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Time/TimePortAc.hpp>
#include <Svc/Fatal/FatalEventPortAc.hpp>
#include <Svc/Ping/PingPortAc.hpp>

namespace Svc {

  //! \class ActiveLoggerComponentBase
  //! \brief Auto-generated base for ActiveLogger component
  //!
  class ActiveLoggerComponentBase :
    public Fw::ActiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class ActiveLoggerComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return CmdDisp[portNum]
    //!
    Fw::InputCmdPort* get_CmdDisp_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return LogRecv[portNum]
    //!
    Fw::InputLogPort* get_LogRecv_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return pingIn[portNum]
    //!
    Svc::InputPingPort* get_pingIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to CmdReg[portNum]
    //!
    void set_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputCmdRegPort *port /*!< The port*/
    );

    //! Connect port to CmdStatus[portNum]
    //!
    void set_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputCmdResponsePort *port /*!< The port*/
    );

    //! Connect port to FatalAnnounce[portNum]
    //!
    void set_FatalAnnounce_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::InputFatalEventPort *port /*!< The port*/
    );

    //! Connect port to Log[portNum]
    //!
    void set_Log_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogPort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogTextPort *port /*!< The port*/
    );
#endif

    //! Connect port to PktSend[portNum]
    //!
    void set_PktSend_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputComPort *port /*!< The port*/
    );

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTimePort *port /*!< The port*/
    );

    //! Connect port to pingOut[portNum]
    //!
    void set_pingOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::InputPingPort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to CmdReg[portNum]
    //!
    void set_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to CmdStatus[portNum]
    //!
    void set_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to FatalAnnounce[portNum]
    //!
    void set_FatalAnnounce_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Log[portNum]
    //!
    void set_Log_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );
#endif

    //! Connect port to PktSend[portNum]
    //!
    void set_PktSend_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to pingOut[portNum]
    //!
    void set_pingOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  public:

    // ----------------------------------------------------------------------
    // Command registration
    // ----------------------------------------------------------------------

    //! \brief Register commands with the Command Dispatcher
    //!
    //! Connect the dispatcher first
    //!
    void regCommands();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a ActiveLoggerComponentBase object
    //!
    ActiveLoggerComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a ActiveLoggerComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a ActiveLoggerComponentBase object
    //!
    virtual ~ActiveLoggerComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port LogRecv
    //
    virtual void LogRecv_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
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
    ) = 0;

    //! Handler for input port pingIn
    //
    virtual void pingIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< 
      Value to return to pinger
      */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port LogRecv
    //!
    void LogRecv_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
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

    //! Handler base-class function for input port pingIn
    //!
    void pingIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< 
      Value to return to pinger
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for typed async input ports.
    // ----------------------------------------------------------------------
    // Each of these functions is invoked just before processing a message
    // on the corresponding port. By default they do nothing. You can
    // override them to provide specific pre-message behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for async input port pingIn
    //!
    virtual void pingIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< 
      Value to return to pinger
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port FatalAnnounce
    //!
    void FatalAnnounce_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwEventIdType Id /*!< 
      The ID of the FATAL event
      */
    );

    //! Invoke output port PktSend
    //!
    void PktSend_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::ComBuffer &data, /*!< 
      Buffer containing packet data
      */
        U32 context /*!< 
      Call context value; meaning chosen by user
      */
    );

    //! Invoke output port pingOut
    //!
    void pingOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< 
      Value to return to pinger
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of CmdDisp input ports
    //!
    //! \return The number of CmdDisp input ports
    //!
    NATIVE_INT_TYPE getNum_CmdDisp_InputPorts();

    //! Get the number of LogRecv input ports
    //!
    //! \return The number of LogRecv input ports
    //!
    NATIVE_INT_TYPE getNum_LogRecv_InputPorts();

    //! Get the number of pingIn input ports
    //!
    //! \return The number of pingIn input ports
    //!
    NATIVE_INT_TYPE getNum_pingIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_CMDDISP_INPUT_PORTS = 1,
       NUM_LOGRECV_INPUT_PORTS = 1,
       NUM_PINGIN_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of CmdReg output ports
    //!
    //! \return The number of CmdReg output ports
    //!
    NATIVE_INT_TYPE getNum_CmdReg_OutputPorts();

    //! Get the number of CmdStatus output ports
    //!
    //! \return The number of CmdStatus output ports
    //!
    NATIVE_INT_TYPE getNum_CmdStatus_OutputPorts();

    //! Get the number of FatalAnnounce output ports
    //!
    //! \return The number of FatalAnnounce output ports
    //!
    NATIVE_INT_TYPE getNum_FatalAnnounce_OutputPorts();

    //! Get the number of Log output ports
    //!
    //! \return The number of Log output ports
    //!
    NATIVE_INT_TYPE getNum_Log_OutputPorts();

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Get the number of LogText output ports
    //!
    //! \return The number of LogText output ports
    //!
    NATIVE_INT_TYPE getNum_LogText_OutputPorts();
#endif

    //! Get the number of PktSend output ports
    //!
    //! \return The number of PktSend output ports
    //!
    NATIVE_INT_TYPE getNum_PktSend_OutputPorts();

    //! Get the number of Time output ports
    //!
    //! \return The number of Time output ports
    //!
    NATIVE_INT_TYPE getNum_Time_OutputPorts();

    //! Get the number of pingOut output ports
    //!
    //! \return The number of pingOut output ports
    //!
    NATIVE_INT_TYPE getNum_pingOut_OutputPorts();


    enum {
       NUM_CMDREG_OUTPUT_PORTS = 1,
       NUM_CMDSTATUS_OUTPUT_PORTS = 1,
       NUM_FATALANNOUNCE_OUTPUT_PORTS = 1,
       NUM_LOG_OUTPUT_PORTS = 1,
       NUM_LOGTEXT_OUTPUT_PORTS = 1,
       NUM_PKTSEND_OUTPUT_PORTS = 1,
       NUM_TIME_OUTPUT_PORTS = 1,
       NUM_PINGOUT_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port CmdReg is connected
    //!
    //! \return Whether port CmdReg is connected
    //!
    bool isConnected_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port CmdStatus is connected
    //!
    //! \return Whether port CmdStatus is connected
    //!
    bool isConnected_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port FatalAnnounce is connected
    //!
    //! \return Whether port FatalAnnounce is connected
    //!
    bool isConnected_FatalAnnounce_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Log is connected
    //!
    //! \return Whether port Log is connected
    //!
    bool isConnected_Log_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Check whether port LogText is connected
    //!
    //! \return Whether port LogText is connected
    //!
    bool isConnected_LogText_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );
#endif

    //! Check whether port PktSend is connected
    //!
    //! \return Whether port PktSend is connected
    //!
    bool isConnected_PktSend_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Time is connected
    //!
    //! \return Whether port Time is connected
    //!
    bool isConnected_Time_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port pingOut is connected
    //!
    //! \return Whether port pingOut is connected
    //!
    bool isConnected_pingOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command opcodes
    // ----------------------------------------------------------------------

    enum {
      OPCODE_SET_EVENT_FILTER = 0x0, /* Set filter for reporting events. Events are not stored in component. */
      OPCODE_SET_ID_FILTER = 0x2, /* Filter a particular ID */
      OPCODE_DUMP_FILTER_STATE = 0x3, /* Dump the filter states via events */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handlers to implement
    // ----------------------------------------------------------------------

    //! Handler for command SET_EVENT_FILTER
    /* Set filter for reporting events. Events are not stored in component. */
    virtual void SET_EVENT_FILTER_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Svc::ActiveLogger_FilterSeverity filterLevel, /*!< 
          Filter level
          */
        Svc::ActiveLogger_Enabled filterEnabled /*!< 
          Filter state
          */
    ) = 0;

    //! Handler for command SET_ID_FILTER
    /* Filter a particular ID */
    virtual void SET_ID_FILTER_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        U32 ID, 
        Svc::ActiveLogger_Enabled idFilterEnabled /*!< 
          ID filter state
          */
    ) = 0;

    //! Handler for command DUMP_FILTER_STATE
    /* Dump the filter states via events */
    virtual void DUMP_FILTER_STATE_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for async commands.
    // ----------------------------------------------------------------------
    // Each of these functions is invoked just before processing the
    // corresponding command. By default they do nothing. You can
    // override them to provide specific pre-command behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for command SET_ID_FILTER
    //!
    virtual void SET_ID_FILTER_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command DUMP_FILTER_STATE
    //!
    virtual void DUMP_FILTER_STATE_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handler base-class functions.
    // Call these functions directly to bypass the command input port.
    // ----------------------------------------------------------------------

    //! Base-class handler function for command SET_EVENT_FILTER
    //!
    void SET_EVENT_FILTER_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command SET_ID_FILTER
    //!
    void SET_ID_FILTER_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command DUMP_FILTER_STATE
    //!
    void DUMP_FILTER_STATE_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command response
    // ----------------------------------------------------------------------

    //! Emit command response
    //!
    void cmdResponse_out(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdResponse response /*!< The command response*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_SEVERITY_FILTER_STATE = 0x0, /* Dump severity filter state */
      EVENTID_ID_FILTER_ENABLED = 0x1, /* Indicate ID is filtered */
      EVENTID_ID_FILTER_LIST_FULL = 0x2, /* Attempted to add ID to full ID filter ID */
      EVENTID_ID_FILTER_REMOVED = 0x3, /* Removed an ID from the filter */
      EVENTID_ID_FILTER_NOT_FOUND = 0x4, /* ID not in filter */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event SEVERITY_FILTER_STATE
    //!
    /* Dump severity filter state */
    void log_ACTIVITY_LO_SEVERITY_FILTER_STATE(
        Svc::ActiveLogger_FilterSeverity severity, /*!< The severity level*/
        bool enabled 
    );


    //! Log event ID_FILTER_ENABLED
    //!
    /* Indicate ID is filtered */
    void log_ACTIVITY_HI_ID_FILTER_ENABLED(
        U32 ID /*!< The ID filtered*/
    );


    //! Log event ID_FILTER_LIST_FULL
    //!
    /* Attempted to add ID to full ID filter ID */
    void log_WARNING_LO_ID_FILTER_LIST_FULL(
        U32 ID /*!< The ID filtered*/
    );


    //! Log event ID_FILTER_REMOVED
    //!
    /* Removed an ID from the filter */
    void log_ACTIVITY_HI_ID_FILTER_REMOVED(
        U32 ID /*!< The ID removed*/
    );


    //! Log event ID_FILTER_NOT_FOUND
    //!
    /* ID not in filter */
    void log_WARNING_LO_ID_FILTER_NOT_FOUND(
        U32 ID /*!< The ID removed*/
    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Time
    // ----------------------------------------------------------------------

    //! Get the time
    //!
    //! \return The current time
    //!
    Fw::Time getTime();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Internal interface handlers
    // ----------------------------------------------------------------------

    //! Internal Interface handler for loqQueue
    //!
    virtual void loqQueue_internalInterfaceHandler(
        FwEventIdType id, /*!< 
          Log ID
          */
        const Fw::Time& timeTag, /*!< 
          Time Tag
          */
        const Fw::LogSeverity& severity, /*!< 
          The severity argument
          */
        const Fw::LogBuffer& args /*!< 
          Buffer containing serialized log entry
          */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Internal interface base-class functions
    // ----------------------------------------------------------------------

    //! Base class function for loqQueue
    //!
    void loqQueue_internalInterfaceInvoke(
        FwEventIdType id, /*!< 
          Log ID
          */
        const Fw::Time& timeTag, /*!< 
          Time Tag
          */
        const Fw::LogSeverity& severity, /*!< 
          The severity argument
          */
        const Fw::LogBuffer& args /*!< 
          Buffer containing serialized log entry
          */
    );



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port CmdDisp
    //!
    Fw::InputCmdPort m_CmdDisp_InputPort[NUM_CMDDISP_INPUT_PORTS];

    //! Input port LogRecv
    //!
    Fw::InputLogPort m_LogRecv_InputPort[NUM_LOGRECV_INPUT_PORTS];

    //! Input port pingIn
    //!
    Svc::InputPingPort m_pingIn_InputPort[NUM_PINGIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port CmdReg
    //!
    Fw::OutputCmdRegPort m_CmdReg_OutputPort[NUM_CMDREG_OUTPUT_PORTS];

    //! Output port CmdStatus
    //!
    Fw::OutputCmdResponsePort m_CmdStatus_OutputPort[NUM_CMDSTATUS_OUTPUT_PORTS];

    //! Output port FatalAnnounce
    //!
    Svc::OutputFatalEventPort m_FatalAnnounce_OutputPort[NUM_FATALANNOUNCE_OUTPUT_PORTS];

    //! Output port Log
    //!
    Fw::OutputLogPort m_Log_OutputPort[NUM_LOG_OUTPUT_PORTS];

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Output port LogText
    //!
    Fw::OutputLogTextPort m_LogText_OutputPort[NUM_LOGTEXT_OUTPUT_PORTS];
#endif

    //! Output port PktSend
    //!
    Fw::OutputComPort m_PktSend_OutputPort[NUM_PKTSEND_OUTPUT_PORTS];

    //! Output port Time
    //!
    Fw::OutputTimePort m_Time_OutputPort[NUM_TIME_OUTPUT_PORTS];

    //! Output port pingOut
    //!
    Svc::OutputPingPort m_pingOut_OutputPort[NUM_PINGOUT_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port CmdDisp
    //!
    static void m_p_CmdDisp_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwOpcodeType opCode, /*!< 
      Command Op Code
      */
        U32 cmdSeq, /*!< 
      Command Sequence
      */
        Fw::CmdArgBuffer &args /*!< 
      Buffer containing arguments
      */
    );

    //! Callback for port LogRecv
    //!
    static void m_p_LogRecv_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
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

    //! Callback for port pingIn
    //!
    static void m_p_pingIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< 
      Value to return to pinger
      */
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Message dispatch functions
    // ----------------------------------------------------------------------

    //! Called in the message loop to dispatch a message from the queue
    //!
    virtual MsgDispatchStatus doDispatch();


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------

  };

} // end namespace Svc
#endif
