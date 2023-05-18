// ======================================================================
// \title  BufferManagerComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for BufferManager component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_BUFFERMANAGER_COMP_HPP_
#define SVC_BUFFERMANAGER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Os/Mutex.hpp>
#include <Fw/Tlm/TlmString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Buffer/BufferGetPortAc.hpp>
#include <Fw/Buffer/BufferSendPortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>
#include <Svc/Sched/SchedPortAc.hpp>

namespace Svc {

  //! \class BufferManagerComponentBase
  //! \brief Auto-generated base for BufferManager component
  //!
  class BufferManagerComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class BufferManagerComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return bufferGetCallee[portNum]
    //!
    Fw::InputBufferGetPort* get_bufferGetCallee_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return bufferSendIn[portNum]
    //!
    Fw::InputBufferSendPort* get_bufferSendIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return schedIn[portNum]
    //!
    Svc::InputSchedPort* get_schedIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to eventOut[portNum]
    //!
    void set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogPort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to textEventOut[portNum]
    //!
    void set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogTextPort *port /*!< The port*/
    );
#endif

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

    //! Connect port to eventOut[portNum]
    //!
    void set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to textEventOut[portNum]
    //!
    void set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );
#endif

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

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a BufferManagerComponentBase object
    //!
    BufferManagerComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a BufferManagerComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a BufferManagerComponentBase object
    //!
    virtual ~BufferManagerComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    //! Mutex operations for guarded ports.
    // ----------------------------------------------------------------------
    //! You can override these operations to provide more sophisticated
    //! synchronization.
    // ----------------------------------------------------------------------

    //! Lock the guarded mutex
    //!
    virtual void lock();

    //! Unlock the guarded mutex
    //!
    virtual void unLock();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port bufferGetCallee
    //
    virtual Fw::Buffer bufferGetCallee_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 size 
    ) = 0;

    //! Handler for input port bufferSendIn
    //
    virtual void bufferSendIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    ) = 0;

    //! Handler for input port schedIn
    //
    virtual void schedIn_handler(
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

    //! Handler base-class function for input port bufferGetCallee
    //!
    Fw::Buffer bufferGetCallee_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 size 
    );

    //! Handler base-class function for input port bufferSendIn
    //!
    void bufferSendIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Handler base-class function for input port schedIn
    //!
    void schedIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of bufferGetCallee input ports
    //!
    //! \return The number of bufferGetCallee input ports
    //!
    NATIVE_INT_TYPE getNum_bufferGetCallee_InputPorts();

    //! Get the number of bufferSendIn input ports
    //!
    //! \return The number of bufferSendIn input ports
    //!
    NATIVE_INT_TYPE getNum_bufferSendIn_InputPorts();

    //! Get the number of schedIn input ports
    //!
    //! \return The number of schedIn input ports
    //!
    NATIVE_INT_TYPE getNum_schedIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_BUFFERGETCALLEE_INPUT_PORTS = 1,
       NUM_BUFFERSENDIN_INPUT_PORTS = 1,
       NUM_SCHEDIN_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of eventOut output ports
    //!
    //! \return The number of eventOut output ports
    //!
    NATIVE_INT_TYPE getNum_eventOut_OutputPorts();

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Get the number of textEventOut output ports
    //!
    //! \return The number of textEventOut output ports
    //!
    NATIVE_INT_TYPE getNum_textEventOut_OutputPorts();
#endif

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
       NUM_EVENTOUT_OUTPUT_PORTS = 1,
       NUM_TEXTEVENTOUT_OUTPUT_PORTS = 1,
       NUM_TIMECALLER_OUTPUT_PORTS = 1,
       NUM_TLMOUT_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port eventOut is connected
    //!
    //! \return Whether port eventOut is connected
    //!
    bool isConnected_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Check whether port textEventOut is connected
    //!
    //! \return Whether port textEventOut is connected
    //!
    bool isConnected_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );
