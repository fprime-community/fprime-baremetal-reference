// ======================================================================
// \title  ComQueueComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for ComQueue component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/ComQueue/ComQueueComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Anonymous namespace to prevent name collisions
  // ----------------------------------------------------------------------

  namespace {

    typedef enum {
      COMQUEUE_COMPONENT_EXIT = Fw::ActiveComponentBase::ACTIVE_COMPONENT_EXIT,
      BUFFQUEUEIN_BUFFERSEND,
      COMQUEUEIN_COM,
      COMSTATUSIN_SUCCESSCONDITION,
      RUN_SCHED
    } MsgTypeEnum;

    // Get the max size by doing a union of the input port serialization sizes.

    typedef union {
      BYTE port1[Fw::InputBufferSendPort::SERIALIZED_SIZE];
      BYTE port2[Fw::InputComPort::SERIALIZED_SIZE];
      BYTE port3[Fw::InputSuccessConditionPort::SERIALIZED_SIZE];
      BYTE port4[Svc::InputSchedPort::SERIALIZED_SIZE];
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

  Fw::InputBufferSendPort *ComQueueComponentBase ::
    get_buffQueueIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_buffQueueIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_buffQueueIn_InputPort[portNum];
  }

  Fw::InputComPort *ComQueueComponentBase ::
    get_comQueueIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_comQueueIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_comQueueIn_InputPort[portNum];
  }

  Fw::InputSuccessConditionPort *ComQueueComponentBase ::
    get_comStatusIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_comStatusIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_comStatusIn_InputPort[portNum];
  }

  Svc::InputSchedPort *ComQueueComponentBase ::
    get_run_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_run_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_run_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void ComQueueComponentBase ::
    set_Log_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Log_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_Log_OutputPort[portNum].addCallPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void ComQueueComponentBase ::
    set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogTextPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_LogText_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_LogText_OutputPort[portNum].addCallPort(port);
  }
#endif

  void ComQueueComponentBase ::
    set_Time_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_Time_OutputPort[portNum].addCallPort(port);
  }

  void ComQueueComponentBase ::
    set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTlmPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Tlm_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_Tlm_OutputPort[portNum].addCallPort(port);
  }

  void ComQueueComponentBase ::
    set_buffQueueSend_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_buffQueueSend_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_buffQueueSend_OutputPort[portNum].addCallPort(port);
  }

  void ComQueueComponentBase ::
    set_comQueueSend_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputComPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_comQueueSend_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_comQueueSend_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void ComQueueComponentBase ::
    set_Log_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Log_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_Log_OutputPort[portNum].registerSerialPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void ComQueueComponentBase ::
    set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_LogText_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_LogText_OutputPort[portNum].registerSerialPort(port);
  }
