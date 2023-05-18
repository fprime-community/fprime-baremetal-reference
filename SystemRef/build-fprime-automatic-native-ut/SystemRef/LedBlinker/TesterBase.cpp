// ======================================================================
// \title  LedBlinker/test/ut/TesterBase.cpp
// \author Auto-generated
// \brief  cpp file for LedBlinker component test harness base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdlib>
#include <cstring>
#include "TesterBase.hpp"

namespace SystemRef {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  LedBlinkerTesterBase ::
    LedBlinkerTesterBase(
        const char *const compName,
        const U32 maxHistorySize
    ) :
      Fw::PassiveComponentBase(compName)
  {
    // Initialize command history
    this->cmdResponseHistory = new History<CmdResponse>(maxHistorySize);
    // Initialize telemetry histories
    this->tlmHistory_BlinkingState =
      new History<TlmEntry_BlinkingState>(maxHistorySize);
    this->tlmHistory_LedTransitions =
      new History<TlmEntry_LedTransitions>(maxHistorySize);
    // Initialize event histories
#if FW_ENABLE_TEXT_LOGGING
    this->textLogHistory = new History<TextLogEntry>(maxHistorySize);
#endif
    this->eventHistory_InvalidBlinkArgument =
      new History<EventEntry_InvalidBlinkArgument>(maxHistorySize);
    this->eventHistory_SetBlinkingState =
      new History<EventEntry_SetBlinkingState>(maxHistorySize);
    this->eventHistory_LedState =
      new History<EventEntry_LedState>(maxHistorySize);
    this->eventHistory_BlinkIntervalSet =
      new History<EventEntry_BlinkIntervalSet>(maxHistorySize);
    // Initialize histories for typed user output ports
    this->fromPortHistory_gpioSet =
      new History<FromPortEntry_gpioSet>(maxHistorySize);
    // Clear history
    this->clearHistory();
  }

  LedBlinkerTesterBase ::
    ~LedBlinkerTesterBase()
  {
    // Destroy command history
    delete this->cmdResponseHistory;
    // Destroy telemetry histories
    delete this->tlmHistory_BlinkingState;
    delete this->tlmHistory_LedTransitions;
    // Destroy event histories
#if FW_ENABLE_TEXT_LOGGING
    delete this->textLogHistory;
#endif
    delete this->eventHistory_InvalidBlinkArgument;
    delete this->eventHistory_SetBlinkingState;
    delete this->eventHistory_LedState;
    delete this->eventHistory_BlinkIntervalSet;
    // Destroy port histories
    delete this->fromPortHistory_gpioSet;
  }

  void LedBlinkerTesterBase ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    this->m_param_BLINK_INTERVAL_valid = Fw::ParamValid::UNINIT;

    // Initialize base class

		Fw::PassiveComponentBase::init(instance);

    // Attach input port cmdRegOut

    for (
        PlatformIntType _port = 0;
        _port < static_cast<PlatformIntType>(this->getNum_from_cmdRegOut());
        ++_port
    ) {

      this->m_from_cmdRegOut[_port].init();
      this->m_from_cmdRegOut[_port].addCallComp(
          this,
          from_cmdRegOut_static
      );
      this->m_from_cmdRegOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_cmdRegOut[%" PRI_PlatformIntType "]",
          this->m_objName,
          _port
      );
      this->m_from_cmdRegOut[_port].setObjName(_portName);
#endif

    }

    // Attach input port cmdResponseOut

    for (
        PlatformIntType _port = 0;
        _port < static_cast<PlatformIntType>(this->getNum_from_cmdResponseOut());
        ++_port
    ) {

      this->m_from_cmdResponseOut[_port].init();
      this->m_from_cmdResponseOut[_port].addCallComp(
          this,
          from_cmdResponseOut_static
      );
      this->m_from_cmdResponseOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_cmdResponseOut[%" PRI_PlatformIntType "]",
          this->m_objName,
          _port
      );
      this->m_from_cmdResponseOut[_port].setObjName(_portName);
