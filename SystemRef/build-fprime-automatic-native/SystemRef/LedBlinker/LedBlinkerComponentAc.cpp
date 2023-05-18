// ======================================================================
// \title  LedBlinkerComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for LedBlinker component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <SystemRef/LedBlinker/LedBlinkerComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace SystemRef {

  // ----------------------------------------------------------------------
  // Anonymous namespace to prevent name collisions
  // ----------------------------------------------------------------------

  namespace {

    typedef enum {
      LEDBLINKER_COMPONENT_EXIT = Fw::ActiveComponentBase::ACTIVE_COMPONENT_EXIT,
      CMD_BLINKING_ON_OFF
    } MsgTypeEnum;

    // Get the max size by doing a union of the input port serialization sizes.

    typedef union {
      BYTE cmdPort[Fw::InputCmdPort::SERIALIZED_SIZE];
    } BuffUnion;

    // Define a message buffer class large enough to handle all the
    // asynchronous inputs to the component

    class ComponentIpcSerializableBuffer :
      public Fw::SerializeBufferBase
    {

      public:

        enum {
          // Max. message size = size of data + message id + port
          SERIALIZATION_SIZE =
            sizeof(BuffUnion) +
            sizeof(NATIVE_INT_TYPE) +
            sizeof(NATIVE_INT_TYPE)
        };

        NATIVE_UINT_TYPE getBuffCapacity() const {
          return sizeof(m_buff);
        }

        U8* getBuffAddr() {
          return m_buff;
        }

        const U8* getBuffAddr() const {
          return m_buff;
        }

      private:
        // Should be the max of all the input ports serialized sizes...
        U8 m_buff[SERIALIZATION_SIZE];

    };

  }

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputCmdPort *LedBlinkerComponentBase ::
    get_cmdIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_cmdIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_cmdIn_InputPort[portNum];
  }

  Svc::InputSchedPort *LedBlinkerComponentBase ::
    get_run_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_run_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_run_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void LedBlinkerComponentBase ::
    set_cmdRegOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputCmdRegPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_cmdRegOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_cmdRegOut_OutputPort[portNum].addCallPort(port);
  }

  void LedBlinkerComponentBase ::
    set_cmdResponseOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputCmdResponsePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_cmdResponseOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_cmdResponseOut_OutputPort[portNum].addCallPort(port);
  }

  void LedBlinkerComponentBase ::
    set_gpioSet_OutputPort(
        NATIVE_INT_TYPE portNum,
        Drv::InputGpioWritePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_gpioSet_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_gpioSet_OutputPort[portNum].addCallPort(port);
  }

  void LedBlinkerComponentBase ::
    set_logOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_logOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_logOut_OutputPort[portNum].addCallPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void LedBlinkerComponentBase ::
    set_logTextOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogTextPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_logTextOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_logTextOut_OutputPort[portNum].addCallPort(port);
  }
#endif

  void LedBlinkerComponentBase ::
    set_prmGetOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputPrmGetPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_prmGetOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_prmGetOut_OutputPort[portNum].addCallPort(port);
  }

  void LedBlinkerComponentBase ::
    set_prmSetOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputPrmSetPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_prmSetOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_prmSetOut_OutputPort[portNum].addCallPort(port);
  }

  void LedBlinkerComponentBase ::
    set_timeCaller_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeCaller_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_timeCaller_OutputPort[portNum].addCallPort(port);
  }

  void LedBlinkerComponentBase ::
    set_tlmOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTlmPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_tlmOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_tlmOut_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void LedBlinkerComponentBase ::
    set_cmdRegOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_cmdRegOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_cmdRegOut_OutputPort[portNum].registerSerialPort(port);
  }

  void LedBlinkerComponentBase ::
    set_cmdResponseOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_cmdResponseOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_cmdResponseOut_OutputPort[portNum].registerSerialPort(port);
  }

  void LedBlinkerComponentBase ::
    set_gpioSet_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_gpioSet_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_gpioSet_OutputPort[portNum].registerSerialPort(port);
  }

  void LedBlinkerComponentBase ::
    set_logOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_logOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_logOut_OutputPort[portNum].registerSerialPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void LedBlinkerComponentBase ::
    set_logTextOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_logTextOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_logTextOut_OutputPort[portNum].registerSerialPort(port);
  }