#endif

  void ComQueueComponentBase ::
    set_Time_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_Time_OutputPort[portNum].registerSerialPort(port);
  }

  void ComQueueComponentBase ::
    set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Tlm_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_Tlm_OutputPort[portNum].registerSerialPort(port);
  }

  void ComQueueComponentBase ::
    set_buffQueueSend_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_buffQueueSend_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_buffQueueSend_OutputPort[portNum].registerSerialPort(port);
  }

  void ComQueueComponentBase ::
    set_comQueueSend_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_comQueueSend_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_comQueueSend_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    ComQueueComponentBase :: ComQueueComponentBase(const char* compName) :
        Fw::ActiveComponentBase(compName) {



  }

  void ComQueueComponentBase ::
    init(
        NATIVE_INT_TYPE queueDepth,
        NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class
    Fw::ActiveComponentBase::init(instance);

    // Connect input port buffQueueIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_buffQueueIn_InputPorts());
        port++
    ) {

      this->m_buffQueueIn_InputPort[port].init();
      this->m_buffQueueIn_InputPort[port].addCallComp(
          this,
          m_p_buffQueueIn_in
      );
      this->m_buffQueueIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_buffQueueIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_buffQueueIn_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port comQueueIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_comQueueIn_InputPorts());
        port++
    ) {

      this->m_comQueueIn_InputPort[port].init();
      this->m_comQueueIn_InputPort[port].addCallComp(
          this,
          m_p_comQueueIn_in
      );
      this->m_comQueueIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_comQueueIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_comQueueIn_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port comStatusIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_comStatusIn_InputPorts());
        port++
    ) {

      this->m_comStatusIn_InputPort[port].init();
      this->m_comStatusIn_InputPort[port].addCallComp(
          this,
          m_p_comStatusIn_in
      );
      this->m_comStatusIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_comStatusIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_comStatusIn_InputPort[port].setObjName(portName);
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

    // Initialize output port buffQueueSend
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_buffQueueSend_OutputPorts());
        port++
    ) {
      this->m_buffQueueSend_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_buffQueueSend_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_buffQueueSend_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port comQueueSend
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_comQueueSend_OutputPorts());
        port++
    ) {
      this->m_comQueueSend_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_comQueueSend_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_comQueueSend_OutputPort[port].setObjName(portName);
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

  ComQueueComponentBase::
    ~ComQueueComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void ComQueueComponentBase ::
    buffQueueSend_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_buffQueueSend_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_buffQueueSend_OutputPort[portNum].invoke(fwBuffer);
  }

  void ComQueueComponentBase ::
    comQueueSend_out(
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {
    FW_ASSERT(portNum < this->getNum_comQueueSend_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_comQueueSend_OutputPort[portNum].invoke(data, context);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE ComQueueComponentBase ::
    getNum_Log_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_Log_OutputPort));
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE ComQueueComponentBase ::
    getNum_LogText_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_LogText_OutputPort));
  }
#endif

  NATIVE_INT_TYPE ComQueueComponentBase ::
    getNum_Time_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_Time_OutputPort));
  }

  NATIVE_INT_TYPE ComQueueComponentBase ::
    getNum_Tlm_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_Tlm_OutputPort));
  }

  NATIVE_INT_TYPE ComQueueComponentBase ::
    getNum_buffQueueIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_buffQueueIn_InputPort));
  }

  NATIVE_INT_TYPE ComQueueComponentBase ::
    getNum_buffQueueSend_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_buffQueueSend_OutputPort));
  }

  NATIVE_INT_TYPE ComQueueComponentBase ::
    getNum_comQueueIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_comQueueIn_InputPort));
  }

  NATIVE_INT_TYPE ComQueueComponentBase ::
    getNum_comQueueSend_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_comQueueSend_OutputPort));
  }

  NATIVE_INT_TYPE ComQueueComponentBase ::
    getNum_comStatusIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_comStatusIn_InputPort));
  }

  NATIVE_INT_TYPE ComQueueComponentBase ::
    getNum_run_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_run_InputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool ComQueueComponentBase ::
    isConnected_Log_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Log_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_Log_OutputPort[portNum].isConnected();
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  bool ComQueueComponentBase ::
    isConnected_LogText_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_LogText_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_LogText_OutputPort[portNum].isConnected();
  }
