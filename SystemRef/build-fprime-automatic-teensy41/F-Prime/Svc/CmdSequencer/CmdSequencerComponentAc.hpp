// ======================================================================
// \title  CmdSequencerComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for CmdSequencer component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_CMDSEQUENCER_COMP_HPP_
#define SVC_CMDSEQUENCER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Cmd/CmdString.hpp>
#include <Fw/Tlm/TlmString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Svc/CmdSequencer/CmdSequencer_BlockStateEnumAc.hpp>
#include <Svc/CmdSequencer/CmdSequencer_FileReadStageEnumAc.hpp>
#include <Svc/CmdSequencer/CmdSequencer_SeqModeEnumAc.hpp>
#include <Fw/Cmd/CmdResponseEnumAc.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Fw/Com/ComBuffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Types/String.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Fw/Com/ComBuffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Types/String.hpp>
#include <Fw/Cmd/CmdPortAc.hpp>
#include <Fw/Cmd/CmdRegPortAc.hpp>
#include <Fw/Cmd/CmdResponsePortAc.hpp>
#include <Fw/Com/ComPortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>
#include <Svc/Ping/PingPortAc.hpp>
#include <Svc/Sched/SchedPortAc.hpp>
#include <Svc/Seq/CmdSeqCancelPortAc.hpp>
#include <Svc/Seq/CmdSeqInPortAc.hpp>

namespace Svc {

  //! \class CmdSequencerComponentBase
  //! \brief Auto-generated base for CmdSequencer component
  //!
  class CmdSequencerComponentBase :
    public Fw::ActiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class CmdSequencerComponentBaseFriend;

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
    //! \return cmdResponseIn[portNum]
    //!
    Fw::InputCmdResponsePort* get_cmdResponseIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return pingIn[portNum]
    //!
    Svc::InputPingPort* get_pingIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return schedIn[portNum]
    //!
    Svc::InputSchedPort* get_schedIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return seqCancelIn[portNum]
    //!
    Svc::InputCmdSeqCancelPort* get_seqCancelIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return seqRunIn[portNum]
    //!
    Svc::InputCmdSeqInPort* get_seqRunIn_InputPort(
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

    //! Connect port to comCmdOut[portNum]
    //!
    void set_comCmdOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputComPort *port /*!< The port*/
    );