#endif

    }

    // Attach input port gpioSet

    for (
        PlatformIntType _port = 0;
        _port < static_cast<PlatformIntType>(this->getNum_from_gpioSet());
        ++_port
    ) {

      this->m_from_gpioSet[_port].init();
      this->m_from_gpioSet[_port].addCallComp(
          this,
          from_gpioSet_static
      );
      this->m_from_gpioSet[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_gpioSet[%" PRI_PlatformIntType "]",
          this->m_objName,
          _port
      );
      this->m_from_gpioSet[_port].setObjName(_portName);
#endif

    }

    // Attach input port logOut

    for (
        PlatformIntType _port = 0;
        _port < static_cast<PlatformIntType>(this->getNum_from_logOut());
        ++_port
    ) {

      this->m_from_logOut[_port].init();
      this->m_from_logOut[_port].addCallComp(
          this,
          from_logOut_static
      );
      this->m_from_logOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_logOut[%" PRI_PlatformIntType "]",
          this->m_objName,
          _port
      );
      this->m_from_logOut[_port].setObjName(_portName);
#endif

    }

    // Attach input port logTextOut

#if FW_ENABLE_TEXT_LOGGING == 1
    for (
        PlatformIntType _port = 0;
        _port < static_cast<PlatformIntType>(this->getNum_from_logTextOut());
        ++_port
    ) {

      this->m_from_logTextOut[_port].init();
      this->m_from_logTextOut[_port].addCallComp(
          this,
          from_logTextOut_static
      );
      this->m_from_logTextOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_logTextOut[%" PRI_PlatformIntType "]",
          this->m_objName,
          _port
      );
      this->m_from_logTextOut[_port].setObjName(_portName);
#endif

    }
#endif

    // Attach input port prmGetOut

    for (
        PlatformIntType _port = 0;
        _port < static_cast<PlatformIntType>(this->getNum_from_prmGetOut());
        ++_port
    ) {

      this->m_from_prmGetOut[_port].init();
      this->m_from_prmGetOut[_port].addCallComp(
          this,
          from_prmGetOut_static
      );
      this->m_from_prmGetOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_prmGetOut[%" PRI_PlatformIntType "]",
          this->m_objName,
          _port
      );
      this->m_from_prmGetOut[_port].setObjName(_portName);
#endif

    }

    // Attach input port prmSetOut

    for (
        PlatformIntType _port = 0;
        _port < static_cast<PlatformIntType>(this->getNum_from_prmSetOut());
        ++_port
    ) {

      this->m_from_prmSetOut[_port].init();
      this->m_from_prmSetOut[_port].addCallComp(
          this,
          from_prmSetOut_static
      );
      this->m_from_prmSetOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_prmSetOut[%" PRI_PlatformIntType "]",
          this->m_objName,
          _port
      );
      this->m_from_prmSetOut[_port].setObjName(_portName);
#endif

    }

    // Attach input port timeCaller

    for (
        PlatformIntType _port = 0;
        _port < static_cast<PlatformIntType>(this->getNum_from_timeCaller());
        ++_port
    ) {

      this->m_from_timeCaller[_port].init();
      this->m_from_timeCaller[_port].addCallComp(
          this,
          from_timeCaller_static
      );
      this->m_from_timeCaller[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_timeCaller[%" PRI_PlatformIntType "]",
          this->m_objName,
          _port
      );
      this->m_from_timeCaller[_port].setObjName(_portName);
#endif

    }

    // Attach input port tlmOut

    for (
        PlatformIntType _port = 0;
        _port < static_cast<PlatformIntType>(this->getNum_from_tlmOut());
        ++_port
    ) {

      this->m_from_tlmOut[_port].init();
      this->m_from_tlmOut[_port].addCallComp(
          this,
          from_tlmOut_static
      );
      this->m_from_tlmOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_tlmOut[%" PRI_PlatformIntType "]",
          this->m_objName,
          _port
      );
      this->m_from_tlmOut[_port].setObjName(_portName);