#endif

  bool ComQueueComponentBase ::
    isConnected_Time_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Time_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_Time_OutputPort[portNum].isConnected();
  }

  bool ComQueueComponentBase ::
    isConnected_Tlm_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Tlm_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_Tlm_OutputPort[portNum].isConnected();
  }

  bool ComQueueComponentBase ::
    isConnected_buffQueueSend_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_buffQueueSend_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_buffQueueSend_OutputPort[portNum].isConnected();
  }

  bool ComQueueComponentBase ::
    isConnected_comQueueSend_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_comQueueSend_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_comQueueSend_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Telemetry write functions
  // ----------------------------------------------------------------------

  void ComQueueComponentBase ::
    tlmWrite_comQueueDepth(const Svc::ComQueueDepth& arg, Fw::Time _tlmTime)
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

      _id = this->getIdBase() + CHANNELID_COMQUEUEDEPTH;

      this->m_Tlm_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void ComQueueComponentBase ::
    tlmWrite_buffQueueDepth(const Svc::BuffQueueDepth& arg, Fw::Time _tlmTime)
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

      _id = this->getIdBase() + CHANNELID_BUFFQUEUEDEPTH;

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

  Fw::Time ComQueueComponentBase ::
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

  void ComQueueComponentBase ::
    log_WARNING_HI_QueueOverflow(
        Svc::QueueType queueType, U32 index
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_Time_OutputPort[0].isConnected()) {
       this->m_Time_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_QUEUEOVERFLOW;

    // Emit the event on the log port
    if (this->m_Log_OutputPort[0].isConnected()) {

      Fw::LogBuffer _logBuff;
      Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

#if FW_AMPCS_COMPATIBLE
      // Serialize the number of arguments
      _status = _logBuff.serialize(static_cast<U8>(2));
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
      _status = _logBuff.serialize(queueType);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );

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
      _status = _logBuff.serialize(index);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );


      this->m_Log_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::WARNING_HI,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_LogText_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: The %s queue at index %u overflowed";
#else
      const char* _formatString =
        "%s: The %s queue at index %u overflowed";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      Fw::String queueTypeStr;
      queueType.toString(queueTypeStr);
      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "QueueOverflow "
        , queueTypeStr.toChar()
        , index
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_LogText_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::WARNING_HI,
          _logString
      );

    }