#endif

  void LedBlinkerComponentBase ::
    set_prmGetOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_prmGetOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_prmGetOut_OutputPort[portNum].registerSerialPort(port);
  }

  void LedBlinkerComponentBase ::
    set_prmSetOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_prmSetOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_prmSetOut_OutputPort[portNum].registerSerialPort(port);
  }

  void LedBlinkerComponentBase ::
    set_timeCaller_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeCaller_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_timeCaller_OutputPort[portNum].registerSerialPort(port);
  }

  void LedBlinkerComponentBase ::
    set_tlmOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_tlmOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_tlmOut_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Command registration
  // ----------------------------------------------------------------------

  void LedBlinkerComponentBase ::
    regCommands()
  {
    FW_ASSERT(this->m_cmdRegOut_OutputPort[0].isConnected());
    this->m_cmdRegOut_OutputPort[0].invoke(
        this->getIdBase() + OPCODE_BLINKING_ON_OFF
    );
    this->m_cmdRegOut_OutputPort[0].invoke(
        this->getIdBase() + OPCODE_BLINK_INTERVAL_SET
    );
    this->m_cmdRegOut_OutputPort[0].invoke(
        this->getIdBase() + OPCODE_BLINK_INTERVAL_SAVE
    );
  }

  // ----------------------------------------------------------------------
  // Parameter loading
  // ----------------------------------------------------------------------

  void LedBlinkerComponentBase::loadParameters() {

    Fw::ParamBuffer buff;
    Fw::SerializeStatus stat = Fw::FW_SERIALIZE_OK;
    FW_ASSERT(this->m_prmGetOut_OutputPort[0].isConnected());

    FwPrmIdType _id;
    // choose parameter ID to get
    _id = this->getIdBase() + PARAMID_BLINK_INTERVAL;
    // Get parameter BLINK_INTERVAL
    this->m_param_BLINK_INTERVAL_valid =
      this->m_prmGetOut_OutputPort[0].invoke(
          _id,
          buff
      );

    // Deserialize value
    this->m_paramLock.lock();

    if (this->m_param_BLINK_INTERVAL_valid == Fw::ParamValid::VALID) {
      stat = buff.deserialize(this->m_BLINK_INTERVAL);
      // If there was a deserialization issue, mark it invalid.
      if (stat != Fw::FW_SERIALIZE_OK) {
        this->m_param_BLINK_INTERVAL_valid = Fw::ParamValid::INVALID;
      }
    }
    else {
      // No default
    }

    this->m_paramLock.unLock();

    // Call notifier
    this->parametersLoaded();
  }

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    LedBlinkerComponentBase :: LedBlinkerComponentBase(const char* compName) :
        Fw::ActiveComponentBase(compName) {



    this->m_param_BLINK_INTERVAL_valid = Fw::ParamValid::UNINIT;
  }

  void LedBlinkerComponentBase ::
    init(
        NATIVE_INT_TYPE queueDepth,
        NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class
    Fw::ActiveComponentBase::init(instance);

    // Connect input port cmdIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_cmdIn_InputPorts());
        port++
    ) {

      this->m_cmdIn_InputPort[port].init();
      this->m_cmdIn_InputPort[port].addCallComp(
          this,
          m_p_cmdIn_in
      );
      this->m_cmdIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_cmdIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_cmdIn_InputPort[port].setObjName(portName);
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

    // Initialize output port cmdRegOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_cmdRegOut_OutputPorts());
        port++
    ) {
      this->m_cmdRegOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_cmdRegOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_cmdRegOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port cmdResponseOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_cmdResponseOut_OutputPorts());
        port++
    ) {
      this->m_cmdResponseOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_cmdResponseOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_cmdResponseOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port gpioSet
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_gpioSet_OutputPorts());
        port++
    ) {
      this->m_gpioSet_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_gpioSet_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_gpioSet_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port logOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_logOut_OutputPorts());
        port++
    ) {
      this->m_logOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_logOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_logOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port logTextOut
#if FW_ENABLE_TEXT_LOGGING == 1
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_logTextOut_OutputPorts());
        port++
    ) {
      this->m_logTextOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_logTextOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_logTextOut_OutputPort[port].setObjName(portName);
#endif

    }
