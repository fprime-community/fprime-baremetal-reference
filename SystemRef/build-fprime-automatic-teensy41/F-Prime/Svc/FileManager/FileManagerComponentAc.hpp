// ======================================================================
// \title  FileManagerComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for FileManager component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_FILEMANAGER_COMP_HPP_
#define SVC_FILEMANAGER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Cmd/CmdString.hpp>
#include <Fw/Tlm/TlmString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Cmd/CmdResponseEnumAc.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Cmd/CmdPortAc.hpp>
#include <Fw/Cmd/CmdRegPortAc.hpp>
#include <Fw/Cmd/CmdResponsePortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>
#include <Svc/Ping/PingPortAc.hpp>

namespace Svc {

  //! \class FileManagerComponentBase
  //! \brief Auto-generated base for FileManager component
  //!
  class FileManagerComponentBase :
    public Fw::ActiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class FileManagerComponentBaseFriend;

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

    //! Construct a FileManagerComponentBase object
    //!
    FileManagerComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a FileManagerComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a FileManagerComponentBase object
    //!
    virtual ~FileManagerComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

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
       NUM_CMDIN_INPUT_PORTS = 1,
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
       NUM_CMDREGOUT_OUTPUT_PORTS = 1,
       NUM_CMDRESPONSEOUT_OUTPUT_PORTS = 1,
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
      OPCODE_CREATEDIRECTORY = 0x0, /* Create a directory */
      OPCODE_MOVEFILE = 0x1, /* Move a file */
      OPCODE_REMOVEDIRECTORY = 0x2, /* Remove a directory, which must be empty */
      OPCODE_REMOVEFILE = 0x3, /* Remove a file */
      OPCODE_SHELLCOMMAND = 0x4, /* Perform a Linux shell command and write the output to a log file. */
      OPCODE_APPENDFILE = 0x5, /* Append 1 file's contents to the end of another. */
      OPCODE_FILESIZE = 0x6, /*  */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handlers to implement
    // ----------------------------------------------------------------------