    //! Connect port to logOut[portNum]
    //!
    void set_logOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogPort *port /*!< The port*/
    );

    //! Connect port to pingOut[portNum]
    //!
    void set_pingOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::InputPingPort *port /*!< The port*/
    );

    //! Connect port to seqDone[portNum]
    //!
    void set_seqDone_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputCmdResponsePort *port /*!< The port*/
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

    //! Connect port to comCmdOut[portNum]
    //!
    void set_comCmdOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to logOut[portNum]
    //!
    void set_logOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to pingOut[portNum]
    //!
    void set_pingOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to seqDone[portNum]
    //!
    void set_seqDone_OutputPort(
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

    //! Construct a CmdSequencerComponentBase object
    //!
    CmdSequencerComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a CmdSequencerComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a CmdSequencerComponentBase object
    //!
    virtual ~CmdSequencerComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port cmdResponseIn
    //
    virtual void cmdResponseIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwOpcodeType opCode, /*!< 
      Command Op Code
      */
        U32 cmdSeq, /*!< 
      Command Sequence
      */
        const Fw::CmdResponse &response /*!< 
      The command response argument
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

    //! Handler for input port schedIn
    //
    virtual void schedIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    ) = 0;

    //! Handler for input port seqCancelIn
    //
    virtual void seqCancelIn_handler(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    ) = 0;

    //! Handler for input port seqRunIn
    //
    virtual void seqRunIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::String &filename /*!< 
      The sequence file
      */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port cmdResponseIn
    //!
    void cmdResponseIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
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

    //! Handler base-class function for input port pingIn
    //!
    void pingIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< 
      Value to return to pinger
      */
    );

    //! Handler base-class function for input port schedIn
    //!
    void schedIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

    //! Handler base-class function for input port seqCancelIn
    //!
    void seqCancelIn_handlerBase(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Handler base-class function for input port seqRunIn
    //!
    void seqRunIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::String &filename /*!< 
      The sequence file
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

    //! Pre-message hook for async input port cmdResponseIn
    //!
    virtual void cmdResponseIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
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

    //! Pre-message hook for async input port pingIn
    //!
    virtual void pingIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< 
      Value to return to pinger
      */
    );

    //! Pre-message hook for async input port schedIn
    //!
    virtual void schedIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

    //! Pre-message hook for async input port seqCancelIn
    //!
    virtual void seqCancelIn_preMsgHook(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Pre-message hook for async input port seqRunIn
    //!
    virtual void seqRunIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::String &filename /*!< 
      The sequence file
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port comCmdOut
    //!
    void comCmdOut_out(
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

    //! Invoke output port seqDone
    //!
    void seqDone_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
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

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of cmdIn input ports
    //!
    //! \return The number of cmdIn input ports
    //!
    NATIVE_INT_TYPE getNum_cmdIn_InputPorts();

    //! Get the number of cmdResponseIn input ports
    //!
    //! \return The number of cmdResponseIn input ports
    //!
    NATIVE_INT_TYPE getNum_cmdResponseIn_InputPorts();

    //! Get the number of pingIn input ports
    //!
    //! \return The number of pingIn input ports
    //!
    NATIVE_INT_TYPE getNum_pingIn_InputPorts();

    //! Get the number of schedIn input ports
    //!
    //! \return The number of schedIn input ports
    //!
    NATIVE_INT_TYPE getNum_schedIn_InputPorts();

    //! Get the number of seqCancelIn input ports
    //!
    //! \return The number of seqCancelIn input ports
    //!
    NATIVE_INT_TYPE getNum_seqCancelIn_InputPorts();

    //! Get the number of seqRunIn input ports
    //!
    //! \return The number of seqRunIn input ports
    //!
    NATIVE_INT_TYPE getNum_seqRunIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_CMDIN_INPUT_PORTS = 1,
       NUM_CMDRESPONSEIN_INPUT_PORTS = 1,
       NUM_PINGIN_INPUT_PORTS = 1,
       NUM_SCHEDIN_INPUT_PORTS = 1,
       NUM_SEQCANCELIN_INPUT_PORTS = 1,
       NUM_SEQRUNIN_INPUT_PORTS = 1,
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

    //! Get the number of comCmdOut output ports
    //!
    //! \return The number of comCmdOut output ports
    //!
    NATIVE_INT_TYPE getNum_comCmdOut_OutputPorts();

    //! Get the number of logOut output ports
    //!
    //! \return The number of logOut output ports
    //!
    NATIVE_INT_TYPE getNum_logOut_OutputPorts();

    //! Get the number of pingOut output ports
    //!
    //! \return The number of pingOut output ports
    //!
    NATIVE_INT_TYPE getNum_pingOut_OutputPorts();

    //! Get the number of seqDone output ports
    //!
    //! \return The number of seqDone output ports
    //!
    NATIVE_INT_TYPE getNum_seqDone_OutputPorts();

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
       NUM_COMCMDOUT_OUTPUT_PORTS = 1,
       NUM_LOGOUT_OUTPUT_PORTS = 1,
       NUM_PINGOUT_OUTPUT_PORTS = 1,
       NUM_SEQDONE_OUTPUT_PORTS = 1,
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

    //! Check whether port comCmdOut is connected
    //!
    //! \return Whether port comCmdOut is connected
    //!
    bool isConnected_comCmdOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port logOut is connected
    //!
    //! \return Whether port logOut is connected
    //!
    bool isConnected_logOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port pingOut is connected
    //!
    //! \return Whether port pingOut is connected
    //!
    bool isConnected_pingOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port seqDone is connected
    //!
    //! \return Whether port seqDone is connected
    //!
    bool isConnected_seqDone_OutputPort(
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
      OPCODE_CS_RUN = 0x0, /* Run a command sequence file */
      OPCODE_CS_VALIDATE = 0x1, /* Validate a command sequence file */
      OPCODE_CS_CANCEL = 0x2, /* Cancel a command sequence */
      OPCODE_CS_START = 0x3, /* Start running a command sequence */
      OPCODE_CS_STEP = 0x4, /* Perform one step in a command sequence. Valid only if CmdSequencer is in MANUAL run mode. */
      OPCODE_CS_AUTO = 0x5, /* Set the run mode to AUTO. */
      OPCODE_CS_MANUAL = 0x6, /* Set the run mode to MANUAL. */
      OPCODE_CS_JOIN_WAIT = 0x7, /* Wait for sequences that are running to finish. Allow user to run multiple seq files in SEQ_NO_BLOCK mode then wait for them to finish before allowing more seq run request. */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handlers to implement
    // ----------------------------------------------------------------------

    //! Handler for command CS_RUN
    /* Run a command sequence file */
    virtual void CS_RUN_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        const Fw::CmdStringArg& fileName, /*!< 
          The name of the sequence file
          */
        Svc::CmdSequencer_BlockState block /*!< 
          Return command status when complete or not
          */
    ) = 0;

    //! Handler for command CS_VALIDATE
    /* Validate a command sequence file */
    virtual void CS_VALIDATE_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        const Fw::CmdStringArg& fileName /*!< 
          The name of the sequence file
          */
    ) = 0;

    //! Handler for command CS_CANCEL
    /* Cancel a command sequence */
    virtual void CS_CANCEL_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    ) = 0;

    //! Handler for command CS_START
    /* Start running a command sequence */
    virtual void CS_START_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    ) = 0;

    //! Handler for command CS_STEP
    /* Perform one step in a command sequence. Valid only if CmdSequencer is in MANUAL run mode. */
    virtual void CS_STEP_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    ) = 0;

    //! Handler for command CS_AUTO
    /* Set the run mode to AUTO. */
    virtual void CS_AUTO_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    ) = 0;

    //! Handler for command CS_MANUAL
    /* Set the run mode to MANUAL. */
    virtual void CS_MANUAL_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    ) = 0;

    //! Handler for command CS_JOIN_WAIT
    /* Wait for sequences that are running to finish. Allow user to run multiple seq files in SEQ_NO_BLOCK mode then wait for them to finish before allowing more seq run request. */
    virtual void CS_JOIN_WAIT_cmdHandler(
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

    //! Pre-message hook for command CS_RUN
    //!
    virtual void CS_RUN_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command CS_VALIDATE
    //!
    virtual void CS_VALIDATE_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command CS_CANCEL
    //!
    virtual void CS_CANCEL_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command CS_START
    //!
    virtual void CS_START_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command CS_STEP
    //!
    virtual void CS_STEP_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command CS_AUTO
    //!
    virtual void CS_AUTO_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command CS_MANUAL
    //!
    virtual void CS_MANUAL_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command CS_JOIN_WAIT
    //!
    virtual void CS_JOIN_WAIT_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handler base-class functions.
    // Call these functions directly to bypass the command input port.
    // ----------------------------------------------------------------------

    //! Base-class handler function for command CS_RUN
    //!
    void CS_RUN_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command CS_VALIDATE
    //!
    void CS_VALIDATE_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command CS_CANCEL
    //!
    void CS_CANCEL_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command CS_START
    //!
    void CS_START_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command CS_STEP
    //!
    void CS_STEP_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command CS_AUTO
    //!
    void CS_AUTO_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command CS_MANUAL
    //!
    void CS_MANUAL_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command CS_JOIN_WAIT
    //!
    void CS_JOIN_WAIT_cmdHandlerBase(
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
      EVENTID_CS_SEQUENCELOADED = 0x0, /* Sequence file was successfully loaded. */
      EVENTID_CS_SEQUENCECANCELED = 0x1, /* A command sequence was successfully canceled. */
      EVENTID_CS_FILEREADERROR = 0x2, /* The Sequence File Loader could not read the sequence file. */
      EVENTID_CS_FILEINVALID = 0x3, /* The sequence file format was invalid. */
      EVENTID_CS_RECORDINVALID = 0x4, /* The format of a command record was invalid. */
      EVENTID_CS_FILESIZEERROR = 0x5, /* The sequence file was too large. */
      EVENTID_CS_FILENOTFOUND = 0x6, /* The sequence file was not found */
      EVENTID_CS_FILECRCFAILURE = 0x7, /* The sequence file validation failed */
      EVENTID_CS_COMMANDCOMPLETE = 0x8, /* The Command Sequencer issued a command and received a success status in return. */
      EVENTID_CS_SEQUENCECOMPLETE = 0x9, /* A command sequence successfully completed. */
      EVENTID_CS_COMMANDERROR = 0xA, /* The Command Sequencer issued a command and received an error status in return. */
      EVENTID_CS_INVALIDMODE = 0xB, /* The Command Sequencer received a command that was invalid for its current mode. */
      EVENTID_CS_RECORDMISMATCH = 0xC, /* Number of records in header doesn't match number in file */
      EVENTID_CS_TIMEBASEMISMATCH = 0xD, /* The running time base doesn't match the time base in the sequence files */
      EVENTID_CS_TIMECONTEXTMISMATCH = 0xE, /* The running time base doesn't match the time base in the sequence files */
      EVENTID_CS_PORTSEQUENCESTARTED = 0xF, /* A local port request to run a sequence was started */
      EVENTID_CS_UNEXPECTEDCOMPLETION = 0x10, /* A command status came back when no sequence was running */
      EVENTID_CS_MODESWITCHED = 0x11, /* Switched step mode */
      EVENTID_CS_NOSEQUENCEACTIVE = 0x12, /* A sequence related command came with no active sequence */
      EVENTID_CS_SEQUENCEVALID = 0x13, /* A sequence passed validation */
      EVENTID_CS_SEQUENCETIMEOUT = 0x14, /* A sequence passed validation */
      EVENTID_CS_CMDSTEPPED = 0x15, /* A command in a sequence was stepped through */
      EVENTID_CS_CMDSTARTED = 0x16, /* A manual sequence was started */
      EVENTID_CS_JOINWAITING = 0x17, /* Wait for the current running sequence file complete */
      EVENTID_CS_JOINWAITINGNOTCOMPLETE = 0x18, /* Cannot run new sequence when current sequence file is still running. */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event CS_SequenceLoaded
    //!
    /* Sequence file was successfully loaded. */
    void log_ACTIVITY_LO_CS_SequenceLoaded(
        const Fw::LogStringArg& fileName /*!< The name of the sequence file*/
    );


    //! Log event CS_SequenceCanceled
    //!
    /* A command sequence was successfully canceled. */
    void log_ACTIVITY_HI_CS_SequenceCanceled(
        const Fw::LogStringArg& fileName /*!< The name of the sequence file*/
    );


    //! Log event CS_FileReadError
    //!
    /* The Sequence File Loader could not read the sequence file. */
    void log_WARNING_HI_CS_FileReadError(
        const Fw::LogStringArg& fileName /*!< The name of the sequence file*/
    );


    //! Log event CS_FileInvalid
    //!
    /* The sequence file format was invalid. */
    void log_WARNING_HI_CS_FileInvalid(
        const Fw::LogStringArg& fileName, /*!< The name of the sequence file*/
        Svc::CmdSequencer_FileReadStage stage, /*!< The read stage*/
        I32 error /*!< The error code*/
    );


    //! Log event CS_RecordInvalid
    //!
    /* The format of a command record was invalid. */
    void log_WARNING_HI_CS_RecordInvalid(
        const Fw::LogStringArg& fileName, /*!< The name of the sequence file*/
        U32 recordNumber, /*!< The record number*/
        I32 error /*!< The error code*/
    );


    //! Log event CS_FileSizeError
    //!
    /* The sequence file was too large. */
    void log_WARNING_HI_CS_FileSizeError(
        const Fw::LogStringArg& fileName, /*!< The name of the sequence file*/
        U32 size /*!< Invalid size*/
    );


    //! Log event CS_FileNotFound
    //!
    /* The sequence file was not found */
    void log_WARNING_HI_CS_FileNotFound(
        const Fw::LogStringArg& fileName /*!< The sequence file*/
    );


    //! Log event CS_FileCrcFailure
    //!
    /* The sequence file validation failed */
    void log_WARNING_HI_CS_FileCrcFailure(
        const Fw::LogStringArg& fileName, /*!< The sequence file*/
        U32 storedCRC, /*!< The CRC stored in the file*/
        U32 computedCRC /*!< The CRC computed over the file*/
    );


    //! Log event CS_CommandComplete
    //!
    /* The Command Sequencer issued a command and received a success status in return. */
    void log_ACTIVITY_LO_CS_CommandComplete(
        const Fw::LogStringArg& fileName, /*!< The name of the sequence file*/
        U32 recordNumber, /*!< The record number of the command*/
        U32 opCode /*!< The command opcode*/
    );


    //! Log event CS_SequenceComplete
    //!
    /* A command sequence successfully completed. */
    void log_ACTIVITY_HI_CS_SequenceComplete(
        const Fw::LogStringArg& fileName /*!< The name of the sequence file*/
    );


    //! Log event CS_CommandError
    //!
    /* The Command Sequencer issued a command and received an error status in return. */
    void log_WARNING_HI_CS_CommandError(
        const Fw::LogStringArg& fileName, /*!< The name of the sequence file*/
        U32 recordNumber, /*!< The record number*/
        U32 opCode, /*!< The opcode*/
        U32 errorStatus /*!< The error status*/
    );


    //! Log event CS_InvalidMode
    //!
    /* The Command Sequencer received a command that was invalid for its current mode. */
    void log_WARNING_HI_CS_InvalidMode(

    );


    //! Log event CS_RecordMismatch
    //!
    /* Number of records in header doesn't match number in file */
    void log_WARNING_HI_CS_RecordMismatch(
        const Fw::LogStringArg& fileName, /*!< The name of the sequence file*/
        U32 header_records, /*!< The number of records in the header*/
        U32 extra_bytes /*!< The number of bytes beyond last record*/
    );


    //! Log event CS_TimeBaseMismatch
    //!
    /* The running time base doesn't match the time base in the sequence files */
    void log_WARNING_HI_CS_TimeBaseMismatch(
        const Fw::LogStringArg& fileName, /*!< The name of the sequence file*/
        U16 time_base, /*!< The current time*/
        U16 seq_time_base /*!< The sequence time base*/
    );


    //! Log event CS_TimeContextMismatch
    //!
    /* The running time base doesn't match the time base in the sequence files */
    void log_WARNING_HI_CS_TimeContextMismatch(
        const Fw::LogStringArg& fileName, /*!< The name of the sequence file*/
        U8 currTimeBase, /*!< The current time base*/
        U8 seqTimeBase /*!< The sequence time base*/
    );


    //! Log event CS_PortSequenceStarted
    //!
    /* A local port request to run a sequence was started */
    void log_ACTIVITY_HI_CS_PortSequenceStarted(
        const Fw::LogStringArg& filename /*!< The sequence file*/
    );


    //! Log event CS_UnexpectedCompletion
    //!
    /* A command status came back when no sequence was running */
    void log_WARNING_HI_CS_UnexpectedCompletion(
        U32 opcode /*!< The reported opcode*/
    );


    //! Log event CS_ModeSwitched
    //!
    /* Switched step mode */
    void log_ACTIVITY_HI_CS_ModeSwitched(
        Svc::CmdSequencer_SeqMode mode /*!< The new mode*/
    );


    //! Log event CS_NoSequenceActive
    //!
    /* A sequence related command came with no active sequence */
    void log_WARNING_LO_CS_NoSequenceActive(

    );


    //! Log event CS_SequenceValid
    //!
    /* A sequence passed validation */
    void log_ACTIVITY_HI_CS_SequenceValid(
        const Fw::LogStringArg& filename /*!< The sequence file*/
    );


    //! Log event CS_SequenceTimeout
    //!
    /* A sequence passed validation */
    void log_WARNING_HI_CS_SequenceTimeout(
        const Fw::LogStringArg& filename, /*!< The sequence file*/
        U32 command /*!< The command that timed out*/
    );


    //! Log event CS_CmdStepped
    //!
    /* A command in a sequence was stepped through */
    void log_ACTIVITY_HI_CS_CmdStepped(
        const Fw::LogStringArg& filename, /*!< The sequence file*/
        U32 command /*!< The command that was stepped*/
    );


    //! Log event CS_CmdStarted
    //!
    /* A manual sequence was started */
    void log_ACTIVITY_HI_CS_CmdStarted(
        const Fw::LogStringArg& filename /*!< The sequence file*/
    );


    //! Log event CS_JoinWaiting
    //!
    /* Wait for the current running sequence file complete */
    void log_ACTIVITY_HI_CS_JoinWaiting(
        const Fw::LogStringArg& filename, /*!< The sequence file*/
        U32 recordNumber, /*!< The record number*/
        U32 opCode /*!< The opcode*/
    );


    //! Log event CS_JoinWaitingNotComplete
    //!
    /* Cannot run new sequence when current sequence file is still running. */
    void log_WARNING_HI_CS_JoinWaitingNotComplete(

    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_CS_LOADCOMMANDS = 0x0, //!< Channel ID for CS_LoadCommands
      CHANNELID_CS_CANCELCOMMANDS = 0x1, //!< Channel ID for CS_CancelCommands
      CHANNELID_CS_ERRORS = 0x2, //!< Channel ID for CS_Errors
      CHANNELID_CS_COMMANDSEXECUTED = 0x3, //!< Channel ID for CS_CommandsExecuted
      CHANNELID_CS_SEQUENCESCOMPLETED = 0x4, //!< Channel ID for CS_SequencesCompleted
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel CS_LoadCommands
    //!
    /* The number of Load commands executed */
    void tlmWrite_CS_LoadCommands(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CS_CancelCommands
    //!
    /* The number of Cancel commands executed */
    void tlmWrite_CS_CancelCommands(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CS_Errors
    //!
    /* The number of errors that have occurred */
    void tlmWrite_CS_Errors(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CS_CommandsExecuted
    //!
    /* The number of commands executed across all sequences. */
    void tlmWrite_CS_CommandsExecuted(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CS_SequencesCompleted
    //!
    /* The number of sequences completed. */
    void tlmWrite_CS_SequencesCompleted(
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

    //! Input port cmdResponseIn
    //!
    Fw::InputCmdResponsePort m_cmdResponseIn_InputPort[NUM_CMDRESPONSEIN_INPUT_PORTS];

    //! Input port pingIn
    //!
    Svc::InputPingPort m_pingIn_InputPort[NUM_PINGIN_INPUT_PORTS];

    //! Input port schedIn
    //!
    Svc::InputSchedPort m_schedIn_InputPort[NUM_SCHEDIN_INPUT_PORTS];

    //! Input port seqCancelIn
    //!
    Svc::InputCmdSeqCancelPort m_seqCancelIn_InputPort[NUM_SEQCANCELIN_INPUT_PORTS];

    //! Input port seqRunIn
    //!
    Svc::InputCmdSeqInPort m_seqRunIn_InputPort[NUM_SEQRUNIN_INPUT_PORTS];

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

    //! Output port comCmdOut
    //!
    Fw::OutputComPort m_comCmdOut_OutputPort[NUM_COMCMDOUT_OUTPUT_PORTS];

    //! Output port logOut
    //!
    Fw::OutputLogPort m_logOut_OutputPort[NUM_LOGOUT_OUTPUT_PORTS];

    //! Output port pingOut
    //!
    Svc::OutputPingPort m_pingOut_OutputPort[NUM_PINGOUT_OUTPUT_PORTS];

    //! Output port seqDone
    //!
    Fw::OutputCmdResponsePort m_seqDone_OutputPort[NUM_SEQDONE_OUTPUT_PORTS];

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

    //! Callback for port cmdResponseIn
    //!
    static void m_p_cmdResponseIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
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

    //! Callback for port pingIn
    //!
    static void m_p_pingIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 key /*!< 
      Value to return to pinger
      */
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

    //! Callback for port seqCancelIn
    //!
    static void m_p_seqCancelIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Callback for port seqRunIn
    //!
    static void m_p_seqRunIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::String &filename /*!< 
      The sequence file
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
