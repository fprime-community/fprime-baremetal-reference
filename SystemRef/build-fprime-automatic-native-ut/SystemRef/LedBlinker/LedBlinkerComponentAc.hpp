// ======================================================================
// \title  LedBlinkerComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for LedBlinker component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SYSTEMREF_LEDBLINKER_COMP_HPP_
#define SYSTEMREF_LEDBLINKER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Os/Mutex.hpp>
#include <Fw/Cmd/CmdString.hpp>
#include <Fw/Tlm/TlmString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Prm/PrmString.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Types/OnEnumAc.hpp>
#include <Fw/Types/LogicEnumAc.hpp>
#include <Fw/Cmd/CmdResponseEnumAc.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Fw/Prm/ParamValidEnumAc.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Prm/ParamBuffer.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Prm/ParamBuffer.hpp>
#include <Fw/Prm/ParamBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Drv/GpioDriverPorts/GpioWritePortAc.hpp>
#include <Fw/Cmd/CmdPortAc.hpp>
#include <Fw/Cmd/CmdRegPortAc.hpp>
#include <Fw/Cmd/CmdResponsePortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Prm/PrmGetPortAc.hpp>
#include <Fw/Prm/PrmSetPortAc.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>
#include <Svc/Sched/SchedPortAc.hpp>

namespace SystemRef {

  //! \class LedBlinkerComponentBase
  //! \brief Auto-generated base for LedBlinker component
  //!
  class LedBlinkerComponentBase :
    public Fw::ActiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class LedBlinkerComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return cmdIn[portNum]
    //!
    Fw::InputCmdPort* get_cmdIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return run[portNum]
    //!
    Svc::InputSchedPort* get_run_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to cmdRegOut[portNum]
    //!
    void set_cmdRegOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputCmdRegPort *port /*!< The port*/
    );

    //! Connect port to cmdResponseOut[portNum]
    //!
    void set_cmdResponseOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputCmdResponsePort *port /*!< The port*/
    );

    //! Connect port to gpioSet[portNum]
    //!
    void set_gpioSet_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::InputGpioWritePort *port /*!< The port*/
    );

    //! Connect port to logOut[portNum]
    //!
    void set_logOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogPort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to logTextOut[portNum]
    //!
    void set_logTextOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogTextPort *port /*!< The port*/
    );
#endif

    //! Connect port to prmGetOut[portNum]
    //!
    void set_prmGetOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputPrmGetPort *port /*!< The port*/
    );

    //! Connect port to prmSetOut[portNum]
    //!
    void set_prmSetOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputPrmSetPort *port /*!< The port*/
    );

    //! Connect port to timeCaller[portNum]
    //!
    void set_timeCaller_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTimePort *port /*!< The port*/
    );

    //! Connect port to tlmOut[portNum]
    //!
    void set_tlmOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTlmPort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to cmdRegOut[portNum]
    //!
    void set_cmdRegOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to cmdResponseOut[portNum]
    //!
    void set_cmdResponseOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to gpioSet[portNum]
    //!
    void set_gpioSet_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to logOut[portNum]
    //!
    void set_logOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to logTextOut[portNum]
    //!
    void set_logTextOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );
