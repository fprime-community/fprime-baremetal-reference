// ======================================================================
// \title  ActiveRateGroupComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for ActiveRateGroup component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_ACTIVERATEGROUP_COMP_HPP_
#define SVC_ACTIVERATEGROUP_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Tlm/TlmString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Svc/Cycle/TimerVal.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Svc/Cycle/TimerVal.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>
#include <Svc/Cycle/CyclePortAc.hpp>
#include <Svc/Ping/PingPortAc.hpp>
#include <Svc/Sched/SchedPortAc.hpp>

namespace Svc {

  //! \class ActiveRateGroupComponentBase
  //! \brief Auto-generated base for ActiveRateGroup component
  //!
  class ActiveRateGroupComponentBase :
    public Fw::ActiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class ActiveRateGroupComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return CycleIn[portNum]
    //!
    Svc::InputCyclePort* get_CycleIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return PingIn[portNum]
    //!
    Svc::InputPingPort* get_PingIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

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

    //! Connect port to PingOut[portNum]
    //!
    void set_PingOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::InputPingPort *port /*!< The port*/
    );

    //! Connect port to RateGroupMemberOut[portNum]
    //!
    void set_RateGroupMemberOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::InputSchedPort *port /*!< The port*/
    );

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTimePort *port /*!< The port*/
    );

    //! Connect port to Tlm[portNum]
    //!
    void set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTlmPort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

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

    //! Connect port to PingOut[portNum]
    //!
    void set_PingOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to RateGroupMemberOut[portNum]
    //!
    void set_RateGroupMemberOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Tlm[portNum]
    //!
    void set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a ActiveRateGroupComponentBase object
    //!
    ActiveRateGroupComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a ActiveRateGroupComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a ActiveRateGroupComponentBase object
    //!
    virtual ~ActiveRateGroupComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port CycleIn
    //
    virtual void CycleIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::TimerVal &cycleStart /*!< 
      Cycle start timer value
      */
    ) = 0;

    //! Handler for input port PingIn
    //
    virtual void PingIn_handler(
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

    //! Handler base-class function for input port CycleIn
    //!
    void CycleIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::TimerVal &cycleStart /*!< 
      Cycle start timer value
      */
    );

    //! Handler base-class function for input port PingIn
    //!
    void PingIn_handlerBase(
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

    //! Pre-message hook for async input port CycleIn
    //!
    virtual void CycleIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::TimerVal &cycleStart /*!< 
      Cycle start timer value
      */
    );

    //! Pre-message hook for async input port PingIn
    //!
    virtual void PingIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< 
      Value to return to pinger
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port PingOut
    //!
    void PingOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< 
      Value to return to pinger
      */
    );

    //! Invoke output port RateGroupMemberOut
    //!
    void RateGroupMemberOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of CycleIn input ports
    //!
    //! \return The number of CycleIn input ports
    //!
    NATIVE_INT_TYPE getNum_CycleIn_InputPorts();

    //! Get the number of PingIn input ports
    //!
    //! \return The number of PingIn input ports
    //!
    NATIVE_INT_TYPE getNum_PingIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_CYCLEIN_INPUT_PORTS = 1,
       NUM_PINGIN_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

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

    //! Get the number of PingOut output ports
    //!
    //! \return The number of PingOut output ports
    //!
    NATIVE_INT_TYPE getNum_PingOut_OutputPorts();

    //! Get the number of RateGroupMemberOut output ports
    //!
    //! \return The number of RateGroupMemberOut output ports
    //!
    NATIVE_INT_TYPE getNum_RateGroupMemberOut_OutputPorts();

    //! Get the number of Time output ports
    //!
    //! \return The number of Time output ports
    //!
    NATIVE_INT_TYPE getNum_Time_OutputPorts();

    //! Get the number of Tlm output ports
    //!
    //! \return The number of Tlm output ports
    //!
    NATIVE_INT_TYPE getNum_Tlm_OutputPorts();


    enum {
       NUM_LOG_OUTPUT_PORTS = 1,
       NUM_LOGTEXT_OUTPUT_PORTS = 1,
       NUM_PINGOUT_OUTPUT_PORTS = 1,
       NUM_RATEGROUPMEMBEROUT_OUTPUT_PORTS = 10,
       NUM_TIME_OUTPUT_PORTS = 1,
       NUM_TLM_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

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

    //! Check whether port PingOut is connected
    //!
    //! \return Whether port PingOut is connected
    //!
    bool isConnected_PingOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port RateGroupMemberOut is connected
    //!
    //! \return Whether port RateGroupMemberOut is connected
    //!
    bool isConnected_RateGroupMemberOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Time is connected
    //!
    //! \return Whether port Time is connected
    //!
    bool isConnected_Time_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Tlm is connected
    //!
    //! \return Whether port Tlm is connected
    //!
    bool isConnected_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_RATEGROUPSTARTED = 0x0, /* Informational event that rate group has started */
      EVENTID_RATEGROUPCYCLESLIP = 0x1, /* Warning event that rate group has had a cycle slip */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event RateGroupStarted
    //!
    /* Informational event that rate group has started */
    void log_DIAGNOSTIC_RateGroupStarted(

    );


    //! Log event RateGroupCycleSlip
    //!
    /* Warning event that rate group has had a cycle slip */
    void log_WARNING_HI_RateGroupCycleSlip(
        U32 cycle /*!< The cycle where the cycle occurred*/
    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_RGMAXTIME = 0x0, //!< Channel ID for RgMaxTime
      CHANNELID_RGCYCLESLIPS = 0x1, //!< Channel ID for RgCycleSlips
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel RgMaxTime
    //!
    /* Max execution time rate group */
    void tlmWrite_RgMaxTime(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel RgCycleSlips
    //!
    /* Cycle slips for rate group */
    void tlmWrite_RgCycleSlips(
        U32 arg /*!< The telemetry value*/,
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



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port CycleIn
    //!
    Svc::InputCyclePort m_CycleIn_InputPort[NUM_CYCLEIN_INPUT_PORTS];

    //! Input port PingIn
    //!
    Svc::InputPingPort m_PingIn_InputPort[NUM_PINGIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port Log
    //!
    Fw::OutputLogPort m_Log_OutputPort[NUM_LOG_OUTPUT_PORTS];

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Output port LogText
    //!
    Fw::OutputLogTextPort m_LogText_OutputPort[NUM_LOGTEXT_OUTPUT_PORTS];
#endif

    //! Output port PingOut
    //!
    Svc::OutputPingPort m_PingOut_OutputPort[NUM_PINGOUT_OUTPUT_PORTS];

    //! Output port RateGroupMemberOut
    //!
    Svc::OutputSchedPort m_RateGroupMemberOut_OutputPort[NUM_RATEGROUPMEMBEROUT_OUTPUT_PORTS];

    //! Output port Time
    //!
    Fw::OutputTimePort m_Time_OutputPort[NUM_TIME_OUTPUT_PORTS];

    //! Output port Tlm
    //!
    Fw::OutputTlmPort m_Tlm_OutputPort[NUM_TLM_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port CycleIn
    //!
    static void m_p_CycleIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::TimerVal &cycleStart /*!< 
      Cycle start timer value
      */
    );

    //! Callback for port PingIn
    //!
    static void m_p_PingIn_in(
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
    // First update flags for telemetry channels
    // ----------------------------------------------------------------------

    //! Initialized to true; cleared when channel RgMaxTime is first updated
    //!
    bool m_first_update_RgMaxTime;

    //! Initialized to true; cleared when channel RgCycleSlips is first updated
    //!
    bool m_first_update_RgCycleSlips;

  PRIVATE:

    // ----------------------------------------------------------------------
    // Last value storage for telemetry channels
    // ----------------------------------------------------------------------

    //! Records the last emitted value for channel RgMaxTime
    //!
    U32 m_last_RgMaxTime;

    //! Records the last emitted value for channel RgCycleSlips
    //!
    U32 m_last_RgCycleSlips;


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------

  };

} // end namespace Svc
#endif