#endif

    }

    // Initialize output port run

    for (
        PlatformIntType _port = 0;
        _port < static_cast<PlatformIntType>(this->getNum_to_run());
        ++_port
    ) {
      this->m_to_run[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_run[%" PRI_PlatformIntType "]",
          this->m_objName,
          _port
      );
      this->m_to_run[_port].setObjName(_portName);
#endif

    }

  }

  // ----------------------------------------------------------------------
  // Getters for port counts
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE LedBlinkerTesterBase ::
    getNum_to_cmdIn() const
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_to_cmdIn));
  }

  NATIVE_INT_TYPE LedBlinkerTesterBase ::
    getNum_from_cmdRegOut() const
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_cmdRegOut));
  }

  NATIVE_INT_TYPE LedBlinkerTesterBase ::
    getNum_from_cmdResponseOut() const
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_cmdResponseOut));
  }

  NATIVE_INT_TYPE LedBlinkerTesterBase ::
    getNum_from_gpioSet() const
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_gpioSet));
  }

  NATIVE_INT_TYPE LedBlinkerTesterBase ::
    getNum_from_logOut() const
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_logOut));
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE LedBlinkerTesterBase ::
    getNum_from_logTextOut() const
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_logTextOut));
  }
#endif

  NATIVE_INT_TYPE LedBlinkerTesterBase ::
    getNum_from_prmGetOut() const
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_prmGetOut));
  }

  NATIVE_INT_TYPE LedBlinkerTesterBase ::
    getNum_from_prmSetOut() const
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_prmSetOut));
  }

  NATIVE_INT_TYPE LedBlinkerTesterBase ::
    getNum_to_run() const
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_to_run));
  }

  NATIVE_INT_TYPE LedBlinkerTesterBase ::
    getNum_from_timeCaller() const
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_timeCaller));
  }

  NATIVE_INT_TYPE LedBlinkerTesterBase ::
    getNum_from_tlmOut() const
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_tlmOut));
  }

  // ----------------------------------------------------------------------
  // Connectors for to ports
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    connect_to_cmdIn(
        const NATIVE_INT_TYPE portNum,
        Fw::InputCmdPort *const cmdIn
    )
  {
    FW_ASSERT(portNum < this->getNum_to_cmdIn(),static_cast<FwAssertArgType>(portNum));
    this->m_to_cmdIn[portNum].addCallPort(cmdIn);
  }

  void LedBlinkerTesterBase ::
    connect_to_run(
        const NATIVE_INT_TYPE portNum,
        Svc::InputSchedPort *const run
    )
  {
    FW_ASSERT(portNum < this->getNum_to_run(),static_cast<FwAssertArgType>(portNum));
    this->m_to_run[portNum].addCallPort(run);
  }


  // ----------------------------------------------------------------------
  // Invocation functions for to ports
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    invoke_to_run(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(portNum < this->getNum_to_run(),static_cast<FwAssertArgType>(portNum));
    FW_ASSERT(portNum < this->getNum_to_run(),static_cast<FwAssertArgType>(portNum));
    this->m_to_run[portNum].invoke(
        context
    );
  }

  // ----------------------------------------------------------------------
  // Connection status for to ports
  // ----------------------------------------------------------------------

  bool LedBlinkerTesterBase ::
    isConnected_to_cmdIn(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_cmdIn(), static_cast<FwAssertArgType>(portNum));
    return this->m_to_cmdIn[portNum].isConnected();
  }

  bool LedBlinkerTesterBase ::
    isConnected_to_run(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_run(), static_cast<FwAssertArgType>(portNum));
    return this->m_to_run[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Getters for from ports
  // ----------------------------------------------------------------------

  Fw::InputCmdRegPort *LedBlinkerTesterBase ::
    get_from_cmdRegOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_cmdRegOut(),static_cast<FwAssertArgType>(portNum));
    return &this->m_from_cmdRegOut[portNum];
  }

  Fw::InputCmdResponsePort *LedBlinkerTesterBase ::
    get_from_cmdResponseOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_cmdResponseOut(),static_cast<FwAssertArgType>(portNum));
    return &this->m_from_cmdResponseOut[portNum];
  }

  Drv::InputGpioWritePort *LedBlinkerTesterBase ::
    get_from_gpioSet(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_gpioSet(),static_cast<FwAssertArgType>(portNum));
    return &this->m_from_gpioSet[portNum];
  }

  Fw::InputLogPort *LedBlinkerTesterBase ::
    get_from_logOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_logOut(),static_cast<FwAssertArgType>(portNum));
    return &this->m_from_logOut[portNum];
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  Fw::InputLogTextPort *LedBlinkerTesterBase ::
    get_from_logTextOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_logTextOut(),static_cast<FwAssertArgType>(portNum));
    return &this->m_from_logTextOut[portNum];
  }
