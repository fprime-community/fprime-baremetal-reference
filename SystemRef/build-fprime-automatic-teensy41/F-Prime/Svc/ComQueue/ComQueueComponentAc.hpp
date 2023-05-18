// ======================================================================
// \title  ComQueueComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for ComQueue component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_COMQUEUE_COMP_HPP_
#define SVC_COMQUEUE_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Tlm/TlmString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Svc/ComQueue/QueueTypeEnumAc.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Fw/Types/SuccessEnumAc.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Com/ComBuffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Com/ComBuffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Buffer/BufferSendPortAc.hpp>
#include <Fw/Com/ComPortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Ports/SuccessCondition/SuccessConditionPortAc.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>
#include <Svc/Sched/SchedPortAc.hpp>
#include <Svc/ComQueue/BuffQueueDepthArrayAc.hpp>
#include <Svc/ComQueue/ComQueueDepthArrayAc.hpp>

namespace Svc {

  //! \class ComQueueComponentBase
  //! \brief Auto-generated base for ComQueue component
  //!
  class ComQueueComponentBase :
    public Fw::ActiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class ComQueueComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return buffQueueIn[portNum]
    //!
    Fw::InputBufferSendPort* get_buffQueueIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return comQueueIn[portNum]
    //!
    Fw::InputComPort* get_comQueueIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return comStatusIn[portNum]
    //!
    Fw::InputSuccessConditionPort* get_comStatusIn_InputPort(
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

    //! Connect port to buffQueueSend[portNum]
    //!
    void set_buffQueueSend_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to comQueueSend[portNum]
    //!
    void set_comQueueSend_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputComPort *port /*!< The port*/
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

    //! Connect port to buffQueueSend[portNum]
    //!
    void set_buffQueueSend_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to comQueueSend[portNum]
    //!
    void set_comQueueSend_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a ComQueueComponentBase object
    //!
    ComQueueComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a ComQueueComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a ComQueueComponentBase object
    //!
    virtual ~ComQueueComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port buffQueueIn
    //
    virtual void buffQueueIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    ) = 0;