#endif

    // Initialize output port prmGetOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_prmGetOut_OutputPorts());
        port++
    ) {
      this->m_prmGetOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_prmGetOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_prmGetOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port prmSetOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_prmSetOut_OutputPorts());
        port++
    ) {
      this->m_prmSetOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_prmSetOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_prmSetOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port timeCaller
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_timeCaller_OutputPorts());
        port++
    ) {
      this->m_timeCaller_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_timeCaller_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_timeCaller_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port tlmOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_tlmOut_OutputPorts());
        port++
    ) {
      this->m_tlmOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_tlmOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_tlmOut_OutputPort[port].setObjName(portName);
#endif

    }

    Os::Queue::QueueStatus qStat =
    this->createQueue(
        queueDepth,
        ComponentIpcSerializableBuffer::SERIALIZATION_SIZE
    );
    FW_ASSERT(
        Os::Queue::QUEUE_OK == qStat,
        static_cast<FwAssertArgType>(qStat)
    );

  }

  LedBlinkerComponentBase::
    ~LedBlinkerComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void LedBlinkerComponentBase ::
    gpioSet_out(
        NATIVE_INT_TYPE portNum,
        const Fw::Logic &state
    )
  {
    FW_ASSERT(portNum < this->getNum_gpioSet_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_gpioSet_OutputPort[portNum].invoke(state);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE LedBlinkerComponentBase ::
    getNum_cmdIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_cmdIn_InputPort));
  }

  NATIVE_INT_TYPE LedBlinkerComponentBase ::
    getNum_cmdRegOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_cmdRegOut_OutputPort));
  }

  NATIVE_INT_TYPE LedBlinkerComponentBase ::
    getNum_cmdResponseOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_cmdResponseOut_OutputPort));
  }

  NATIVE_INT_TYPE LedBlinkerComponentBase ::
    getNum_gpioSet_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_gpioSet_OutputPort));
  }

  NATIVE_INT_TYPE LedBlinkerComponentBase ::
    getNum_logOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_logOut_OutputPort));
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE LedBlinkerComponentBase ::
    getNum_logTextOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_logTextOut_OutputPort));
  }
#endif

  NATIVE_INT_TYPE LedBlinkerComponentBase ::
    getNum_prmGetOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_prmGetOut_OutputPort));
  }

  NATIVE_INT_TYPE LedBlinkerComponentBase ::
    getNum_prmSetOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_prmSetOut_OutputPort));
  }

  NATIVE_INT_TYPE LedBlinkerComponentBase ::
    getNum_run_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_run_InputPort));
  }

  NATIVE_INT_TYPE LedBlinkerComponentBase ::
    getNum_timeCaller_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_timeCaller_OutputPort));
  }

  NATIVE_INT_TYPE LedBlinkerComponentBase ::
    getNum_tlmOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_tlmOut_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool LedBlinkerComponentBase ::
    isConnected_cmdRegOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_cmdRegOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_cmdRegOut_OutputPort[portNum].isConnected();
  }

  bool LedBlinkerComponentBase ::
    isConnected_cmdResponseOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_cmdResponseOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_cmdResponseOut_OutputPort[portNum].isConnected();
  }

  bool LedBlinkerComponentBase ::
    isConnected_gpioSet_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_gpioSet_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_gpioSet_OutputPort[portNum].isConnected();
  }

  bool LedBlinkerComponentBase ::
    isConnected_logOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_logOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_logOut_OutputPort[portNum].isConnected();
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  bool LedBlinkerComponentBase ::
    isConnected_logTextOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_logTextOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_logTextOut_OutputPort[portNum].isConnected();
  }