#endif

  Fw::InputPrmGetPort *LedBlinkerTesterBase ::
    get_from_prmGetOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_prmGetOut(),static_cast<FwAssertArgType>(portNum));
    return &this->m_from_prmGetOut[portNum];
  }

  Fw::InputPrmSetPort *LedBlinkerTesterBase ::
    get_from_prmSetOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_prmSetOut(),static_cast<FwAssertArgType>(portNum));
    return &this->m_from_prmSetOut[portNum];
  }

  Fw::InputTimePort *LedBlinkerTesterBase ::
    get_from_timeCaller(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_timeCaller(),static_cast<FwAssertArgType>(portNum));
    return &this->m_from_timeCaller[portNum];
  }

  Fw::InputTlmPort *LedBlinkerTesterBase ::
    get_from_tlmOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_tlmOut(),static_cast<FwAssertArgType>(portNum));
    return &this->m_from_tlmOut[portNum];
  }

  // ----------------------------------------------------------------------
  // Static functions for from ports
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    from_gpioSet_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        const Fw::Logic &state
    )
  {
    FW_ASSERT(callComp);
    LedBlinkerTesterBase* _testerBase =
      static_cast<LedBlinkerTesterBase*>(callComp);
    _testerBase->from_gpioSet_handlerBase(
        portNum,
        state
    );
  }

  void LedBlinkerTesterBase ::
    from_cmdResponseOut_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CmdResponse &response
    )
  {
    LedBlinkerTesterBase* _testerBase =
      static_cast<LedBlinkerTesterBase*>(component);
    _testerBase->cmdResponseIn(opCode, cmdSeq, response);
  }

  void LedBlinkerTesterBase ::
    from_cmdRegOut_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        const FwOpcodeType opCode
    )
  {

  }

  void LedBlinkerTesterBase ::
    from_tlmOut_static(
        Fw::PassiveComponentBase *const component,
        NATIVE_INT_TYPE portNum,
        FwChanIdType id,
        Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {
    LedBlinkerTesterBase* _testerBase =
      static_cast<LedBlinkerTesterBase*>(component);
    _testerBase->dispatchTlm(id, timeTag, val);
  }

  void LedBlinkerTesterBase ::
    from_logOut_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        const Fw::LogSeverity &severity,
        Fw::LogBuffer &args
    )
  {
    LedBlinkerTesterBase* _testerBase =
      static_cast<LedBlinkerTesterBase*>(component);
    _testerBase->dispatchEvents(id, timeTag, severity, args);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void LedBlinkerTesterBase ::
    from_logTextOut_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        const Fw::LogSeverity &severity,
        Fw::TextLogString &text
    )
  {
    LedBlinkerTesterBase* _testerBase =
      static_cast<LedBlinkerTesterBase*>(component);
    _testerBase->textLogIn(id,timeTag,severity,text);
  }