    //! Handler for input port comQueueIn
    //
    virtual void comQueueIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::ComBuffer &data, /*!< 
      Buffer containing packet data
      */
        U32 context /*!< 
      Call context value; meaning chosen by user
      */
    ) = 0;

    //! Handler for input port comStatusIn
    //
    virtual void comStatusIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Success &condition /*!< 
      Condition success/failure
      */
    ) = 0;

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

    //! Handler base-class function for input port buffQueueIn
    //!
    void buffQueueIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Handler base-class function for input port comQueueIn
    //!
    void comQueueIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::ComBuffer &data, /*!< 
      Buffer containing packet data
      */
        U32 context /*!< 
      Call context value; meaning chosen by user
      */
    );

    //! Handler base-class function for input port comStatusIn
    //!
    void comStatusIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Success &condition /*!< 
      Condition success/failure
      */
    );

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
    // Pre-message hooks for typed async input ports.
    // ----------------------------------------------------------------------
    // Each of these functions is invoked just before processing a message
    // on the corresponding port. By default they do nothing. You can
    // override them to provide specific pre-message behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for async input port buffQueueIn
    //!
    virtual void buffQueueIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Pre-message hook for async input port comQueueIn
    //!
    virtual void comQueueIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::ComBuffer &data, /*!< 
      Buffer containing packet data
      */
        U32 context /*!< 
      Call context value; meaning chosen by user
      */
    );

    //! Pre-message hook for async input port comStatusIn
    //!
    virtual void comStatusIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Success &condition /*!< 
      Condition success/failure
      */
    );

    //! Pre-message hook for async input port run
    //!
    virtual void run_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port buffQueueSend
    //!
    void buffQueueSend_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Invoke output port comQueueSend
    //!
    void comQueueSend_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::ComBuffer &data, /*!< 
      Buffer containing packet data
      */
        U32 context /*!< 
      Call context value; meaning chosen by user
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of buffQueueIn input ports
    //!
    //! \return The number of buffQueueIn input ports
    //!
    NATIVE_INT_TYPE getNum_buffQueueIn_InputPorts();

    //! Get the number of comQueueIn input ports
    //!
    //! \return The number of comQueueIn input ports
    //!
    NATIVE_INT_TYPE getNum_comQueueIn_InputPorts();

    //! Get the number of comStatusIn input ports
    //!
    //! \return The number of comStatusIn input ports
    //!
    NATIVE_INT_TYPE getNum_comStatusIn_InputPorts();

    //! Get the number of run input ports
    //!
    //! \return The number of run input ports
    //!
    NATIVE_INT_TYPE getNum_run_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_BUFFQUEUEIN_INPUT_PORTS = 1,
       NUM_COMQUEUEIN_INPUT_PORTS = 2,
       NUM_COMSTATUSIN_INPUT_PORTS = 1,
       NUM_RUN_INPUT_PORTS = 1,
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

    //! Get the number of buffQueueSend output ports
    //!
    //! \return The number of buffQueueSend output ports
    //!
    NATIVE_INT_TYPE getNum_buffQueueSend_OutputPorts();

    //! Get the number of comQueueSend output ports
    //!
    //! \return The number of comQueueSend output ports
    //!
    NATIVE_INT_TYPE getNum_comQueueSend_OutputPorts();


    enum {
       NUM_LOG_OUTPUT_PORTS = 1,
       NUM_LOGTEXT_OUTPUT_PORTS = 1,
       NUM_TIME_OUTPUT_PORTS = 1,
       NUM_TLM_OUTPUT_PORTS = 1,
       NUM_BUFFQUEUESEND_OUTPUT_PORTS = 1,
       NUM_COMQUEUESEND_OUTPUT_PORTS = 1,
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

    //! Check whether port buffQueueSend is connected
    //!
    //! \return Whether port buffQueueSend is connected
    //!
    bool isConnected_buffQueueSend_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port comQueueSend is connected
    //!
    //! \return Whether port comQueueSend is connected
    //!
    bool isConnected_comQueueSend_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_QUEUEOVERFLOW = 0x0, /* Queue overflow event */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event QueueOverflow
    //!
    /* Queue overflow event */
    void log_WARNING_HI_QueueOverflow(
        Svc::QueueType queueType, /*!< The Queue data type*/
        U32 index /*!< index of overflowed queue*/
    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_COMQUEUEDEPTH = 0x0, //!< Channel ID for comQueueDepth
      CHANNELID_BUFFQUEUEDEPTH = 0x1, //!< Channel ID for buffQueueDepth
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel comQueueDepth
    //!
    /* Depth of queues of Fw::ComBuffer type */
    void tlmWrite_comQueueDepth(
        const Svc::ComQueueDepth& arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel buffQueueDepth
    //!
    /* Depth of queues of Fw::Buffer type */
    void tlmWrite_buffQueueDepth(
        const Svc::BuffQueueDepth& arg /*!< The telemetry value*/,
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

    //! Input port buffQueueIn
    //!
    Fw::InputBufferSendPort m_buffQueueIn_InputPort[NUM_BUFFQUEUEIN_INPUT_PORTS];

    //! Input port comQueueIn
    //!
    Fw::InputComPort m_comQueueIn_InputPort[NUM_COMQUEUEIN_INPUT_PORTS];

    //! Input port comStatusIn
    //!
    Fw::InputSuccessConditionPort m_comStatusIn_InputPort[NUM_COMSTATUSIN_INPUT_PORTS];

    //! Input port run
    //!
    Svc::InputSchedPort m_run_InputPort[NUM_RUN_INPUT_PORTS];

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

    //! Output port Time
    //!
    Fw::OutputTimePort m_Time_OutputPort[NUM_TIME_OUTPUT_PORTS];

    //! Output port Tlm
    //!
    Fw::OutputTlmPort m_Tlm_OutputPort[NUM_TLM_OUTPUT_PORTS];

    //! Output port buffQueueSend
    //!
    Fw::OutputBufferSendPort m_buffQueueSend_OutputPort[NUM_BUFFQUEUESEND_OUTPUT_PORTS];

    //! Output port comQueueSend
    //!
    Fw::OutputComPort m_comQueueSend_OutputPort[NUM_COMQUEUESEND_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port buffQueueIn
    //!
    static void m_p_buffQueueIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Callback for port comQueueIn
    //!
    static void m_p_comQueueIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::ComBuffer &data, /*!< 
      Buffer containing packet data
      */
        U32 context /*!< 
      Call context value; meaning chosen by user
      */
    );

    //! Callback for port comStatusIn
    //!
    static void m_p_comStatusIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Success &condition /*!< 
      Condition success/failure
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
    // Counter values for event throttling
    // ----------------------------------------------------------------------

  };

} // end namespace Svc
#endif