#endif

  }


  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void ComQueueComponentBase ::
    m_p_buffQueueIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(callComp);
    ComQueueComponentBase* compPtr = static_cast<ComQueueComponentBase*>(callComp);
    compPtr->buffQueueIn_handlerBase(portNum, fwBuffer);
  }

  void ComQueueComponentBase ::
    m_p_comQueueIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {
    FW_ASSERT(callComp);
    ComQueueComponentBase* compPtr = static_cast<ComQueueComponentBase*>(callComp);
    compPtr->comQueueIn_handlerBase(portNum, data, context);
  }

  void ComQueueComponentBase ::
    m_p_comStatusIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Success &condition
    )
  {
    FW_ASSERT(callComp);
    ComQueueComponentBase* compPtr = static_cast<ComQueueComponentBase*>(callComp);
    compPtr->comStatusIn_handlerBase(portNum, condition);
  }

  void ComQueueComponentBase ::
    m_p_run_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(callComp);
    ComQueueComponentBase* compPtr = static_cast<ComQueueComponentBase*>(callComp);
    compPtr->run_handlerBase(portNum, context);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void ComQueueComponentBase ::
    buffQueueIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_buffQueueIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Call pre-message hook
    buffQueueIn_preMsgHook(
        portNum,
        fwBuffer
    );

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    _status = msg.serialize(
        static_cast<NATIVE_INT_TYPE>(BUFFQUEUEIN_BUFFERSEND)
    );
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(portNum);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    // Serialize argument fwBuffer
    _status = msg.serialize(fwBuffer);
    FW_ASSERT(
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );


    // send message
    Os::Queue::QueueBlocking _block =
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 0,_block);
    if (qStatus == Os::Queue::QUEUE_FULL) {
        this->incNumMsgDropped();
        return;
    }
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
    );

  }

  void ComQueueComponentBase ::
    comQueueIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_comQueueIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Call pre-message hook
    comQueueIn_preMsgHook(
        portNum,
        data, context
    );

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    _status = msg.serialize(
        static_cast<NATIVE_INT_TYPE>(COMQUEUEIN_COM)
    );
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(portNum);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    // Serialize argument data
    _status = msg.serialize(data);
    FW_ASSERT(
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    // Serialize argument context
    _status = msg.serialize(context);
    FW_ASSERT(
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );


    // send message
    Os::Queue::QueueBlocking _block =
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 0,_block);
    if (qStatus == Os::Queue::QUEUE_FULL) {
        this->incNumMsgDropped();
        return;
    }
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
    );

  }

  void ComQueueComponentBase ::
    comStatusIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Success &condition
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_comStatusIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Call pre-message hook
    comStatusIn_preMsgHook(
        portNum,
        condition
    );

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    _status = msg.serialize(
        static_cast<NATIVE_INT_TYPE>(COMSTATUSIN_SUCCESSCONDITION)
    );
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(portNum);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    // Serialize argument condition
    _status = msg.serialize(condition);
    FW_ASSERT(
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

  void ComQueueComponentBase ::
    run_handlerBase(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_run_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Call pre-message hook
    run_preMsgHook(
        portNum,
        context
    );

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    _status = msg.serialize(
        static_cast<NATIVE_INT_TYPE>(RUN_SCHED)
    );
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(portNum);
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );

    // Serialize argument context
    _status = msg.serialize(context);
    FW_ASSERT(
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(_status)
    );


    // send message
    Os::Queue::QueueBlocking _block =
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 0,_block);
    if (qStatus == Os::Queue::QUEUE_FULL) {
        this->incNumMsgDropped();
        return;
    }
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
    );

  }

  // ----------------------------------------------------------------------
  // Pre-message hooks for async input ports
  // ----------------------------------------------------------------------

  void ComQueueComponentBase ::
    buffQueueIn_preMsgHook(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    // Default: no-op
  }

  void ComQueueComponentBase ::
    comQueueIn_preMsgHook(
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {
    // Default: no-op
  }

  void ComQueueComponentBase ::
    comStatusIn_preMsgHook(
        NATIVE_INT_TYPE portNum,
        Fw::Success &condition
    )
  {
    // Default: no-op
  }

  void ComQueueComponentBase ::
    run_preMsgHook(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // Default: no-op
  }

  // ----------------------------------------------------------------------
  // Message dispatch method for active and queued components. Called
  // by active component thread or implementation code for queued components
  // ----------------------------------------------------------------------

  Fw::QueuedComponentBase::MsgDispatchStatus ComQueueComponentBase ::
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

    if (msgType == COMQUEUE_COMPONENT_EXIT) {
      return MSG_DISPATCH_EXIT;
    }

    NATIVE_INT_TYPE portNum = 0;
    deserStatus = msg.deserialize(portNum);
    FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(deserStatus)
    );

    switch (msgType) {

      // Handle async input port buffQueueIn
      case BUFFQUEUEIN_BUFFERSEND: {

        // Deserialize argument fwBuffer
        Fw::Buffer fwBuffer;
        deserStatus = msg.deserialize(fwBuffer);
        FW_ASSERT(
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Call handler function
        this->buffQueueIn_handler(
            portNum,
            fwBuffer
        );

        break;

      }

      // Handle async input port comQueueIn
      case COMQUEUEIN_COM: {

        // Deserialize argument data
        Fw::ComBuffer data;
        deserStatus = msg.deserialize(data);
        FW_ASSERT(
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Deserialize argument context
        U32 context;
        deserStatus = msg.deserialize(context);
        FW_ASSERT(
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Call handler function
        this->comQueueIn_handler(
            portNum,
            data, context
        );

        break;

      }

      // Handle async input port comStatusIn
      case COMSTATUSIN_SUCCESSCONDITION: {

        // Deserialize argument condition
        Fw::Success condition;
        deserStatus = msg.deserialize(condition);
        FW_ASSERT(
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Call handler function
        this->comStatusIn_handler(
            portNum,
            condition
        );

        break;

      }

      // Handle async input port run
      case RUN_SCHED: {

        // Deserialize argument context
        NATIVE_UINT_TYPE context;
        deserStatus = msg.deserialize(context);
        FW_ASSERT(
            deserStatus == Fw::FW_SERIALIZE_OK,
            static_cast<FwAssertArgType>(deserStatus)
        );

        // Call handler function
        this->run_handler(
            portNum,
            context
        );

        break;

      }

      default:
        return MSG_DISPATCH_ERROR;

    }

    return MSG_DISPATCH_OK;

  }

} // end namespace Svc
