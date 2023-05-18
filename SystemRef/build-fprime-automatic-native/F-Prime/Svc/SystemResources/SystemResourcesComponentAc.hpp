// ======================================================================
// \title  SystemResourcesComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for SystemResources component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_SYSTEMRESOURCES_COMP_HPP_
#define SVC_SYSTEMRESOURCES_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Os/Mutex.hpp>
#include <Fw/Cmd/CmdString.hpp>
#include <Fw/Tlm/TlmString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Svc/SystemResources/SystemResourceEnabledEnumAc.hpp>
#include <Fw/Cmd/CmdResponseEnumAc.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
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
#include <Svc/Sched/SchedPortAc.hpp>

namespace Svc {

  //! \class SystemResourcesComponentBase
  //! \brief Auto-generated base for SystemResources component
  //!
  class SystemResourcesComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class SystemResourcesComponentBaseFriend;

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
    //! \return run[portNum]
    //!
    Svc::InputSchedPort* get_run_InputPort(
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

    //! Construct a SystemResourcesComponentBase object
    //!
    SystemResourcesComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a SystemResourcesComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a SystemResourcesComponentBase object
    //!
    virtual ~SystemResourcesComponentBase();

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
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of CmdDisp input ports
    //!
    //! \return The number of CmdDisp input ports
    //!
    NATIVE_INT_TYPE getNum_CmdDisp_InputPorts();

    //! Get the number of run input ports
    //!
    //! \return The number of run input ports
    //!
    NATIVE_INT_TYPE getNum_run_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_CMDDISP_INPUT_PORTS = 1,
       NUM_RUN_INPUT_PORTS = 1,
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


    enum {
       NUM_CMDREG_OUTPUT_PORTS = 1,
       NUM_CMDSTATUS_OUTPUT_PORTS = 1,
       NUM_LOG_OUTPUT_PORTS = 1,
       NUM_LOGTEXT_OUTPUT_PORTS = 1,
       NUM_TIME_OUTPUT_PORTS = 1,
       NUM_TLM_OUTPUT_PORTS = 1,
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

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command opcodes
    // ----------------------------------------------------------------------

    enum {
      OPCODE_ENABLE = 0x0, /* A command to enable or disable system resource telemetry */
      OPCODE_VERSION = 0x1, /* Report version as EVR */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handlers to implement
    // ----------------------------------------------------------------------

    //! Handler for command ENABLE
    /* A command to enable or disable system resource telemetry */
    virtual void ENABLE_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Svc::SystemResourceEnabled enable /*!< 
          whether or not system resource telemetry is enabled
          */
    ) = 0;

    //! Handler for command VERSION
    /* Report version as EVR */
    virtual void VERSION_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handler base-class functions.
    // Call these functions directly to bypass the command input port.
    // ----------------------------------------------------------------------

    //! Base-class handler function for command ENABLE
    //!
    void ENABLE_cmdHandlerBase(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command VERSION
    //!
    void VERSION_cmdHandlerBase(
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
      EVENTID_FRAMEWORK_VERSION = 0x0, /* Version of the git repository. */
      EVENTID_PROJECT_VERSION = 0x1, /* Version of the git repository. */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event FRAMEWORK_VERSION
    //!
    /* Version of the git repository. */
    void log_ACTIVITY_LO_FRAMEWORK_VERSION(
        const Fw::LogStringArg& version /*!< version string*/
    );


    //! Log event PROJECT_VERSION
    //!
    /* Version of the git repository. */
    void log_ACTIVITY_LO_PROJECT_VERSION(
        const Fw::LogStringArg& version /*!< version string*/
    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_MEMORY_TOTAL = 0x0, //!< Channel ID for MEMORY_TOTAL
      CHANNELID_MEMORY_USED = 0x1, //!< Channel ID for MEMORY_USED
      CHANNELID_NON_VOLATILE_TOTAL = 0x2, //!< Channel ID for NON_VOLATILE_TOTAL
      CHANNELID_NON_VOLATILE_FREE = 0x3, //!< Channel ID for NON_VOLATILE_FREE
      CHANNELID_CPU = 0x4, //!< Channel ID for CPU
      CHANNELID_CPU_00 = 0x5, //!< Channel ID for CPU_00
      CHANNELID_CPU_01 = 0x6, //!< Channel ID for CPU_01
      CHANNELID_CPU_02 = 0x7, //!< Channel ID for CPU_02
      CHANNELID_CPU_03 = 0x8, //!< Channel ID for CPU_03
      CHANNELID_CPU_04 = 0x9, //!< Channel ID for CPU_04
      CHANNELID_CPU_05 = 0xA, //!< Channel ID for CPU_05
      CHANNELID_CPU_06 = 0xB, //!< Channel ID for CPU_06
      CHANNELID_CPU_07 = 0xC, //!< Channel ID for CPU_07
      CHANNELID_CPU_08 = 0xD, //!< Channel ID for CPU_08
      CHANNELID_CPU_09 = 0xE, //!< Channel ID for CPU_09
      CHANNELID_CPU_10 = 0xF, //!< Channel ID for CPU_10
      CHANNELID_CPU_11 = 0x10, //!< Channel ID for CPU_11
      CHANNELID_CPU_12 = 0x11, //!< Channel ID for CPU_12
      CHANNELID_CPU_13 = 0x12, //!< Channel ID for CPU_13
      CHANNELID_CPU_14 = 0x13, //!< Channel ID for CPU_14
      CHANNELID_CPU_15 = 0x14, //!< Channel ID for CPU_15
      CHANNELID_FRAMEWORK_VERSION = 0x15, //!< Channel ID for FRAMEWORK_VERSION
      CHANNELID_PROJECT_VERSION = 0x16, //!< Channel ID for PROJECT_VERSION
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel MEMORY_TOTAL
    //!
    /* Total system memory in KB */
    void tlmWrite_MEMORY_TOTAL(
        U64 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel MEMORY_USED
    //!
    /* System memory used in KB */
    void tlmWrite_MEMORY_USED(
        U64 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel NON_VOLATILE_TOTAL
    //!
    /* System non-volatile available in KB */
    void tlmWrite_NON_VOLATILE_TOTAL(
        U64 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel NON_VOLATILE_FREE
    //!
    /* System non-volatile available in KB */
    void tlmWrite_NON_VOLATILE_FREE(
        U64 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_00
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_00(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_01
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_01(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_02
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_02(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_03
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_03(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_04
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_04(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_05
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_05(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_06
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_06(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_07
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_07(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_08
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_08(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_09
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_09(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_10
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_10(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_11
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_11(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_12
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_12(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_13
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_13(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_14
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_14(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel CPU_15
    //!
    /* System's CPU Percentage */
    void tlmWrite_CPU_15(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel FRAMEWORK_VERSION
    //!
    /* Software framework version */
    void tlmWrite_FRAMEWORK_VERSION(
        const Fw::TlmString& arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel PROJECT_VERSION
    //!
    /* Software project version */
    void tlmWrite_PROJECT_VERSION(
        const Fw::TlmString& arg /*!< The telemetry value*/,
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

    //! Input port CmdDisp
    //!
    Fw::InputCmdPort m_CmdDisp_InputPort[NUM_CMDDISP_INPUT_PORTS];

    //! Input port run
    //!
    Svc::InputSchedPort m_run_InputPort[NUM_RUN_INPUT_PORTS];

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