#endif

    //! Connect port to prmGetOut[portNum]
    //!
    void set_prmGetOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to prmSetOut[portNum]
    //!
    void set_prmSetOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to timeCaller[portNum]
    //!
    void set_timeCaller_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to tlmOut[portNum]
    //!
    void set_tlmOut_OutputPort(
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

  public:

    // ----------------------------------------------------------------------
    // Parameter loading
    // ----------------------------------------------------------------------

    //! \brief Load the parameters from a parameter source
    //!
    //! Connect the parameter first
    //!
    void loadParameters();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a LedBlinkerComponentBase object
    //!
    LedBlinkerComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a LedBlinkerComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a LedBlinkerComponentBase object
    //!
    virtual ~LedBlinkerComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port run
    //
    virtual void run_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port run
    //!
    void run_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port gpioSet
    //!
    void gpioSet_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        const Fw::Logic &state 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of cmdIn input ports
    //!
    //! \return The number of cmdIn input ports
    //!
    NATIVE_INT_TYPE getNum_cmdIn_InputPorts();

    //! Get the number of run input ports
    //!
    //! \return The number of run input ports
    //!
    NATIVE_INT_TYPE getNum_run_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_CMDIN_INPUT_PORTS = 1,
       NUM_RUN_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of cmdRegOut output ports
    //!
    //! \return The number of cmdRegOut output ports
    //!
    NATIVE_INT_TYPE getNum_cmdRegOut_OutputPorts();

    //! Get the number of cmdResponseOut output ports
    //!
    //! \return The number of cmdResponseOut output ports
    //!
    NATIVE_INT_TYPE getNum_cmdResponseOut_OutputPorts();

    //! Get the number of gpioSet output ports
    //!
    //! \return The number of gpioSet output ports
    //!
    NATIVE_INT_TYPE getNum_gpioSet_OutputPorts();

    //! Get the number of logOut output ports
    //!
    //! \return The number of logOut output ports
    //!
    NATIVE_INT_TYPE getNum_logOut_OutputPorts();

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Get the number of logTextOut output ports
    //!
    //! \return The number of logTextOut output ports
    //!
    NATIVE_INT_TYPE getNum_logTextOut_OutputPorts();
#endif

    //! Get the number of prmGetOut output ports
    //!
    //! \return The number of prmGetOut output ports
    //!
    NATIVE_INT_TYPE getNum_prmGetOut_OutputPorts();

    //! Get the number of prmSetOut output ports
    //!
    //! \return The number of prmSetOut output ports
    //!
    NATIVE_INT_TYPE getNum_prmSetOut_OutputPorts();

    //! Get the number of timeCaller output ports
    //!
    //! \return The number of timeCaller output ports
    //!
    NATIVE_INT_TYPE getNum_timeCaller_OutputPorts();

    //! Get the number of tlmOut output ports
    //!
    //! \return The number of tlmOut output ports
    //!
    NATIVE_INT_TYPE getNum_tlmOut_OutputPorts();


    enum {
       NUM_CMDREGOUT_OUTPUT_PORTS = 1,
       NUM_CMDRESPONSEOUT_OUTPUT_PORTS = 1,
       NUM_GPIOSET_OUTPUT_PORTS = 1,
       NUM_LOGOUT_OUTPUT_PORTS = 1,
       NUM_LOGTEXTOUT_OUTPUT_PORTS = 1,
       NUM_PRMGETOUT_OUTPUT_PORTS = 1,
       NUM_PRMSETOUT_OUTPUT_PORTS = 1,
       NUM_TIMECALLER_OUTPUT_PORTS = 1,
       NUM_TLMOUT_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port cmdRegOut is connected
    //!
    //! \return Whether port cmdRegOut is connected
    //!
    bool isConnected_cmdRegOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port cmdResponseOut is connected
    //!
    //! \return Whether port cmdResponseOut is connected
    //!
    bool isConnected_cmdResponseOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port gpioSet is connected
    //!
    //! \return Whether port gpioSet is connected
    //!
    bool isConnected_gpioSet_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port logOut is connected
    //!
    //! \return Whether port logOut is connected
    //!
    bool isConnected_logOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Check whether port logTextOut is connected
    //!
    //! \return Whether port logTextOut is connected
    //!
    bool isConnected_logTextOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );
#endif

    //! Check whether port prmGetOut is connected
    //!
    //! \return Whether port prmGetOut is connected
    //!
    bool isConnected_prmGetOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port prmSetOut is connected
    //!
    //! \return Whether port prmSetOut is connected
    //!
    bool isConnected_prmSetOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port timeCaller is connected
    //!
    //! \return Whether port timeCaller is connected
    //!
    bool isConnected_timeCaller_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port tlmOut is connected
    //!
    //! \return Whether port tlmOut is connected
    //!
    bool isConnected_tlmOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command opcodes
    // ----------------------------------------------------------------------

    enum {
      OPCODE_BLINKING_ON_OFF = 0x0, /* Command to turn on or off the blinking LED */
      OPCODE_BLINK_INTERVAL_SET = 0x1, //!< opcode to set parameter BLINK_INTERVAL
      OPCODE_BLINK_INTERVAL_SAVE = 0x2, //!< opcode to save parameter BLINK_INTERVAL
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handlers to implement
    // ----------------------------------------------------------------------

    //! Handler for command BLINKING_ON_OFF
    /* Command to turn on or off the blinking LED */
    virtual void BLINKING_ON_OFF_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::On on_off /*!< 
          Indicates whether the blinking should be on or off
          */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for async commands.
    // ----------------------------------------------------------------------
    // Each of these functions is invoked just before processing the
    // corresponding command. By default they do nothing. You can
    // override them to provide specific pre-command behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for command BLINKING_ON_OFF
    //!
    virtual void BLINKING_ON_OFF_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handler base-class functions.
    // Call these functions directly to bypass the command input port.
    // ----------------------------------------------------------------------

    //! Base-class handler function for command BLINKING_ON_OFF
    //!
    void BLINKING_ON_OFF_cmdHandlerBase(
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
      EVENTID_INVALIDBLINKARGUMENT = 0x0, /* Indicates we received an invalid argument. */
      EVENTID_SETBLINKINGSTATE = 0x1, /* Reports the state we set to blinking. */
      EVENTID_LEDSTATE = 0x2, /* Event logged when the LED turns on or off */
      EVENTID_BLINKINTERVALSET = 0x3, /* Event logged when the LED blink interval is updated */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event InvalidBlinkArgument
    //!
    /* Indicates we received an invalid argument. */
    void log_WARNING_LO_InvalidBlinkArgument(
        Fw::On badArgument 
    );


    //! Log event SetBlinkingState
    //!
    /* Reports the state we set to blinking. */
    void log_ACTIVITY_HI_SetBlinkingState(
        Fw::On state 
    );


    //! Log event LedState
    //!
    /* Event logged when the LED turns on or off */
    void log_ACTIVITY_LO_LedState(
        Fw::On on_off 
    );


    //! Log event BlinkIntervalSet
    //!
    /* Event logged when the LED blink interval is updated */
    void log_ACTIVITY_HI_BlinkIntervalSet(
        U32 interval 
    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_BLINKINGSTATE = 0x0, //!< Channel ID for BlinkingState
      CHANNELID_LEDTRANSITIONS = 0x1, //!< Channel ID for LedTransitions
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel BlinkingState
    //!
    /* Telemetry channel to report blinking state. */
    void tlmWrite_BlinkingState(
        const Fw::On& arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel LedTransitions
    //!
    /* Telemetry channel counting LED transitions */
    void tlmWrite_LedTransitions(
        U64 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
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
    // Parameter IDs
    // ----------------------------------------------------------------------

    enum {
      PARAMID_BLINK_INTERVAL = 0x0,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Parameter update hook
    // ----------------------------------------------------------------------

    //! \brief Called whenever a parameter is updated
    //!
    //! This function does nothing by default. You may override it.
    //!
    virtual void parameterUpdated(
        FwPrmIdType id /*!< The parameter ID*/
    );

    // ----------------------------------------------------------------------
    // Parameter load hook
    // ----------------------------------------------------------------------

    //! \brief Called whenever parameters are loaded
    //!
    //! This function does nothing by default. You may override it.
    //!
    virtual void parametersLoaded();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Parameter get functions
    // ----------------------------------------------------------------------

    //! Get parameter BLINK_INTERVAL
    //!
    /* Blinking interval in rate group ticks */
    //! \return The parameter value
    //!
    U32 paramGet_BLINK_INTERVAL(
        Fw::ParamValid& valid /*!< Whether the parameter is valid*/
    );



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port cmdIn
    //!
    Fw::InputCmdPort m_cmdIn_InputPort[NUM_CMDIN_INPUT_PORTS];

    //! Input port run
    //!
    Svc::InputSchedPort m_run_InputPort[NUM_RUN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port cmdRegOut
    //!
    Fw::OutputCmdRegPort m_cmdRegOut_OutputPort[NUM_CMDREGOUT_OUTPUT_PORTS];

    //! Output port cmdResponseOut
    //!
    Fw::OutputCmdResponsePort m_cmdResponseOut_OutputPort[NUM_CMDRESPONSEOUT_OUTPUT_PORTS];

    //! Output port gpioSet
    //!
    Drv::OutputGpioWritePort m_gpioSet_OutputPort[NUM_GPIOSET_OUTPUT_PORTS];

    //! Output port logOut
    //!
    Fw::OutputLogPort m_logOut_OutputPort[NUM_LOGOUT_OUTPUT_PORTS];

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Output port logTextOut
    //!
    Fw::OutputLogTextPort m_logTextOut_OutputPort[NUM_LOGTEXTOUT_OUTPUT_PORTS];
#endif

    //! Output port prmGetOut
    //!
    Fw::OutputPrmGetPort m_prmGetOut_OutputPort[NUM_PRMGETOUT_OUTPUT_PORTS];

    //! Output port prmSetOut
    //!
    Fw::OutputPrmSetPort m_prmSetOut_OutputPort[NUM_PRMSETOUT_OUTPUT_PORTS];

    //! Output port timeCaller
    //!
    Fw::OutputTimePort m_timeCaller_OutputPort[NUM_TIMECALLER_OUTPUT_PORTS];

    //! Output port tlmOut
    //!
    Fw::OutputTlmPort m_tlmOut_OutputPort[NUM_TLMOUT_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port cmdIn
    //!
    static void m_p_cmdIn_in(
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

    //! Callback for port run
    //!
    static void m_p_run_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
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
    // Mutexes
    // ----------------------------------------------------------------------

    //! Mutex for locking parameters during sets and saves
    //!
    Os::Mutex m_paramLock;

  PRIVATE:

    // ----------------------------------------------------------------------
    // Parameter validity flags
    // ----------------------------------------------------------------------

    //! True if parameter BLINK_INTERVAL was successfully received
    //!
    Fw::ParamValid m_param_BLINK_INTERVAL_valid;

  PRIVATE:

    // ----------------------------------------------------------------------
    // Parameter variables
    // ----------------------------------------------------------------------

    //! Parameter BLINK_INTERVAL
    //!
    /*! Blinking interval in rate group ticks*/
    U32 m_BLINK_INTERVAL;

  PRIVATE:

    // ----------------------------------------------------------------------
    // Private parameter get function
    // ----------------------------------------------------------------------

    //! Get a parameter by ID
    //!
    //! \return Whether the parameter is valid
    //!
    Fw::ParamValid getParam(
        FwPrmIdType id, /*!< The ID*/
        Fw::ParamBuffer& buff /*!< The parameter value*/
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Parameter set functions
    // ----------------------------------------------------------------------

    //! Set parameter BLINK_INTERVAL
    //!
    //! \return The command response
    //!
    Fw::CmdResponse paramSet_BLINK_INTERVAL(
        Fw::SerializeBufferBase &val /*!< The serialization buffer*/
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Parameter save functions
    // ----------------------------------------------------------------------

    //! Save parameter BLINK_INTERVAL
    //!
    //! \return The command response
    //!
    Fw::CmdResponse paramSave_BLINK_INTERVAL();


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------

  };

} // end namespace SystemRef
#endif
