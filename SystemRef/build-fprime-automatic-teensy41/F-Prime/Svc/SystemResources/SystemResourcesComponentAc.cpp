// ======================================================================
// \title  SystemResourcesComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for SystemResources component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/SystemResources/SystemResourcesComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputCmdPort *SystemResourcesComponentBase ::
    get_CmdDisp_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_CmdDisp_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_CmdDisp_InputPort[portNum];
  }

  Svc::InputSchedPort *SystemResourcesComponentBase ::
    get_run_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_run_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_run_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void SystemResourcesComponentBase ::
    set_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputCmdRegPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_CmdReg_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_CmdReg_OutputPort[portNum].addCallPort(port);
  }

  void SystemResourcesComponentBase ::
    set_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputCmdResponsePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_CmdStatus_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_CmdStatus_OutputPort[portNum].addCallPort(port);
  }

  void SystemResourcesComponentBase ::
    set_Log_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Log_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_Log_OutputPort[portNum].addCallPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void SystemResourcesComponentBase ::
    set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogTextPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_LogText_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_LogText_OutputPort[portNum].addCallPort(port);
  }
#endif

  void SystemResourcesComponentBase ::
    set_Time_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_Time_OutputPort[portNum].addCallPort(port);
  }

  void SystemResourcesComponentBase ::
    set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTlmPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Tlm_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_Tlm_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void SystemResourcesComponentBase ::
    set_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_CmdReg_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_CmdReg_OutputPort[portNum].registerSerialPort(port);
  }

  void SystemResourcesComponentBase ::
    set_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_CmdStatus_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_CmdStatus_OutputPort[portNum].registerSerialPort(port);
  }

  void SystemResourcesComponentBase ::
    set_Log_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Log_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_Log_OutputPort[portNum].registerSerialPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void SystemResourcesComponentBase ::
    set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_LogText_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_LogText_OutputPort[portNum].registerSerialPort(port);
  }
#endif

  void SystemResourcesComponentBase ::
    set_Time_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_Time_OutputPort[portNum].registerSerialPort(port);
  }

  void SystemResourcesComponentBase ::
    set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Tlm_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_Tlm_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Command registration
  // ----------------------------------------------------------------------

  void SystemResourcesComponentBase ::
    regCommands()
  {
    FW_ASSERT(this->m_CmdReg_OutputPort[0].isConnected());
    this->m_CmdReg_OutputPort[0].invoke(
        this->getIdBase() + OPCODE_ENABLE
    );
    this->m_CmdReg_OutputPort[0].invoke(
        this->getIdBase() + OPCODE_VERSION
    );
  }

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    SystemResourcesComponentBase :: SystemResourcesComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void SystemResourcesComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port CmdDisp
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_CmdDisp_InputPorts());
        port++
    ) {

      this->m_CmdDisp_InputPort[port].init();
      this->m_CmdDisp_InputPort[port].addCallComp(
          this,
          m_p_CmdDisp_in
      );
      this->m_CmdDisp_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_CmdDisp_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_CmdDisp_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port run
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_run_InputPorts());
        port++
    ) {

      this->m_run_InputPort[port].init();
      this->m_run_InputPort[port].addCallComp(
          this,
          m_p_run_in
      );
      this->m_run_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_run_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_run_InputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port CmdReg
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_CmdReg_OutputPorts());
        port++
    ) {
      this->m_CmdReg_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_CmdReg_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_CmdReg_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port CmdStatus
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_CmdStatus_OutputPorts());
        port++
    ) {
      this->m_CmdStatus_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_CmdStatus_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_CmdStatus_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port Log
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_Log_OutputPorts());
        port++
    ) {
      this->m_Log_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_Log_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_Log_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port LogText
#if FW_ENABLE_TEXT_LOGGING == 1
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_LogText_OutputPorts());
        port++
    ) {
      this->m_LogText_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_LogText_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_LogText_OutputPort[port].setObjName(portName);
#endif

    }
#endif

    // Initialize output port Time
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_Time_OutputPorts());
        port++
    ) {
      this->m_Time_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_Time_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_Time_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port Tlm
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_Tlm_OutputPorts());
        port++
    ) {
      this->m_Tlm_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_Tlm_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_Tlm_OutputPort[port].setObjName(portName);
#endif

    }


  }

  SystemResourcesComponentBase::
    ~SystemResourcesComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE SystemResourcesComponentBase ::
    getNum_CmdDisp_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_CmdDisp_InputPort));
  }

  NATIVE_INT_TYPE SystemResourcesComponentBase ::
    getNum_CmdReg_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_CmdReg_OutputPort));
  }

  NATIVE_INT_TYPE SystemResourcesComponentBase ::
    getNum_CmdStatus_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_CmdStatus_OutputPort));
  }

  NATIVE_INT_TYPE SystemResourcesComponentBase ::
    getNum_Log_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_Log_OutputPort));
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE SystemResourcesComponentBase ::
    getNum_LogText_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_LogText_OutputPort));
  }
