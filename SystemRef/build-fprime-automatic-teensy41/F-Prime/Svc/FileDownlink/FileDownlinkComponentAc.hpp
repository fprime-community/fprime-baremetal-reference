// ======================================================================
// \title  FileDownlinkComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for FileDownlink component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_FILEDOWNLINK_COMP_HPP_
#define SVC_FILEDOWNLINK_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Os/Mutex.hpp>
#include <Fw/Cmd/CmdString.hpp>
#include <Fw/Tlm/TlmString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Cmd/CmdResponseEnumAc.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Svc/FileDownlinkPorts/SendFileStatusEnumAc.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Buffer/BufferSendPortAc.hpp>
#include <Fw/Cmd/CmdPortAc.hpp>
#include <Fw/Cmd/CmdRegPortAc.hpp>
#include <Fw/Cmd/CmdResponsePortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>
#include <Svc/FileDownlinkPorts/SendFileCompletePortAc.hpp>
#include <Svc/FileDownlinkPorts/SendFileRequestPortAc.hpp>
#include <Svc/Ping/PingPortAc.hpp>
#include <Svc/Sched/SchedPortAc.hpp>
#include <Svc/FileDownlinkPorts/SendFileResponseSerializableAc.hpp>

namespace Svc {

  //! \class FileDownlinkComponentBase
  //! \brief Auto-generated base for FileDownlink component
  //!
  class FileDownlinkComponentBase :
    public Fw::ActiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class FileDownlinkComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return Run[portNum]
    //!
    Svc::InputSchedPort* get_Run_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return SendFile[portNum]
    //!
    Svc::InputSendFileRequestPort* get_SendFile_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return bufferReturn[portNum]
    //!
    Fw::InputBufferSendPort* get_bufferReturn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return cmdIn[portNum]
    //!
    Fw::InputCmdPort* get_cmdIn_InputPort(
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

    //! Connect port to FileComplete[portNum]
    //!
    void set_FileComplete_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::InputSendFileCompletePort *port /*!< The port*/
    );

    //! Connect port to bufferSendOut[portNum]
    //!
    void set_bufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

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

    //! Connect port to FileComplete[portNum]
    //!
    void set_FileComplete_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to bufferSendOut[portNum]
    //!
    void set_bufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

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

    //! Construct a FileDownlinkComponentBase object
    //!
    FileDownlinkComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a FileDownlinkComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a FileDownlinkComponentBase object
    //!
    virtual ~FileDownlinkComponentBase();

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