#endif

  void LedBlinkerTesterBase ::
    from_timeCaller_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        Fw::Time& time
    )
  {
    LedBlinkerTesterBase* _testerBase =
      static_cast<LedBlinkerTesterBase*>(component);
    time = _testerBase->m_testTime;
  }


  Fw::ParamValid LedBlinkerTesterBase ::
    from_prmGetOut_static(
        Fw::PassiveComponentBase* component,
        NATIVE_INT_TYPE portNum,
        FwPrmIdType id,
        Fw::ParamBuffer &val
    )
  {
    LedBlinkerTesterBase* _testerBase =
      static_cast<LedBlinkerTesterBase*>(component);

    Fw::SerializeStatus _status;
    Fw::ParamValid _ret = Fw::ParamValid::VALID;
    val.resetSer();

    const U32 idBase = _testerBase->getIdBase();
    FW_ASSERT(id >= idBase, id, idBase);

    switch (id - idBase) {
      case 0x0:
      {
        _status = val.serialize(_testerBase->m_param_BLINK_INTERVAL);
        _ret = _testerBase->m_param_BLINK_INTERVAL_valid;
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(_status)
        );
      }
        break;
      default:
        FW_ASSERT(id);
        break;
    }

    return _ret;
  }

  void LedBlinkerTesterBase ::
    from_prmSetOut_static(
        Fw::PassiveComponentBase* component,
        NATIVE_INT_TYPE portNum,
        FwPrmIdType id,
        Fw::ParamBuffer &val
    )
  {
    LedBlinkerTesterBase* _testerBase =
      static_cast<LedBlinkerTesterBase*>(component);

    Fw::SerializeStatus _status;
    val.resetDeser();

    // This is exercised completely in autocode,
    // so just verify that it works. If it doesn't
    // it probably is an autocoder error.

    const U32 idBase = _testerBase->getIdBase();
    FW_ASSERT(id >= idBase, id, idBase);

    switch (id - idBase) {
      case 0x0:
      {
        U32 BLINK_INTERVALVal;
        _status = val.deserialize(BLINK_INTERVALVal);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(_status)
        );
        FW_ASSERT(
            BLINK_INTERVALVal ==
            _testerBase->m_param_BLINK_INTERVAL
        );
        break;
      }

      default: {
        FW_ASSERT(id);
        break;
      }

    }
  }

  // ----------------------------------------------------------------------
  // Histories for typed from ports
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    clearFromPortHistory()
  {
    this->fromPortHistorySize = 0;
    this->fromPortHistory_gpioSet->clear();
  }

  // ----------------------------------------------------------------------
  // From port: gpioSet
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    pushFromPortEntry_gpioSet(
        const Fw::Logic &state
    )
  {
    FromPortEntry_gpioSet _e = {
      state
    };
    this->fromPortHistory_gpioSet->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ----------------------------------------------------------------------
  // Handler base functions for from ports
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    from_gpioSet_handlerBase(
        const NATIVE_INT_TYPE portNum,
        const Fw::Logic &state
    )
  {
    FW_ASSERT(portNum < this->getNum_from_gpioSet(),static_cast<FwAssertArgType>(portNum));
    this->from_gpioSet_handler(
        portNum,
        state
    );
  }

  // ----------------------------------------------------------------------
  // Command response handling
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    cmdResponseIn(
        const FwOpcodeType opCode,
        const U32 seq,
        const Fw::CmdResponse response
    )
  {
    CmdResponse e = { opCode, seq, response };
    this->cmdResponseHistory->push_back(e);
  }

  // ----------------------------------------------------------------------
  // Command: BLINKING_ON_OFF
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    sendCmd_BLINKING_ON_OFF(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq,
        Fw::On on_off
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;
    Fw::SerializeStatus _status;
    _status = buff.serialize(on_off);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<FwAssertArgType>(_status));

    // Call output command port

    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = LedBlinkerComponentBase::OPCODE_BLINKING_ON_OFF + idBase;

    if (this->m_to_cmdIn[0].isConnected()) {
      this->m_to_cmdIn[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }


  void LedBlinkerTesterBase ::
    sendRawCmd(FwOpcodeType opcode, U32 cmdSeq, Fw::CmdArgBuffer& args) {

    const U32 idBase = this->getIdBase();
    FwOpcodeType _opcode = opcode + idBase;
    if (this->m_to_cmdIn[0].isConnected()) {
      this->m_to_cmdIn[0].invoke(
          _opcode,
          cmdSeq,
          args
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ----------------------------------------------------------------------
  // History
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    clearHistory()
  {
    this->cmdResponseHistory->clear();
    this->clearTlm();
    this->textLogHistory->clear();
    this->clearEvents();
    this->clearFromPortHistory();
  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    setTestTime(const Fw::Time& time)
  {
    this->m_testTime = time;
  }

  // ----------------------------------------------------------------------
  // Telemetry dispatch
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    dispatchTlm(
        const FwChanIdType id,
        const Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {

    val.resetDeser();

    const U32 idBase = this->getIdBase();
    FW_ASSERT(id >= idBase, id, idBase);

    switch (id - idBase) {

      case LedBlinkerComponentBase::CHANNELID_BLINKINGSTATE:
      {
        Fw::On arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing BlinkingState: %d\n", _status);
          return;
        }
        this->tlmInput_BlinkingState(timeTag, arg);
        break;
      }

      case LedBlinkerComponentBase::CHANNELID_LEDTRANSITIONS:
      {
        U64 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing LedTransitions: %d\n", _status);
          return;
        }
        this->tlmInput_LedTransitions(timeTag, arg);
        break;
      }

      default: {
        FW_ASSERT(0, id);
        break;
      }

    }

  }

  void LedBlinkerTesterBase ::
    clearTlm()
  {
    this->tlmSize = 0;
    this->tlmHistory_BlinkingState->clear();
    this->tlmHistory_LedTransitions->clear();
  }

  // ----------------------------------------------------------------------
  // Channel: BlinkingState
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    tlmInput_BlinkingState(
        const Fw::Time& timeTag,
        const Fw::On& val
    )
  {
    TlmEntry_BlinkingState e = { timeTag, val };
    this->tlmHistory_BlinkingState->push_back(e);
    ++this->tlmSize;
  }

  // ----------------------------------------------------------------------
  // Channel: LedTransitions
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    tlmInput_LedTransitions(
        const Fw::Time& timeTag,
        const U64& val
    )
  {
    TlmEntry_LedTransitions e = { timeTag, val };
    this->tlmHistory_LedTransitions->push_back(e);
    ++this->tlmSize;
  }

  // ----------------------------------------------------------------------
  // Event dispatch
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    dispatchEvents(
        const FwEventIdType id,
        Fw::Time &timeTag,
        const Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {

    args.resetDeser();

    const U32 idBase = this->getIdBase();
    FW_ASSERT(id >= idBase, id, idBase);
    switch (id - idBase) {

      case LedBlinkerComponentBase::EVENTID_INVALIDBLINKARGUMENT:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);

#endif
        Fw::On badArgument;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(_status)
          );
          FW_ASSERT(_argSize == sizeof(Fw::On),_argSize,sizeof(Fw::On));
        }
#endif
        _status = args.deserialize(badArgument);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(_status)
        );

        this->logIn_WARNING_LO_InvalidBlinkArgument(badArgument);

        break;

      }

      case LedBlinkerComponentBase::EVENTID_SETBLINKINGSTATE:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);

#endif
        Fw::On state;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(_status)
          );
          FW_ASSERT(_argSize == sizeof(Fw::On),_argSize,sizeof(Fw::On));
        }