#endif

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
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_NOBUFFSAVAILABLE = 0x0, /* The BufferManager was unable to allocate a requested buffer */
      EVENTID_ZEROSIZEBUFFER = 0x1, /* The buffer manager received a zero-sized buffer as a return. Probably undetected empty buffer allocation */
    };

    // ----------------------------------------------------------------------
    // Event Throttle values - sets initial value of countdown variable
    // ----------------------------------------------------------------------

    enum {
      EVENTID_NOBUFFSAVAILABLE_THROTTLE = 10, /*!< Throttle reset count for NoBuffsAvailable*/
      EVENTID_ZEROSIZEBUFFER_THROTTLE = 10, /*!< Throttle reset count for ZeroSizeBuffer*/
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event NoBuffsAvailable
    //!
    /* The BufferManager was unable to allocate a requested buffer */
    void log_WARNING_HI_NoBuffsAvailable(
        U32 size /*!< The requested size*/
    );

    // reset throttle value for NoBuffsAvailable
    void log_WARNING_HI_NoBuffsAvailable_ThrottleClear();

    //! Log event ZeroSizeBuffer
    //!
    /* The buffer manager received a zero-sized buffer as a return. Probably undetected empty buffer allocation */
    void log_WARNING_HI_ZeroSizeBuffer(

    );

    // reset throttle value for ZeroSizeBuffer
    void log_WARNING_HI_ZeroSizeBuffer_ThrottleClear();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_TOTALBUFFS = 0x0, //!< Channel ID for TotalBuffs
      CHANNELID_CURRBUFFS = 0x1, //!< Channel ID for CurrBuffs
      CHANNELID_HIBUFFS = 0x2, //!< Channel ID for HiBuffs
      CHANNELID_NOBUFFS = 0x3, //!< Channel ID for NoBuffs
      CHANNELID_EMPTYBUFFS = 0x4, //!< Channel ID for EmptyBuffs
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel TotalBuffs
    //!
    /* The total buffers allocated */
    void tlmWrite_TotalBuffs(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CurrBuffs
    //!
    /* The current number of allocated buffers */
    void tlmWrite_CurrBuffs(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel HiBuffs
    //!
    /* The high water mark of allocated buffers */
    void tlmWrite_HiBuffs(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel NoBuffs
    //!
    /* The number of requests that couldn't return a buffer */
    void tlmWrite_NoBuffs(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel EmptyBuffs
    //!
    /* The number of empty buffers returned */
    void tlmWrite_EmptyBuffs(
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

    //! Input port bufferGetCallee
    //!
    Fw::InputBufferGetPort m_bufferGetCallee_InputPort[NUM_BUFFERGETCALLEE_INPUT_PORTS];

    //! Input port bufferSendIn
    //!
    Fw::InputBufferSendPort m_bufferSendIn_InputPort[NUM_BUFFERSENDIN_INPUT_PORTS];

    //! Input port schedIn
    //!
    Svc::InputSchedPort m_schedIn_InputPort[NUM_SCHEDIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port eventOut
    //!
    Fw::OutputLogPort m_eventOut_OutputPort[NUM_EVENTOUT_OUTPUT_PORTS];

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Output port textEventOut
    //!
    Fw::OutputLogTextPort m_textEventOut_OutputPort[NUM_TEXTEVENTOUT_OUTPUT_PORTS];
#endif

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

    //! Callback for port bufferGetCallee
    //!
    static Fw::Buffer m_p_bufferGetCallee_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 size 
    );

    //! Callback for port bufferSendIn
    //!
    static void m_p_bufferSendIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Callback for port schedIn
    //!
    static void m_p_schedIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Mutexes
    // ----------------------------------------------------------------------

    //! Mutex for guarded ports
    //!
    Os::Mutex m_guardedPortMutex;

  PRIVATE:

    // ----------------------------------------------------------------------
    // First update flags for telemetry channels
    // ----------------------------------------------------------------------

    //! Initialized to true; cleared when channel TotalBuffs is first updated
    //!
    bool m_first_update_TotalBuffs;

    //! Initialized to true; cleared when channel CurrBuffs is first updated
    //!
    bool m_first_update_CurrBuffs;

    //! Initialized to true; cleared when channel HiBuffs is first updated
    //!
    bool m_first_update_HiBuffs;

    //! Initialized to true; cleared when channel NoBuffs is first updated
    //!
    bool m_first_update_NoBuffs;

    //! Initialized to true; cleared when channel EmptyBuffs is first updated
    //!
    bool m_first_update_EmptyBuffs;

  PRIVATE:

    // ----------------------------------------------------------------------
    // Last value storage for telemetry channels
    // ----------------------------------------------------------------------

    //! Records the last emitted value for channel TotalBuffs
    //!
    U32 m_last_TotalBuffs;

    //! Records the last emitted value for channel CurrBuffs
    //!
    U32 m_last_CurrBuffs;

    //! Records the last emitted value for channel HiBuffs
    //!
    U32 m_last_HiBuffs;

    //! Records the last emitted value for channel NoBuffs
    //!
    U32 m_last_NoBuffs;

    //! Records the last emitted value for channel EmptyBuffs
    //!
    U32 m_last_EmptyBuffs;


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------
    NATIVE_UINT_TYPE m_NoBuffsAvailableThrottle; //!< throttle for NoBuffsAvailable
    NATIVE_UINT_TYPE m_ZeroSizeBufferThrottle; //!< throttle for ZeroSizeBuffer

  };

} // end namespace Svc
#endif