    //! Handler for input port Run
    //
    virtual void Run_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    ) = 0;

    //! Handler for input port SendFile
    //
    virtual Svc::SendFileResponse SendFile_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        const sourceFileNameString &sourceFileName, /*!< 
      Path of file to downlink
      */
        const destFileNameString &destFileName, /*!< 
      Path to store downlinked file at
      */
        U32 offset, /*!< 
      Amount of data in bytes to downlink from file. 0 to read until end of file
      */
        U32 length /*!< 
      Amount of data in bytes to downlink from file. 0 to read until end of file
      */
    ) = 0;

    //! Handler for input port bufferReturn
    //
    virtual void bufferReturn_handler(
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

    //! Handler base-class function for input port Run
    //!
    void Run_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

    //! Handler base-class function for input port SendFile
    //!
    Svc::SendFileResponse SendFile_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        const sourceFileNameString &sourceFileName, /*!< 
      Path of file to downlink
      */
        const destFileNameString &destFileName, /*!< 
      Path to store downlinked file at
      */
        U32 offset, /*!< 
      Amount of data in bytes to downlink from file. 0 to read until end of file
      */
        U32 length /*!< 
      Amount of data in bytes to downlink from file. 0 to read until end of file
      */
    );

    //! Handler base-class function for input port bufferReturn
    //!
    void bufferReturn_handlerBase(
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

    //! Pre-message hook for async input port Run
    //!
    virtual void Run_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

    //! Pre-message hook for async input port bufferReturn
    //!
    virtual void bufferReturn_preMsgHook(
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

    //! Invoke output port FileComplete
    //!
    void FileComplete_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        const Svc::SendFileResponse &resp 
    );

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

    //! Get the number of Run input ports
    //!
    //! \return The number of Run input ports
    //!
    NATIVE_INT_TYPE getNum_Run_InputPorts();

    //! Get the number of SendFile input ports
    //!
    //! \return The number of SendFile input ports
    //!
    NATIVE_INT_TYPE getNum_SendFile_InputPorts();

    //! Get the number of bufferReturn input ports
    //!
    //! \return The number of bufferReturn input ports
    //!
    NATIVE_INT_TYPE getNum_bufferReturn_InputPorts();

    //! Get the number of cmdIn input ports
    //!
    //! \return The number of cmdIn input ports
    //!
    NATIVE_INT_TYPE getNum_cmdIn_InputPorts();

    //! Get the number of pingIn input ports
    //!
    //! \return The number of pingIn input ports
    //!
    NATIVE_INT_TYPE getNum_pingIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_RUN_INPUT_PORTS = 1,
       NUM_SENDFILE_INPUT_PORTS = 1,
       NUM_BUFFERRETURN_INPUT_PORTS = 1,
       NUM_CMDIN_INPUT_PORTS = 1,
       NUM_PINGIN_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of FileComplete output ports
    //!
    //! \return The number of FileComplete output ports
    //!
    NATIVE_INT_TYPE getNum_FileComplete_OutputPorts();

    //! Get the number of bufferSendOut output ports
    //!
    //! \return The number of bufferSendOut output ports
    //!
    NATIVE_INT_TYPE getNum_bufferSendOut_OutputPorts();

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
       NUM_FILECOMPLETE_OUTPUT_PORTS = 1,
       NUM_BUFFERSENDOUT_OUTPUT_PORTS = 1,
       NUM_CMDREGOUT_OUTPUT_PORTS = 1,
       NUM_CMDRESPONSEOUT_OUTPUT_PORTS = 1,
       NUM_EVENTOUT_OUTPUT_PORTS = 1,
       NUM_PINGOUT_OUTPUT_PORTS = 1,
       NUM_TEXTEVENTOUT_OUTPUT_PORTS = 1,
       NUM_TIMECALLER_OUTPUT_PORTS = 1,
       NUM_TLMOUT_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port FileComplete is connected
    //!
    //! \return Whether port FileComplete is connected
    //!
    bool isConnected_FileComplete_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port bufferSendOut is connected
    //!
    //! \return Whether port bufferSendOut is connected
    //!
    bool isConnected_bufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

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
    // Command opcodes
    // ----------------------------------------------------------------------

    enum {
      OPCODE_SENDFILE = 0x0, /* Read a named file off the disk. Divide it into packets and send the packets for transmission to the ground. */
      OPCODE_CANCEL = 0x1, /* Cancel the downlink in progress, if any */
      OPCODE_SENDPARTIAL = 0x2, /* Read a named file off the disk from a starting position. Divide it into packets and send the packets for transmission to the ground. */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handlers to implement
    // ----------------------------------------------------------------------

    //! Handler for command SendFile
    /* Read a named file off the disk. Divide it into packets and send the packets for transmission to the ground. */
    virtual void SendFile_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        const Fw::CmdStringArg& sourceFileName, /*!< 
          The name of the on-board file to send
          */
        const Fw::CmdStringArg& destFileName /*!< 
          The name of the destination file on the ground
          */
    ) = 0;

    //! Handler for command Cancel
    /* Cancel the downlink in progress, if any */
    virtual void Cancel_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    ) = 0;

    //! Handler for command SendPartial
    /* Read a named file off the disk from a starting position. Divide it into packets and send the packets for transmission to the ground. */
    virtual void SendPartial_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        const Fw::CmdStringArg& sourceFileName, /*!< 
          The name of the on-board file to send
          */
        const Fw::CmdStringArg& destFileName, /*!< 
          The name of the destination file on the ground
          */
        U32 startOffset, /*!< 
          Starting offset of the source file
          */
        U32 length /*!< 
          Number of bytes to send from starting offset. Length of 0 implies until the end of the file
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

    //! Pre-message hook for command SendFile
    //!
    virtual void SendFile_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command Cancel
    //!
    virtual void Cancel_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command SendPartial
    //!
    virtual void SendPartial_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handler base-class functions.
    // Call these functions directly to bypass the command input port.
    // ----------------------------------------------------------------------

    //! Base-class handler function for command SendFile
    //!
    void SendFile_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command Cancel
    //!
    void Cancel_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command SendPartial
    //!
    void SendPartial_cmdHandlerBase(
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
      EVENTID_FILEOPENERROR = 0x0, /* An error occurred opening a file */
      EVENTID_FILEREADERROR = 0x1, /* An error occurred reading a file */
      EVENTID_FILESENT = 0x2, /* The File Downlink component successfully sent a file */
      EVENTID_DOWNLINKCANCELED = 0x3, /* The File Downlink component canceled downlink of a file */
      EVENTID_DOWNLINKTIMEOUT = 0x4, /* The File Downlink component has detected a timeout. Downlink has been canceled. */
      EVENTID_DOWNLINKPARTIALWARNING = 0x5, /* The File Downlink component has detected a timeout. Downlink has been canceled. */
      EVENTID_DOWNLINKPARTIALFAIL = 0x6, /* The File Downlink component has detected a timeout. Downlink has been canceled. */
      EVENTID_SENDDATAFAIL = 0x7, /* The File Downlink component generated an error when trying to send a data packet. */
      EVENTID_SENDSTARTED = 0x8, /* The File Downlink component started a file download. */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event FileOpenError
    //!
    /* An error occurred opening a file */
    void log_WARNING_HI_FileOpenError(
        const Fw::LogStringArg& fileName /*!< The name of the file*/
    );


    //! Log event FileReadError
    //!
    /* An error occurred reading a file */
    void log_WARNING_HI_FileReadError(
        const Fw::LogStringArg& fileName, /*!< The name of the file*/
        I32 status /*!< The file status of read*/
    );


    //! Log event FileSent
    //!
    /* The File Downlink component successfully sent a file */
    void log_ACTIVITY_HI_FileSent(
        const Fw::LogStringArg& sourceFileName, /*!< The source file name*/
        const Fw::LogStringArg& destFileName /*!< The destination file name*/
    );


    //! Log event DownlinkCanceled
    //!
    /* The File Downlink component canceled downlink of a file */
    void log_ACTIVITY_HI_DownlinkCanceled(
        const Fw::LogStringArg& sourceFileName, /*!< The source file name*/
        const Fw::LogStringArg& destFileName /*!< The destination file name*/
    );


    //! Log event DownlinkTimeout
    //!
    /* The File Downlink component has detected a timeout. Downlink has been canceled. */
    void log_WARNING_HI_DownlinkTimeout(
        const Fw::LogStringArg& sourceFileName, /*!< The source filename*/
        const Fw::LogStringArg& destFileName /*!< The destination file name*/
    );


    //! Log event DownlinkPartialWarning
    //!
    /* The File Downlink component has detected a timeout. Downlink has been canceled. */
    void log_WARNING_LO_DownlinkPartialWarning(
        U32 startOffset, /*!< Starting file offset in bytes*/
        U32 length, /*!< Number of bytes to downlink*/
        U32 filesize, /*!< Size of source file*/
        const Fw::LogStringArg& sourceFileName, /*!< The source filename*/
        const Fw::LogStringArg& destFileName /*!< The destination file name*/
    );


    //! Log event DownlinkPartialFail
    //!
    /* The File Downlink component has detected a timeout. Downlink has been canceled. */
    void log_WARNING_HI_DownlinkPartialFail(
        const Fw::LogStringArg& sourceFileName, /*!< The source filename*/
        const Fw::LogStringArg& destFileName, /*!< The destination file name*/
        U32 startOffset, /*!< Starting file offset in bytes*/
        U32 filesize /*!< Size of source file*/
    );


    //! Log event SendDataFail
    //!
    /* The File Downlink component generated an error when trying to send a data packet. */
    void log_WARNING_HI_SendDataFail(
        const Fw::LogStringArg& sourceFileName, /*!< The source filename*/
        U32 byteOffset /*!< Byte offset*/
    );


    //! Log event SendStarted
    //!
    /* The File Downlink component started a file download. */
    void log_ACTIVITY_HI_SendStarted(
        U32 fileSize, /*!< The source file size*/
        const Fw::LogStringArg& sourceFileName, /*!< The source filename*/
        const Fw::LogStringArg& destFileName /*!< The destination filename*/
    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_FILESSENT = 0x0, //!< Channel ID for FilesSent
      CHANNELID_PACKETSSENT = 0x1, //!< Channel ID for PacketsSent
      CHANNELID_WARNINGS = 0x2, //!< Channel ID for Warnings
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel FilesSent
    //!
    /* The total number of files sent */
    void tlmWrite_FilesSent(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel PacketsSent
    //!
    /* The total number of packets sent */
    void tlmWrite_PacketsSent(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel Warnings
    //!
    /* The total number of warnings */
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

    //! Input port Run
    //!
    Svc::InputSchedPort m_Run_InputPort[NUM_RUN_INPUT_PORTS];

    //! Input port SendFile
    //!
    Svc::InputSendFileRequestPort m_SendFile_InputPort[NUM_SENDFILE_INPUT_PORTS];

    //! Input port bufferReturn
    //!
    Fw::InputBufferSendPort m_bufferReturn_InputPort[NUM_BUFFERRETURN_INPUT_PORTS];

    //! Input port cmdIn
    //!
    Fw::InputCmdPort m_cmdIn_InputPort[NUM_CMDIN_INPUT_PORTS];

    //! Input port pingIn
    //!
    Svc::InputPingPort m_pingIn_InputPort[NUM_PINGIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port FileComplete
    //!
    Svc::OutputSendFileCompletePort m_FileComplete_OutputPort[NUM_FILECOMPLETE_OUTPUT_PORTS];

    //! Output port bufferSendOut
    //!
    Fw::OutputBufferSendPort m_bufferSendOut_OutputPort[NUM_BUFFERSENDOUT_OUTPUT_PORTS];

    //! Output port cmdRegOut
    //!
    Fw::OutputCmdRegPort m_cmdRegOut_OutputPort[NUM_CMDREGOUT_OUTPUT_PORTS];

    //! Output port cmdResponseOut
    //!
    Fw::OutputCmdResponsePort m_cmdResponseOut_OutputPort[NUM_CMDRESPONSEOUT_OUTPUT_PORTS];

    //! Output port eventOut
    //!
    Fw::OutputLogPort m_eventOut_OutputPort[NUM_EVENTOUT_OUTPUT_PORTS];

    //! Output port pingOut
    //!
    Svc::OutputPingPort m_pingOut_OutputPort[NUM_PINGOUT_OUTPUT_PORTS];

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

    //! Callback for port Run
    //!
    static void m_p_Run_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

    //! Callback for port SendFile
    //!
    static Svc::SendFileResponse m_p_SendFile_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        const sourceFileNameString &sourceFileName, /*!< 
      Path of file to downlink
      */
        const destFileNameString &destFileName, /*!< 
      Path to store downlinked file at
      */
        U32 offset, /*!< 
      Amount of data in bytes to downlink from file. 0 to read until end of file
      */
        U32 length /*!< 
      Amount of data in bytes to downlink from file. 0 to read until end of file
      */
    );

    //! Callback for port bufferReturn
    //!
    static void m_p_bufferReturn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

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
    // Mutexes
    // ----------------------------------------------------------------------

    //! Mutex for guarded ports
    //!
    Os::Mutex m_guardedPortMutex;


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------

  };

} // end namespace Svc
#endif