#endif
        _status = args.deserialize(state);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(_status)
        );

        this->logIn_ACTIVITY_HI_SetBlinkingState(state);

        break;

      }

      case LedBlinkerComponentBase::EVENTID_LEDSTATE:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);

#endif
        Fw::On on_off;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(_status)
          );
          FW_ASSERT(_argSize == sizeof(Fw::On),_argSize,sizeof(Fw::On));
        }
#endif
        _status = args.deserialize(on_off);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(_status)
        );

        this->logIn_ACTIVITY_LO_LedState(on_off);

        break;

      }

      case LedBlinkerComponentBase::EVENTID_BLINKINTERVALSET:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);

#endif
        U32 interval;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif
        _status = args.deserialize(interval);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(_status)
        );

        this->logIn_ACTIVITY_HI_BlinkIntervalSet(interval);

        break;

      }

      default: {
        FW_ASSERT(0, id);
        break;
      }

    }

  }

  void LedBlinkerTesterBase ::
    clearEvents()
  {
    this->eventsSize = 0;
    this->eventHistory_InvalidBlinkArgument->clear();
    this->eventHistory_SetBlinkingState->clear();
    this->eventHistory_LedState->clear();
    this->eventHistory_BlinkIntervalSet->clear();
  }

#if FW_ENABLE_TEXT_LOGGING

  // ----------------------------------------------------------------------
  // Text events
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    textLogIn(
        const U32 id,
        Fw::Time &timeTag,
        const Fw::LogSeverity severity,
        const Fw::TextLogString &text
    )
  {
    TextLogEntry e = { id, timeTag, severity, text };
    textLogHistory->push_back(e);
  }

  void LedBlinkerTesterBase ::
    printTextLogHistoryEntry(
        const TextLogEntry& e,
        FILE* file
    )
  {
    const char *severityString = "UNKNOWN";
    switch (e.severity.e) {
      case Fw::LogSeverity::FATAL:
        severityString = "FATAL";
        break;
      case Fw::LogSeverity::WARNING_HI:
        severityString = "WARNING_HI";
        break;
      case Fw::LogSeverity::WARNING_LO:
        severityString = "WARNING_LO";
        break;
      case Fw::LogSeverity::COMMAND:
        severityString = "COMMAND";
        break;
      case Fw::LogSeverity::ACTIVITY_HI:
        severityString = "ACTIVITY_HI";
        break;
      case Fw::LogSeverity::ACTIVITY_LO:
        severityString = "ACTIVITY_LO";
        break;
      case Fw::LogSeverity::DIAGNOSTIC:
       severityString = "DIAGNOSTIC";
        break;
      default:
        severityString = "SEVERITY ERROR";
        break;
    }

    fprintf(
        file,
        "EVENT: (%" PRI_FwEventIdType ") (%" PRI_FwTimeBaseStoreType ":%" PRIu32 ",%" PRIu32 ") %s: %s\n",
        e.id,
        static_cast<FwTimeBaseStoreType>(e.timeTag.getTimeBase()),
        e.timeTag.getSeconds(),
        e.timeTag.getUSeconds(),
        severityString,
        e.text.toChar()
    );

  }

  void LedBlinkerTesterBase ::
    printTextLogHistory(FILE *file)
  {
    for (U32 i = 0; i < this->textLogHistory->size(); ++i) {
      this->printTextLogHistoryEntry(
          this->textLogHistory->at(i),
          file
      );
    }
  }