#endif

  bool LedBlinkerComponentBase ::
    isConnected_prmGetOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_prmGetOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_prmGetOut_OutputPort[portNum].isConnected();
  }

  bool LedBlinkerComponentBase ::
    isConnected_prmSetOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_prmSetOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_prmSetOut_OutputPort[portNum].isConnected();
  }

  bool LedBlinkerComponentBase ::
    isConnected_timeCaller_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_timeCaller_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_timeCaller_OutputPort[portNum].isConnected();
  }

  bool LedBlinkerComponentBase ::
    isConnected_tlmOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_tlmOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_tlmOut_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Calls for messages received on command input ports
  // ----------------------------------------------------------------------

  void LedBlinkerComponentBase ::
    m_p_cmdIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdArgBuffer &args
    )
  {

    // Select base class function based on opcode
    FW_ASSERT(callComp);
    LedBlinkerComponentBase* compPtr = static_cast<LedBlinkerComponentBase*>(callComp);

    const U32 idBase = callComp->getIdBase();
    FW_ASSERT(opCode >= idBase, opCode, idBase);
    switch (opCode - idBase) {

      case OPCODE_BLINKING_ON_OFF: /*!< Command to turn on or off the blinking LED */
        compPtr->BLINKING_ON_OFF_cmdHandlerBase(
            opCode,
            cmdSeq,
            args
        );
        break;

      case OPCODE_BLINK_INTERVAL_SET:
      {
        Fw::CmdResponse _cstat = compPtr->paramSet_BLINK_INTERVAL(args);
        compPtr->cmdResponse_out(
            opCode,
            cmdSeq,
            _cstat
        );
        break;
      }
      case OPCODE_BLINK_INTERVAL_SAVE:
      {
        Fw::CmdResponse _cstat = compPtr->paramSave_BLINK_INTERVAL();
        compPtr->cmdResponse_out(
            opCode,
            cmdSeq,
            _cstat
        );
        break;
      }
      default: {
        compPtr->cmdResponse_out(
            opCode,cmdSeq,
            Fw::CmdResponse::INVALID_OPCODE
        );
        break;
      }

    }

  }

  void LedBlinkerComponentBase ::
    cmdResponse_out(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdResponse response
    )
  {
    FW_ASSERT(this->m_cmdResponseOut_OutputPort[0].isConnected());
    this->m_cmdResponseOut_OutputPort[0].invoke(opCode,cmdSeq,response);
  }

  // ----------------------------------------------------------------------
  // Base class command functions
  // ----------------------------------------------------------------------

  void LedBlinkerComponentBase ::
    BLINKING_ON_OFF_cmdHandlerBase(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdArgBuffer &args
    )
  {

    // Call pre-message hook
    this->BLINKING_ON_OFF_preMsgHook(opCode,cmdSeq);

    // Defer deserializing arguments to the message dispatcher
    // to avoid deserializing and reserializing just for IPC
    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Serialize for IPC
    _status = msg.serialize(static_cast<NATIVE_INT_TYPE>(CMD_BLINKING_ON_OFF));
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
        );

    // Fake port number to make message dequeue work
    NATIVE_INT_TYPE port = 0;
    _status = msg.serialize(port);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(opCode);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(cmdSeq);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(args);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    // send message
    Os::Queue::QueueBlocking _block =
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 0,_block);
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
    );

  }

  void LedBlinkerComponentBase::
    BLINKING_ON_OFF_preMsgHook(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // Defaults to no-op; can be overridden
  }

  // ----------------------------------------------------------------------
  // Telemetry write functions
  // ----------------------------------------------------------------------

  void LedBlinkerComponentBase ::
    tlmWrite_BlinkingState(const Fw::On& arg, Fw::Time _tlmTime)
  {
    if (this->m_tlmOut_OutputPort[0].isConnected()) {
      if (this->m_timeCaller_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_timeCaller_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_BLINKINGSTATE;

      this->m_tlmOut_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void LedBlinkerComponentBase ::
    tlmWrite_LedTransitions(U64 arg, Fw::Time _tlmTime)
  {
    if (this->m_tlmOut_OutputPort[0].isConnected()) {
      if (this->m_timeCaller_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_timeCaller_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_LEDTRANSITIONS;

      this->m_tlmOut_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  Fw::Time LedBlinkerComponentBase ::
    getTime()
  {
    if (this->m_timeCaller_OutputPort[0].isConnected()) {
      Fw::Time _time;
      this->m_timeCaller_OutputPort[0].invoke(_time);
      return _time;
    } else {
      return Fw::Time(TB_NONE,0,0);
    }
  }

  // ----------------------------------------------------------------------
  // Parameter update hook
  // ----------------------------------------------------------------------

  void LedBlinkerComponentBase ::
    parameterUpdated(FwPrmIdType id)
  {
    // Do nothing by default
  }

  // ----------------------------------------------------------------------
  // Parameter load hook
  // ----------------------------------------------------------------------

  void LedBlinkerComponentBase ::
    parametersLoaded()
  {
    // Do nothing by default
  }

  // ----------------------------------------------------------------------
  // Protected parameter get functions
  // ----------------------------------------------------------------------

  U32 LedBlinkerComponentBase ::
    paramGet_BLINK_INTERVAL(Fw::ParamValid& valid)
  {
    U32 _local;
    this->m_paramLock.lock();
    valid = this->m_param_BLINK_INTERVAL_valid;
    _local = this->m_BLINK_INTERVAL;
    this->m_paramLock.unLock();
    return _local;
  }

  // ----------------------------------------------------------------------
  // Private parameter get function
  // ----------------------------------------------------------------------

  Fw::ParamValid LedBlinkerComponentBase ::
    getParam(
      FwPrmIdType id,
      Fw::ParamBuffer& buff
    )
  {
    if (this->m_prmGetOut_OutputPort[0].isConnected()) {
      return this->m_prmGetOut_OutputPort[0].invoke(id,buff);
    } else {
      return Fw::ParamValid::INVALID;
    }

  }

  // ----------------------------------------------------------------------
  // Parameter set functions
  // ----------------------------------------------------------------------

  Fw::CmdResponse LedBlinkerComponentBase ::
    paramSet_BLINK_INTERVAL(Fw::SerializeBufferBase &val)
  {

    U32 _local_val;
    Fw::SerializeStatus _stat = val.deserialize(_local_val);
    if (_stat != Fw::FW_SERIALIZE_OK) {
      return Fw::CmdResponse::VALIDATION_ERROR;
    }

    // Assign value only if successfully deserialized
    this->m_paramLock.lock();
    this->m_BLINK_INTERVAL = _local_val;
    this->m_param_BLINK_INTERVAL_valid = Fw::ParamValid::VALID;
    this->m_paramLock.unLock();

    // Call notifier
    this->parameterUpdated(PARAMID_BLINK_INTERVAL);
    return Fw::CmdResponse::OK;

  }

  // ----------------------------------------------------------------------
  // Parameter save functions
  // ----------------------------------------------------------------------

  Fw::CmdResponse LedBlinkerComponentBase ::
    paramSave_BLINK_INTERVAL()
  {

    if (this->m_prmSetOut_OutputPort[0].isConnected()) {
      Fw::ParamBuffer saveBuff;
      this->m_paramLock.lock();

      Fw::SerializeStatus stat =
        saveBuff.serialize(m_BLINK_INTERVAL);
      this->m_paramLock.unLock();
      if (stat != Fw::FW_SERIALIZE_OK) {
        return Fw::CmdResponse::VALIDATION_ERROR;
      }

      FwPrmIdType id = 0;
      id = this->getIdBase() + PARAMID_BLINK_INTERVAL;
      // Save the parameter
      this->m_prmSetOut_OutputPort[0].invoke(
          id,
          saveBuff
      );
      return Fw::CmdResponse::OK;

    }

    return Fw::CmdResponse::EXECUTION_ERROR;

  }

  // ----------------------------------------------------------------------
  // Event handling functions
  // ----------------------------------------------------------------------

  void LedBlinkerComponentBase ::
    log_WARNING_LO_InvalidBlinkArgument(
        Fw::On badArgument
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_timeCaller_OutputPort[0].isConnected()) {
       this->m_timeCaller_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_INVALIDBLINKARGUMENT;

    // Emit the event on the log port
    if (this->m_logOut_OutputPort[0].isConnected()) {

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

#if FW_AMPCS_COMPATIBLE
      // Serialize the argument size
      _status = _logBuff.serialize(
          static_cast<U8>(sizeof())
      );
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif
      _status = _logBuff.serialize(badArgument);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );


      this->m_logOut_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::WARNING_LO,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_logTextOut_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: Invalid Blinking Argument: %s";
#else
      const char* _formatString =
        "%s: Invalid Blinking Argument: %s";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      Fw::String badArgumentStr;
      badArgument.toString(badArgumentStr);
      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "InvalidBlinkArgument "
        , badArgumentStr.toChar()
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_logTextOut_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::WARNING_LO,
          _logString
      );

    }
#endif

  }


  void LedBlinkerComponentBase ::
    log_ACTIVITY_HI_SetBlinkingState(
        Fw::On state
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_timeCaller_OutputPort[0].isConnected()) {
       this->m_timeCaller_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_SETBLINKINGSTATE;

    // Emit the event on the log port
    if (this->m_logOut_OutputPort[0].isConnected()) {

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

#if FW_AMPCS_COMPATIBLE
      // Serialize the argument size
      _status = _logBuff.serialize(
          static_cast<U8>(sizeof())
      );
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif
      _status = _logBuff.serialize(state);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );


      this->m_logOut_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_HI,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_logTextOut_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: Set blinking state to %s.";
#else
      const char* _formatString =
        "%s: Set blinking state to %s.";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      Fw::String stateStr;
      state.toString(stateStr);
      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "SetBlinkingState "
        , stateStr.toChar()
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_logTextOut_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_HI,
          _logString
      );

    }
#endif

  }


  void LedBlinkerComponentBase ::
    log_ACTIVITY_LO_LedState(
        Fw::On on_off
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_timeCaller_OutputPort[0].isConnected()) {
       this->m_timeCaller_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_LEDSTATE;

    // Emit the event on the log port
    if (this->m_logOut_OutputPort[0].isConnected()) {

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

#if FW_AMPCS_COMPATIBLE
      // Serialize the argument size
      _status = _logBuff.serialize(
          static_cast<U8>(sizeof())
      );
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif
      _status = _logBuff.serialize(on_off);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );


      this->m_logOut_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_LO,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_logTextOut_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: LED is %s";
#else
      const char* _formatString =
        "%s: LED is %s";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      Fw::String on_offStr;
      on_off.toString(on_offStr);
      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "LedState "
        , on_offStr.toChar()
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_logTextOut_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_LO,
          _logString
      );

    }
#endif

  }


  void LedBlinkerComponentBase ::
    log_ACTIVITY_HI_BlinkIntervalSet(
        U32 interval
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_timeCaller_OutputPort[0].isConnected()) {
       this->m_timeCaller_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_BLINKINTERVALSET;

    // Emit the event on the log port
    if (this->m_logOut_OutputPort[0].isConnected()) {

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

#if FW_AMPCS_COMPATIBLE
      // Serialize the argument size
      _status = _logBuff.serialize(
          static_cast<U8>(sizeof())
      );
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );
#endif
      _status = _logBuff.serialize(interval);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );


      this->m_logOut_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_HI,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_logTextOut_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: LED blink interval set to %u";