    //! Handler for command CreateDirectory
    /* Create a directory */
    virtual void CreateDirectory_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        const Fw::CmdStringArg& dirName /*!< 
          The directory to create
          */
    ) = 0;

    //! Handler for command MoveFile
    /* Move a file */
    virtual void MoveFile_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        const Fw::CmdStringArg& sourceFileName, /*!< 
          The source file name
          */
        const Fw::CmdStringArg& destFileName /*!< 
          The destination file name
          */
    ) = 0;

    //! Handler for command RemoveDirectory
    /* Remove a directory, which must be empty */
    virtual void RemoveDirectory_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        const Fw::CmdStringArg& dirName /*!< 
          The directory to remove
          */
    ) = 0;

    //! Handler for command RemoveFile
    /* Remove a file */
    virtual void RemoveFile_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        const Fw::CmdStringArg& fileName, /*!< 
          The file to remove
          */
        bool ignoreErrors /*!< 
          Ignore non-existent files
          */
    ) = 0;

    //! Handler for command ShellCommand
    /* Perform a Linux shell command and write the output to a log file. */
    virtual void ShellCommand_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        const Fw::CmdStringArg& command, /*!< 
          The shell command string
          */
        const Fw::CmdStringArg& logFileName /*!< 
          The name of the log file
          */
    ) = 0;

    //! Handler for command AppendFile
    /* Append 1 file's contents to the end of another. */
    virtual void AppendFile_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        const Fw::CmdStringArg& source, /*!< 
          The name of the file to take content from
          */
        const Fw::CmdStringArg& target /*!< 
          The name of the file to append to
          */
    ) = 0;

    //! Handler for command FileSize
    /*  */
    virtual void FileSize_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        const Fw::CmdStringArg& fileName /*!< 
          The file to get the size of
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

    //! Pre-message hook for command CreateDirectory
    //!
    virtual void CreateDirectory_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command MoveFile
    //!
    virtual void MoveFile_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command RemoveDirectory
    //!
    virtual void RemoveDirectory_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command RemoveFile
    //!
    virtual void RemoveFile_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command ShellCommand
    //!
    virtual void ShellCommand_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command AppendFile
    //!
    virtual void AppendFile_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command FileSize
    //!
    virtual void FileSize_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handler base-class functions.
    // Call these functions directly to bypass the command input port.
    // ----------------------------------------------------------------------

    //! Base-class handler function for command CreateDirectory
    //!
    void CreateDirectory_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command MoveFile
    //!
    void MoveFile_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command RemoveDirectory
    //!
    void RemoveDirectory_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command RemoveFile
    //!
    void RemoveFile_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command ShellCommand
    //!
    void ShellCommand_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command AppendFile
    //!
    void AppendFile_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command FileSize
    //!
    void FileSize_cmdHandlerBase(
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
      EVENTID_DIRECTORYCREATEERROR = 0x0, /* An error occurred while attempting to create a directory */
      EVENTID_DIRECTORYREMOVEERROR = 0x1, /* An error occurred while attempting to remove a directory */
      EVENTID_FILEMOVEERROR = 0x2, /* An error occurred while attempting to move a file */
      EVENTID_FILEREMOVEERROR = 0x3, /* An error occurred while attempting to remove a file */
      EVENTID_SHELLCOMMANDFAILED = 0x4, /* The File System component executed a shell command that returned status non-zero */
      EVENTID_APPENDFILEFAILED = 0x5, /* The File System component returned status non-zero when trying to append 2 files together */
      EVENTID_APPENDFILESUCCEEDED = 0x6, /* The File System component appended 2 files without error */
      EVENTID_SHELLCOMMANDSUCCEEDED = 0x7, /* The File System component executed a shell command that returned status zero */
      EVENTID_CREATEDIRECTORYSUCCEEDED = 0x8, /* The File System component created a new directory without error */
      EVENTID_REMOVEDIRECTORYSUCCEEDED = 0x9, /* The File System component deleted and existing directory without error */
      EVENTID_MOVEFILESUCCEEDED = 0xA, /* The File System component moved a file to a new location without error */
      EVENTID_REMOVEFILESUCCEEDED = 0xB, /* The File System component deleted an existing file without error */
      EVENTID_APPENDFILESTARTED = 0xC, /* The File System component appended 2 files without error */
      EVENTID_SHELLCOMMANDSTARTED = 0xD, /* The File System component began executing a shell command */
      EVENTID_CREATEDIRECTORYSTARTED = 0xE, /* The File System component began creating a new directory */
      EVENTID_REMOVEDIRECTORYSTARTED = 0xF, /* The File System component began deleting a directory */
      EVENTID_MOVEFILESTARTED = 0x10, /* The File System component began moving a file to a new location */
      EVENTID_REMOVEFILESTARTED = 0x11, /* The File System component began deleting an existing file */
      EVENTID_FILESIZESUCCEEDED = 0x12, /* File size response */
      EVENTID_FILESIZEERROR = 0x13, /* Failed to get file size */
      EVENTID_FILESIZESTARTED = 0x14, /* Checking file size */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event DirectoryCreateError
    //!
    /* An error occurred while attempting to create a directory */
    void log_WARNING_HI_DirectoryCreateError(
        const Fw::LogStringArg& dirName, /*!< The name of the directory*/
        U32 status /*!< The error status*/
    );


    //! Log event DirectoryRemoveError
    //!
    /* An error occurred while attempting to remove a directory */
    void log_WARNING_HI_DirectoryRemoveError(
        const Fw::LogStringArg& dirName, /*!< The name of the directory*/
        U32 status /*!< The error status*/
    );


    //! Log event FileMoveError
    //!
    /* An error occurred while attempting to move a file */
    void log_WARNING_HI_FileMoveError(
        const Fw::LogStringArg& sourceFileName, /*!< The name of the source file*/
        const Fw::LogStringArg& destFileName, /*!< The name of the destination file*/
        U32 status /*!< The error status*/
    );


    //! Log event FileRemoveError
    //!
    /* An error occurred while attempting to remove a file */
    void log_WARNING_HI_FileRemoveError(
        const Fw::LogStringArg& fileName, /*!< The name of the file*/
        U32 status /*!< The error status*/
    );


    //! Log event ShellCommandFailed
    //!
    /* The File System component executed a shell command that returned status non-zero */
    void log_WARNING_HI_ShellCommandFailed(
        const Fw::LogStringArg& command, /*!< The command string*/
        U32 status /*!< The status code*/
    );


    //! Log event AppendFileFailed
    //!
    /* The File System component returned status non-zero when trying to append 2 files together */
    void log_WARNING_HI_AppendFileFailed(
        const Fw::LogStringArg& source, /*!< The name of the file being read from*/
        const Fw::LogStringArg& target, /*!< The name of the file to append to*/
        U32 status /*!< The error status*/
    );


    //! Log event AppendFileSucceeded
    //!
    /* The File System component appended 2 files without error */
    void log_ACTIVITY_HI_AppendFileSucceeded(
        const Fw::LogStringArg& source, /*!< The name of the file being read from*/
        const Fw::LogStringArg& target /*!< The name of the file to append to*/
    );


    //! Log event ShellCommandSucceeded
    //!
    /* The File System component executed a shell command that returned status zero */
    void log_ACTIVITY_HI_ShellCommandSucceeded(
        const Fw::LogStringArg& command /*!< The command string*/
    );


    //! Log event CreateDirectorySucceeded
    //!
    /* The File System component created a new directory without error */
    void log_ACTIVITY_HI_CreateDirectorySucceeded(
        const Fw::LogStringArg& dirName /*!< The name of the directory*/
    );


    //! Log event RemoveDirectorySucceeded
    //!
    /* The File System component deleted and existing directory without error */
    void log_ACTIVITY_HI_RemoveDirectorySucceeded(
        const Fw::LogStringArg& dirName /*!< The name of the directory*/
    );


    //! Log event MoveFileSucceeded
    //!
    /* The File System component moved a file to a new location without error */
    void log_ACTIVITY_HI_MoveFileSucceeded(
        const Fw::LogStringArg& sourceFileName, /*!< The name of the source file*/
        const Fw::LogStringArg& destFileName /*!< The name of the destination file*/
    );


    //! Log event RemoveFileSucceeded
    //!
    /* The File System component deleted an existing file without error */
    void log_ACTIVITY_HI_RemoveFileSucceeded(
        const Fw::LogStringArg& fileName /*!< The name of the file*/
    );


    //! Log event AppendFileStarted
    //!
    /* The File System component appended 2 files without error */
    void log_ACTIVITY_HI_AppendFileStarted(
        const Fw::LogStringArg& source, /*!< The name of the file being read from*/
        const Fw::LogStringArg& target /*!< The name of the file to append to*/
    );


    //! Log event ShellCommandStarted
    //!
    /* The File System component began executing a shell command */
    void log_ACTIVITY_HI_ShellCommandStarted(
        const Fw::LogStringArg& command /*!< The command string*/
    );


    //! Log event CreateDirectoryStarted
    //!
    /* The File System component began creating a new directory */
    void log_ACTIVITY_HI_CreateDirectoryStarted(
        const Fw::LogStringArg& dirName /*!< The name of the directory*/
    );


    //! Log event RemoveDirectoryStarted
    //!
    /* The File System component began deleting a directory */
    void log_ACTIVITY_HI_RemoveDirectoryStarted(
        const Fw::LogStringArg& dirName /*!< The name of the directory*/
    );


    //! Log event MoveFileStarted
    //!
    /* The File System component began moving a file to a new location */
    void log_ACTIVITY_HI_MoveFileStarted(
        const Fw::LogStringArg& sourceFileName, /*!< The name of the source file*/
        const Fw::LogStringArg& destFileName /*!< The name of the destination file*/
    );


    //! Log event RemoveFileStarted
    //!
    /* The File System component began deleting an existing file */
    void log_ACTIVITY_HI_RemoveFileStarted(
        const Fw::LogStringArg& fileName /*!< The name of the file*/
    );


    //! Log event FileSizeSucceeded
    //!
    /* File size response */
    void log_ACTIVITY_HI_FileSizeSucceeded(
        const Fw::LogStringArg& fileName, /*!< The name of the file*/
        U64 size /*!< The size of the file in bytes*/
    );


    //! Log event FileSizeError
    //!
    /* Failed to get file size */
    void log_WARNING_HI_FileSizeError(
        const Fw::LogStringArg& fileName, /*!< The name of the file*/
        U32 status /*!< The error status*/
    );


    //! Log event FileSizeStarted
    //!
    /* Checking file size */
    void log_ACTIVITY_HI_FileSizeStarted(
        const Fw::LogStringArg& fileName /*!< The name of the file*/
    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_COMMANDSEXECUTED = 0x0, //!< Channel ID for CommandsExecuted
      CHANNELID_ERRORS = 0x1, //!< Channel ID for Errors
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel CommandsExecuted
    //!
    /* The total number of commands successfully executed */
    void tlmWrite_CommandsExecuted(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel Errors
    //!
    /* The total number of errors */
    void tlmWrite_Errors(
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

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Output port LogText
    //!
    Fw::OutputLogTextPort m_LogText_OutputPort[NUM_LOGTEXT_OUTPUT_PORTS];
#endif

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