#endif

  NATIVE_INT_TYPE SystemResourcesComponentBase ::
    getNum_Time_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_Time_OutputPort));
  }

  NATIVE_INT_TYPE SystemResourcesComponentBase ::
    getNum_Tlm_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_Tlm_OutputPort));
  }

  NATIVE_INT_TYPE SystemResourcesComponentBase ::
    getNum_run_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_run_InputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool SystemResourcesComponentBase ::
    isConnected_CmdReg_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_CmdReg_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_CmdReg_OutputPort[portNum].isConnected();
  }

  bool SystemResourcesComponentBase ::
    isConnected_CmdStatus_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_CmdStatus_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_CmdStatus_OutputPort[portNum].isConnected();
  }

  bool SystemResourcesComponentBase ::
    isConnected_Log_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Log_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_Log_OutputPort[portNum].isConnected();
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  bool SystemResourcesComponentBase ::
    isConnected_LogText_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_LogText_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_LogText_OutputPort[portNum].isConnected();
  }
#endif

  bool SystemResourcesComponentBase ::
    isConnected_Time_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Time_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_Time_OutputPort[portNum].isConnected();
  }

  bool SystemResourcesComponentBase ::
    isConnected_Tlm_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Tlm_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_Tlm_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Calls for messages received on command input ports
  // ----------------------------------------------------------------------

  void SystemResourcesComponentBase ::
    m_p_CmdDisp_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdArgBuffer &args
    )
  {

    // Select base class function based on opcode
    FW_ASSERT(callComp);
    SystemResourcesComponentBase* compPtr = static_cast<SystemResourcesComponentBase*>(callComp);

    const U32 idBase = callComp->getIdBase();
    FW_ASSERT(opCode >= idBase, opCode, idBase);
    switch (opCode - idBase) {

      case OPCODE_ENABLE: /*!< A command to enable or disable system resource telemetry */
        compPtr->ENABLE_cmdHandlerBase(
            opCode,
            cmdSeq,
            args
        );
        break;

      case OPCODE_VERSION: /*!< Report version as EVR */
        compPtr->VERSION_cmdHandlerBase(
            opCode,
            cmdSeq,
            args
        );
        break;

      default: {
        compPtr->cmdResponse_out(
            opCode,cmdSeq,
            Fw::CmdResponse::INVALID_OPCODE
        );
        break;
      }

    }

  }

  void SystemResourcesComponentBase ::
    cmdResponse_out(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdResponse response
    )
  {
    FW_ASSERT(this->m_CmdStatus_OutputPort[0].isConnected());
    this->m_CmdStatus_OutputPort[0].invoke(opCode,cmdSeq,response);
  }

  // ----------------------------------------------------------------------
  // Base class command functions
  // ----------------------------------------------------------------------

  void SystemResourcesComponentBase ::
    ENABLE_cmdHandlerBase(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdArgBuffer &args
    )
  {

    // Deserialize the arguments
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Reset the buffer
    args.resetDeser();

    Svc::SystemResourceEnabled enable;
    _status = args.deserialize(enable);
    if (_status != Fw::FW_SERIALIZE_OK) {
      if (this->m_CmdStatus_OutputPort[0].isConnected()) {
        this->m_CmdStatus_OutputPort[0].invoke(
            opCode,
            cmdSeq,Fw::CmdResponse::FORMAT_ERROR
        );
      }
      return;
    }

#if FW_CMD_CHECK_RESIDUAL
    // Make sure there was no data left over.
    // That means the argument buffer size was incorrect.
    if (args.getBuffLeft() != 0) {
      if (this->m_CmdStatus_OutputPort[0].isConnected()) {
        this->m_CmdStatus_OutputPort[0].invoke(
            opCode,
            cmdSeq,Fw::CmdResponse::FORMAT_ERROR
        );
      }
      return;
    }
#endif
    this->lock();
    this->ENABLE_cmdHandler(
        opCode,
        cmdSeq,
        enable
    );
    this->unLock();

  }

  void SystemResourcesComponentBase ::
    VERSION_cmdHandlerBase(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdArgBuffer &args
    )
  {

#if FW_CMD_CHECK_RESIDUAL
    // Make sure there was no data left over.
    // That means the argument buffer size was incorrect.
    if (args.getBuffLeft() != 0) {
      if (this->m_CmdStatus_OutputPort[0].isConnected()) {
        this->m_CmdStatus_OutputPort[0].invoke(
            opCode,
            cmdSeq,Fw::CmdResponse::FORMAT_ERROR
        );
      }
      return;
    }
#endif
    this->lock();
    this->VERSION_cmdHandler(opCode,cmdSeq);
    this->unLock();

  }

  // ----------------------------------------------------------------------
  // Telemetry write functions
  // ----------------------------------------------------------------------

  void SystemResourcesComponentBase ::
    tlmWrite_MEMORY_TOTAL(U64 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_MEMORY_TOTAL;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_MEMORY_USED(U64 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_MEMORY_USED;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_NON_VOLATILE_TOTAL(U64 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_NON_VOLATILE_TOTAL;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_NON_VOLATILE_FREE(U64 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_NON_VOLATILE_FREE;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_00(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_00;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_01(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_01;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_02(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_02;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_03(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_03;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_04(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_04;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_05(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_05;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_06(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_06;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_07(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_07;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_08(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_08;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_09(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_09;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_10(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_10;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_11(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_11;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_12(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_12;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_13(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_13;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_14(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_14;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_CPU_15(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_CPU_15;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_FRAMEWORK_VERSION(const Fw::TlmString& arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = arg.serialize(_tlmBuff, 40);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_FRAMEWORK_VERSION;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SystemResourcesComponentBase ::
    tlmWrite_PROJECT_VERSION(const Fw::TlmString& arg, Fw::Time _tlmTime)
  {
    if (this->m_Tlm_OutputPort[0].isConnected()) {
      if (this->m_Time_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_Time_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = arg.serialize(_tlmBuff, 40);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_PROJECT_VERSION;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  Fw::Time SystemResourcesComponentBase ::
    getTime()
  {
    if (this->m_Time_OutputPort[0].isConnected()) {
      Fw::Time _time;
      this->m_Time_OutputPort[0].invoke(_time);
      return _time;
    } else {
      return Fw::Time(TB_NONE,0,0);
    }
  }

  // ----------------------------------------------------------------------
  // Event handling functions
  // ----------------------------------------------------------------------

  void SystemResourcesComponentBase ::
    log_ACTIVITY_LO_FRAMEWORK_VERSION(
        const Fw::LogStringArg& version
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_Time_OutputPort[0].isConnected()) {
       this->m_Time_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_FRAMEWORK_VERSION;

    // Emit the event on the log port
    if (this->m_Log_OutputPort[0].isConnected()) {

      Fw::LogBuffer _logBuff;
      Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

#if FW_AMPCS_COMPATIBLE
      // Serialize the number of arguments
      _status = _logBuff.serialize(static_cast<U8>(1));
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif

      _status = version.serialize(_logBuff, 40);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );


      this->m_Log_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_LO,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_LogText_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: Framework Version: [%s]";
#else
      const char* _formatString =
        "%s: Framework Version: [%s]";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "FRAMEWORK_VERSION "
        , version.toChar()
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_LogText_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_LO,
          _logString
      );

    }
#endif

  }


  void SystemResourcesComponentBase ::
    log_ACTIVITY_LO_PROJECT_VERSION(
        const Fw::LogStringArg& version
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_Time_OutputPort[0].isConnected()) {
       this->m_Time_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_PROJECT_VERSION;

    // Emit the event on the log port
    if (this->m_Log_OutputPort[0].isConnected()) {

      Fw::LogBuffer _logBuff;
      Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

#if FW_AMPCS_COMPATIBLE
      // Serialize the number of arguments
      _status = _logBuff.serialize(static_cast<U8>(1));
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif

      _status = version.serialize(_logBuff, 40);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );


      this->m_Log_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_LO,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_LogText_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: Project Version: [%s]";
#else
      const char* _formatString =
        "%s: Project Version: [%s]";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "PROJECT_VERSION "
        , version.toChar()
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_LogText_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_LO,
          _logString
      );

    }
#endif

  }


  // ----------------------------------------------------------------------
  // Mutex functions for guarded ports
  // ----------------------------------------------------------------------

  void SystemResourcesComponentBase ::
    lock()
  {
    this->m_guardedPortMutex.lock();
  }

  void SystemResourcesComponentBase ::
    unLock()
  {
    this->m_guardedPortMutex.unLock();
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void SystemResourcesComponentBase ::
    m_p_run_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(callComp);
    SystemResourcesComponentBase* compPtr = static_cast<SystemResourcesComponentBase*>(callComp);
    compPtr->run_handlerBase(portNum, context);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void SystemResourcesComponentBase ::
    run_handlerBase(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_run_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->run_handler(portNum, context);

    // Unlock guard mutex
    this->unLock();

  }

} // end namespace Svc