#endif

  // ----------------------------------------------------------------------
  // Event: InvalidBlinkArgument
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    logIn_WARNING_LO_InvalidBlinkArgument(
        Fw::On badArgument
    )
  {
    EventEntry_InvalidBlinkArgument e = {
      badArgument
    };
    eventHistory_InvalidBlinkArgument->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: SetBlinkingState
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    logIn_ACTIVITY_HI_SetBlinkingState(
        Fw::On state
    )
  {
    EventEntry_SetBlinkingState e = {
      state
    };
    eventHistory_SetBlinkingState->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: LedState
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    logIn_ACTIVITY_LO_LedState(
        Fw::On on_off
    )
  {
    EventEntry_LedState e = {
      on_off
    };
    eventHistory_LedState->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: BlinkIntervalSet
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    logIn_ACTIVITY_HI_BlinkIntervalSet(
        U32 interval
    )
  {
    EventEntry_BlinkIntervalSet e = {
      interval
    };
    eventHistory_BlinkIntervalSet->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Parameter BLINK_INTERVAL
  // ----------------------------------------------------------------------

  void LedBlinkerTesterBase ::
    paramSet_BLINK_INTERVAL(
        const U32& val,
        Fw::ParamValid valid
    )
  {
    this->m_param_BLINK_INTERVAL = val;
    this->m_param_BLINK_INTERVAL_valid = valid;
  }

  void LedBlinkerTesterBase ::
    paramSend_BLINK_INTERVAL(
        NATIVE_INT_TYPE instance,
        U32 cmdSeq
    )
  {

    // Build command for parameter set

    Fw::CmdArgBuffer args;
    FW_ASSERT(
        args.serialize(
            this->m_param_BLINK_INTERVAL
        ) == Fw::FW_SERIALIZE_OK
    );
    const U32 idBase = this->getIdBase();
    FwOpcodeType _prmOpcode;
    _prmOpcode =  LedBlinkerComponentBase::OPCODE_BLINK_INTERVAL_SET + idBase;
    if (not this->m_to_cmdIn[0].isConnected()) {
      printf("Test Command Output port not connected!\n");
    }
    else {
      this->m_to_cmdIn[0].invoke(
          _prmOpcode,
          cmdSeq,
          args
      );
    }

  }

  void LedBlinkerTesterBase ::
    paramSave_BLINK_INTERVAL (
        NATIVE_INT_TYPE instance,
        U32 cmdSeq
    )

  {
    Fw::CmdArgBuffer args;
    FwOpcodeType _prmOpcode;
    const U32 idBase = this->getIdBase();
    _prmOpcode = LedBlinkerComponentBase::OPCODE_BLINK_INTERVAL_SAVE + idBase;
    if (not this->m_to_cmdIn[0].isConnected()) {
      printf("Test Command Output port not connected!\n");
    }
    else {
      this->m_to_cmdIn[0].invoke(
          _prmOpcode,
          cmdSeq,
          args
      );
    }
  }

} // end namespace SystemRef