#else
      const char* _formatString =
        "%s: LED blink interval set to %u";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "BlinkIntervalSet "
        , interval
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_logTextOut_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_HI,
          _logString
      );

    }
#endif

  }


  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void LedBlinkerComponentBase ::
    m_p_run_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(callComp);
    LedBlinkerComponentBase* compPtr = static_cast<LedBlinkerComponentBase*>(callComp);
    compPtr->run_handlerBase(portNum, context);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void LedBlinkerComponentBase ::
    run_handlerBase(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_run_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->run_handler(portNum, context);

  }

  // ----------------------------------------------------------------------
  // Message dispatch method for active and queued components. Called
  // by active component thread or implementation code for queued components
  // ----------------------------------------------------------------------

  Fw::QueuedComponentBase::MsgDispatchStatus LedBlinkerComponentBase ::
    doDispatch()
  {
    ComponentIpcSerializableBuffer msg;
    NATIVE_INT_TYPE priority = 0;

    Os::Queue::QueueStatus msgStatus = this->m_queue.receive(msg,priority,Os::Queue::QUEUE_BLOCKING);
    FW_ASSERT(
        msgStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(msgStatus)
    );

    // Reset to beginning of buffer
    msg.resetDeser();

    NATIVE_INT_TYPE desMsg = 0;
    Fw::SerializeStatus deserStatus = msg.deserialize(desMsg);
    FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(deserStatus)
    );

    MsgTypeEnum msgType = static_cast<MsgTypeEnum>(desMsg);

    if (msgType == LEDBLINKER_COMPONENT_EXIT) {
      return MSG_DISPATCH_EXIT;
    }

    NATIVE_INT_TYPE portNum = 0;
    deserStatus = msg.deserialize(portNum);
    FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(deserStatus)
    );

    switch (msgType) {

      // Handle command BLINKING_ON_OFF
      case CMD_BLINKING_ON_OFF: {
        // Deserialize opcode
        FwOpcodeType opCode = 0;
        deserStatus = msg.deserialize(opCode);
        FW_ASSERT (
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Deserialize command sequence
        U32 cmdSeq = 0;
        deserStatus = msg.deserialize(cmdSeq);
        FW_ASSERT (
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Deserialize command argument buffer
        Fw::CmdArgBuffer args;
        deserStatus = msg.deserialize(args);
        FW_ASSERT (
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Reset buffer
        args.resetDeser();

        // Deserialize argument on_off
        Fw::On on_off;
        deserStatus = args.deserialize(on_off);
        if (deserStatus != Fw::FW_SERIALIZE_OK) {
          if (this->m_cmdResponseOut_OutputPort[0].isConnected()) {
            this->cmdResponse_out(
                opCode,
                cmdSeq,
                Fw::CmdResponse::FORMAT_ERROR
            );
          }
          // Don't crash the task if bad arguments were passed from the ground
          break;
        }

        // Make sure there was no data left over.
        // That means the argument buffer size was incorrect.
#if FW_CMD_CHECK_RESIDUAL
        if (args.getBuffLeft() != 0) {
          if (this->m_cmdResponseOut_OutputPort[0].isConnected()) {
            this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::FORMAT_ERROR);
          }
          // Don't crash the task if bad arguments were passed from the ground
          break;
        }
#endif
        // Call handler function
        this->BLINKING_ON_OFF_cmdHandler(
            opCode,
            cmdSeq,
            on_off
        );

        break;

      }

      default:
        return MSG_DISPATCH_ERROR;

    }

    return MSG_DISPATCH_OK;

  }

} // end namespace SystemRef
