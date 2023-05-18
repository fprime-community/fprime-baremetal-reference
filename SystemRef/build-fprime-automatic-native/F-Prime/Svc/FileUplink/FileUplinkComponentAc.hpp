// ======================================================================
// \title  FileUplinkComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for FileUplink component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_FILEUPLINK_COMP_HPP_
#define SVC_FILEUPLINK_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Tlm/TlmString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Buffer/BufferSendPortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>
#include <Svc/Ping/PingPortAc.hpp>

namespace Svc {

  //! \class FileUplinkComponentBase
  //! \brief Auto-generated base for FileUplink component
  //!
  class FileUplinkComponentBase :
    public Fw::ActiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class FileUplinkComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return bufferSendIn[portNum]
    //!
    Fw::InputBufferSendPort* get_bufferSendIn_InputPort(
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

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogTextPort *port /*!< The port*/
    );
#endif

    //! Connect port to bufferSendOut[portNum]
    //!
    void set_bufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to eventOut[portNum]
    //!
    void set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogPort *port /*!< The port*/
    );

    //! Connect port to pingOut[portNum]
    //!
    void set_pingOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::InputPingPort *port /*!< The port*/
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

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );
#endif

    //! Connect port to bufferSendOut[portNum]
    //!
    void set_bufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to eventOut[portNum]
    //!
    void set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to pingOut[portNum]
    //!
    void set_pingOut_OutputPort(
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

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a FileUplinkComponentBase object
    //!
    FileUplinkComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a FileUplinkComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a FileUplinkComponentBase object
    //!
    virtual ~FileUplinkComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port bufferSendIn
    //
    virtual void bufferSendIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
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

    //! Handler base-class function for input port bufferSendIn
    //!
    void bufferSendIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
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

    //! Pre-message hook for async input port bufferSendIn
    //!
    virtual void bufferSendIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

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

    //! Invoke output port bufferSendOut
    //!
    void bufferSendOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
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

    //! Get the number of bufferSendIn input ports
    //!
    //! \return The number of bufferSendIn input ports
    //!
    NATIVE_INT_TYPE getNum_bufferSendIn_InputPorts();

    //! Get the number of pingIn input ports
    //!
    //! \return The number of pingIn input ports
    //!
    NATIVE_INT_TYPE getNum_pingIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_BUFFERSENDIN_INPUT_PORTS = 1,
       NUM_PINGIN_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Get the number of LogText output ports
    //!
    //! \return The number of LogText output ports
    //!
    NATIVE_INT_TYPE getNum_LogText_OutputPorts();
#endif

    //! Get the number of bufferSendOut output ports
    //!
    //! \return The number of bufferSendOut output ports
    //!
    NATIVE_INT_TYPE getNum_bufferSendOut_OutputPorts();

    //! Get the number of eventOut output ports
    //!
    //! \return The number of eventOut output ports
    //!
    NATIVE_INT_TYPE getNum_eventOut_OutputPorts();

    //! Get the number of pingOut output ports
    //!
    //! \return The number of pingOut output ports
    //!
    NATIVE_INT_TYPE getNum_pingOut_OutputPorts();

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
       NUM_LOGTEXT_OUTPUT_PORTS = 1,
       NUM_BUFFERSENDOUT_OUTPUT_PORTS = 1,
       NUM_EVENTOUT_OUTPUT_PORTS = 1,
       NUM_PINGOUT_OUTPUT_PORTS = 1,
       NUM_TIMECALLER_OUTPUT_PORTS = 1,
       NUM_TLMOUT_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Check whether port LogText is connected
    //!
    //! \return Whether port LogText is connected
    //!
    bool isConnected_LogText_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );
#endif

    //! Check whether port bufferSendOut is connected
    //!
    //! \return Whether port bufferSendOut is connected
    //!
    bool isConnected_bufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port eventOut is connected
    //!
    //! \return Whether port eventOut is connected
    //!
    bool isConnected_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port pingOut is connected
    //!
    //! \return Whether port pingOut is connected
    //!
    bool isConnected_pingOut_OutputPort(
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
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_BADCHECKSUM = 0x0, /* During receipt of a file, the computed checksum value did not match the stored value */
      EVENTID_FILEOPENERROR = 0x1, /* An error occurred opening a file */
      EVENTID_FILERECEIVED = 0x2, /* The File Uplink component successfully received a file */
      EVENTID_FILEWRITEERROR = 0x3, /* An error occurred writing to a file */
      EVENTID_INVALIDRECEIVEMODE = 0x4, /* The File Uplink component received a packet with a type that was invalid for the current receive mode */
      EVENTID_PACKETOUTOFBOUNDS = 0x5, /* During receipt of a file, the File Uplink component encountered a packet with offset and size out of bounds for the current file */
      EVENTID_PACKETOUTOFORDER = 0x6, /* The File Uplink component encountered an out-of-order packet during file receipt */
      EVENTID_UPLINKCANCELED = 0x7, /* The File Uplink component received a CANCEL packet */
      EVENTID_DECODEERROR = 0x8, /* Error decoding file packet */
    };

    // ----------------------------------------------------------------------
    // Event Throttle values - sets initial value of countdown variable
    // ----------------------------------------------------------------------

    enum {
      EVENTID_FILEWRITEERROR_THROTTLE = 5, /*!< Throttle reset count for FileWriteError*/
      EVENTID_INVALIDRECEIVEMODE_THROTTLE = 5, /*!< Throttle reset count for InvalidReceiveMode*/
      EVENTID_PACKETOUTOFBOUNDS_THROTTLE = 5, /*!< Throttle reset count for PacketOutOfBounds*/
      EVENTID_PACKETOUTOFORDER_THROTTLE = 20, /*!< Throttle reset count for PacketOutOfOrder*/
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event BadChecksum
    //!
    /* During receipt of a file, the computed checksum value did not match the stored value */
    void log_WARNING_HI_BadChecksum(
        const Fw::LogStringArg& fileName, /*!< The file name*/
        U32 computed, /*!< The computed value*/
        U32 read /*!< The value read*/
    );


    //! Log event FileOpenError
    //!
    /* An error occurred opening a file */
    void log_WARNING_HI_FileOpenError(
        const Fw::LogStringArg& fileName /*!< The name of the file*/
    );


    //! Log event FileReceived
    //!
    /* The File Uplink component successfully received a file */
    void log_ACTIVITY_HI_FileReceived(
        const Fw::LogStringArg& fileName /*!< The name of the file*/
    );


    //! Log event FileWriteError
    //!
    /* An error occurred writing to a file */
    void log_WARNING_HI_FileWriteError(
        const Fw::LogStringArg& fileName /*!< The name of the file*/
    );

    // reset throttle value for FileWriteError
    void log_WARNING_HI_FileWriteError_ThrottleClear();

    //! Log event InvalidReceiveMode
    //!
    /* The File Uplink component received a packet with a type that was invalid for the current receive mode */
    void log_WARNING_HI_InvalidReceiveMode(
        U32 packetType, /*!< The type of the packet received*/
        U32 mode /*!< The receive mode*/
    );

    // reset throttle value for InvalidReceiveMode
    void log_WARNING_HI_InvalidReceiveMode_ThrottleClear();

    //! Log event PacketOutOfBounds
    //!
    /* During receipt of a file, the File Uplink component encountered a packet with offset and size out of bounds for the current file */
    void log_WARNING_HI_PacketOutOfBounds(
        U32 packetIndex, /*!< The sequence index of the packet*/
        const Fw::LogStringArg& fileName /*!< The name of the file*/
    );

    // reset throttle value for PacketOutOfBounds
    void log_WARNING_HI_PacketOutOfBounds_ThrottleClear();

    //! Log event PacketOutOfOrder
    //!
    /* The File Uplink component encountered an out-of-order packet during file receipt */
    void log_WARNING_HI_PacketOutOfOrder(
        U32 packetIndex, /*!< The sequence index of the out-of-order packet*/
        U32 lastPacketIndex /*!< The sequence index of the last packet received before the out-of-order packet*/
    );

    // reset throttle value for PacketOutOfOrder
    void log_WARNING_HI_PacketOutOfOrder_ThrottleClear();

    //! Log event UplinkCanceled
    //!
    /* The File Uplink component received a CANCEL packet */
    void log_ACTIVITY_HI_UplinkCanceled(

    );


    //! Log event DecodeError
    //!
    /* Error decoding file packet */
    void log_WARNING_HI_DecodeError(
        I32 status /*!< The sequence index of the out-of-order packet*/
    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_FILESRECEIVED = 0x0, //!< Channel ID for FilesReceived
      CHANNELID_PACKETSRECEIVED = 0x1, //!< Channel ID for PacketsReceived
      CHANNELID_WARNINGS = 0x2, //!< Channel ID for Warnings
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel FilesReceived
    //!
    /* The total number of complete files received */
    void tlmWrite_FilesReceived(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel PacketsReceived
    //!
    /* The total number of packets received */
    void tlmWrite_PacketsReceived(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel Warnings
    //!
    /* The total number of warnings issued */
    void tlmWrite_Warnings(
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

    //! Input port bufferSendIn
    //!
    Fw::InputBufferSendPort m_bufferSendIn_InputPort[NUM_BUFFERSENDIN_INPUT_PORTS];

    //! Input port pingIn
    //!
    Svc::InputPingPort m_pingIn_InputPort[NUM_PINGIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Output port LogText
    //!
    Fw::OutputLogTextPort m_LogText_OutputPort[NUM_LOGTEXT_OUTPUT_PORTS];
#endif

    //! Output port bufferSendOut
    //!
    Fw::OutputBufferSendPort m_bufferSendOut_OutputPort[NUM_BUFFERSENDOUT_OUTPUT_PORTS];

    //! Output port eventOut
    //!
    Fw::OutputLogPort m_eventOut_OutputPort[NUM_EVENTOUT_OUTPUT_PORTS];

    //! Output port pingOut
    //!
    Svc::OutputPingPort m_pingOut_OutputPort[NUM_PINGOUT_OUTPUT_PORTS];

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

    //! Callback for port bufferSendIn
    //!
    static void m_p_bufferSendIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
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
    NATIVE_UINT_TYPE m_FileWriteErrorThrottle; //!< throttle for FileWriteError
    NATIVE_UINT_TYPE m_InvalidReceiveModeThrottle; //!< throttle for InvalidReceiveMode
    NATIVE_UINT_TYPE m_PacketOutOfBoundsThrottle; //!< throttle for PacketOutOfBounds
    NATIVE_UINT_TYPE m_PacketOutOfOrderThrottle; //!< throttle for PacketOutOfOrder

  };

} // end namespace Svc
#endif
