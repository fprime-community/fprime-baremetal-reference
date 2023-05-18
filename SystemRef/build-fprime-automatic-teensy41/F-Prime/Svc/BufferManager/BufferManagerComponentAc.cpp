// ======================================================================
// \title  BufferManagerComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for BufferManager component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/BufferManager/BufferManagerComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputBufferGetPort *BufferManagerComponentBase ::
    get_bufferGetCallee_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_bufferGetCallee_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_bufferGetCallee_InputPort[portNum];
  }

  Fw::InputBufferSendPort *BufferManagerComponentBase ::
    get_bufferSendIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_bufferSendIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_bufferSendIn_InputPort[portNum];
  }

  Svc::InputSchedPort *BufferManagerComponentBase ::
    get_schedIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_schedIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_schedIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void BufferManagerComponentBase ::
    set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_eventOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_eventOut_OutputPort[portNum].addCallPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void BufferManagerComponentBase ::
    set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogTextPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_textEventOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_textEventOut_OutputPort[portNum].addCallPort(port);
  }
#endif

  void BufferManagerComponentBase ::
    set_timeCaller_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeCaller_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_timeCaller_OutputPort[portNum].addCallPort(port);
  }

  void BufferManagerComponentBase ::
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

  void BufferManagerComponentBase ::
    set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_eventOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_eventOut_OutputPort[portNum].registerSerialPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void BufferManagerComponentBase ::
    set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_textEventOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_textEventOut_OutputPort[portNum].registerSerialPort(port);
  }
#endif

  void BufferManagerComponentBase ::
    set_timeCaller_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeCaller_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_timeCaller_OutputPort[portNum].registerSerialPort(port);
  }

  void BufferManagerComponentBase ::
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
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    BufferManagerComponentBase :: BufferManagerComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {

    // Initialize telemetry channel TotalBuffs
    this->m_first_update_TotalBuffs = true;
    this->m_last_TotalBuffs = 0;
    // Initialize telemetry channel CurrBuffs
    this->m_first_update_CurrBuffs = true;
    this->m_last_CurrBuffs = 0;
    // Initialize telemetry channel HiBuffs
    this->m_first_update_HiBuffs = true;
    this->m_last_HiBuffs = 0;
    // Initialize telemetry channel NoBuffs
    this->m_first_update_NoBuffs = true;
    this->m_last_NoBuffs = 0;
    // Initialize telemetry channel EmptyBuffs
    this->m_first_update_EmptyBuffs = true;
    this->m_last_EmptyBuffs = 0;

    this->m_NoBuffsAvailableThrottle = 0;
    this->m_ZeroSizeBufferThrottle = 0;

  }

  void BufferManagerComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port bufferGetCallee
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_bufferGetCallee_InputPorts());
        port++
    ) {

      this->m_bufferGetCallee_InputPort[port].init();
      this->m_bufferGetCallee_InputPort[port].addCallComp(
          this,
          m_p_bufferGetCallee_in
      );
      this->m_bufferGetCallee_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_bufferGetCallee_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_bufferGetCallee_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port bufferSendIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_bufferSendIn_InputPorts());
        port++
    ) {

      this->m_bufferSendIn_InputPort[port].init();
      this->m_bufferSendIn_InputPort[port].addCallComp(
          this,
          m_p_bufferSendIn_in
      );
      this->m_bufferSendIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_bufferSendIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_bufferSendIn_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port schedIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_schedIn_InputPorts());
        port++
    ) {

      this->m_schedIn_InputPort[port].init();
      this->m_schedIn_InputPort[port].addCallComp(
          this,
          m_p_schedIn_in
      );
      this->m_schedIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_schedIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_schedIn_InputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port eventOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_eventOut_OutputPorts());
        port++
    ) {
      this->m_eventOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_eventOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_eventOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port textEventOut
#if FW_ENABLE_TEXT_LOGGING == 1
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_textEventOut_OutputPorts());
        port++
    ) {
      this->m_textEventOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_textEventOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_textEventOut_OutputPort[port].setObjName(portName);
#endif

    }
#endif

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


  }

  BufferManagerComponentBase::
    ~BufferManagerComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE BufferManagerComponentBase ::
    getNum_bufferGetCallee_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_bufferGetCallee_InputPort));
  }

  NATIVE_INT_TYPE BufferManagerComponentBase ::
    getNum_bufferSendIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_bufferSendIn_InputPort));
  }

  NATIVE_INT_TYPE BufferManagerComponentBase ::
    getNum_eventOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_eventOut_OutputPort));
  }

  NATIVE_INT_TYPE BufferManagerComponentBase ::
    getNum_schedIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_schedIn_InputPort));
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE BufferManagerComponentBase ::
    getNum_textEventOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_textEventOut_OutputPort));
  }
#endif

  NATIVE_INT_TYPE BufferManagerComponentBase ::
    getNum_timeCaller_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_timeCaller_OutputPort));
  }

  NATIVE_INT_TYPE BufferManagerComponentBase ::
    getNum_tlmOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_tlmOut_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool BufferManagerComponentBase ::
    isConnected_eventOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_eventOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_eventOut_OutputPort[portNum].isConnected();
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  bool BufferManagerComponentBase ::
    isConnected_textEventOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_textEventOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_textEventOut_OutputPort[portNum].isConnected();
  }
#endif

  bool BufferManagerComponentBase ::
    isConnected_timeCaller_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_timeCaller_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_timeCaller_OutputPort[portNum].isConnected();
  }

  bool BufferManagerComponentBase ::
    isConnected_tlmOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_tlmOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_tlmOut_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Telemetry write functions
  // ----------------------------------------------------------------------

  void BufferManagerComponentBase ::
    tlmWrite_TotalBuffs(U32 arg, Fw::Time _tlmTime)
  {
    // Check to see if it is the first time
    if (not this->m_first_update_TotalBuffs) {
      // Check to see if value has changed. If not, don't write it.
      if (arg == this->m_last_TotalBuffs) {
        return;
      } else {
        this->m_last_TotalBuffs = arg;
      }
    }
    else {
      this->m_first_update_TotalBuffs = false;
      this->m_last_TotalBuffs = arg;
    }

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

      _id = this->getIdBase() + CHANNELID_TOTALBUFFS;

      this->m_tlmOut_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void BufferManagerComponentBase ::
    tlmWrite_CurrBuffs(U32 arg, Fw::Time _tlmTime)
  {
    // Check to see if it is the first time
    if (not this->m_first_update_CurrBuffs) {
      // Check to see if value has changed. If not, don't write it.
      if (arg == this->m_last_CurrBuffs) {
        return;
      } else {
        this->m_last_CurrBuffs = arg;
      }
    }
    else {
      this->m_first_update_CurrBuffs = false;
      this->m_last_CurrBuffs = arg;
    }

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

      _id = this->getIdBase() + CHANNELID_CURRBUFFS;

      this->m_tlmOut_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void BufferManagerComponentBase ::
    tlmWrite_HiBuffs(U32 arg, Fw::Time _tlmTime)
  {
    // Check to see if it is the first time
    if (not this->m_first_update_HiBuffs) {
      // Check to see if value has changed. If not, don't write it.
      if (arg == this->m_last_HiBuffs) {
        return;
      } else {
        this->m_last_HiBuffs = arg;
      }
    }
    else {
      this->m_first_update_HiBuffs = false;
      this->m_last_HiBuffs = arg;
    }

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

      _id = this->getIdBase() + CHANNELID_HIBUFFS;

      this->m_tlmOut_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void BufferManagerComponentBase ::
    tlmWrite_NoBuffs(U32 arg, Fw::Time _tlmTime)
  {
    // Check to see if it is the first time
    if (not this->m_first_update_NoBuffs) {
      // Check to see if value has changed. If not, don't write it.
      if (arg == this->m_last_NoBuffs) {
        return;
      } else {
        this->m_last_NoBuffs = arg;
      }
    }
    else {
      this->m_first_update_NoBuffs = false;
      this->m_last_NoBuffs = arg;
    }

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

      _id = this->getIdBase() + CHANNELID_NOBUFFS;

      this->m_tlmOut_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void BufferManagerComponentBase ::
    tlmWrite_EmptyBuffs(U32 arg, Fw::Time _tlmTime)
  {
    // Check to see if it is the first time
    if (not this->m_first_update_EmptyBuffs) {
      // Check to see if value has changed. If not, don't write it.
      if (arg == this->m_last_EmptyBuffs) {
        return;
      } else {
        this->m_last_EmptyBuffs = arg;
      }
    }
    else {
      this->m_first_update_EmptyBuffs = false;
      this->m_last_EmptyBuffs = arg;
    }

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

      _id = this->getIdBase() + CHANNELID_EMPTYBUFFS;

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

  Fw::Time BufferManagerComponentBase ::
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
  // Event handling functions
  // ----------------------------------------------------------------------

  void BufferManagerComponentBase ::
    log_WARNING_HI_NoBuffsAvailable(
        U32 size
    )
  {

    // check throttle value
    if (this->m_NoBuffsAvailableThrottle >= EVENTID_NOBUFFSAVAILABLE_THROTTLE) {
        return;
    } else {
        this->m_NoBuffsAvailableThrottle++;
    }

    // Get the time
    Fw::Time _logTime;
    if (this->m_timeCaller_OutputPort[0].isConnected()) {
       this->m_timeCaller_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_NOBUFFSAVAILABLE;

    // Emit the event on the log port
    if (this->m_eventOut_OutputPort[0].isConnected()) {

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
      _status = _logBuff.serialize(size);
      FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_status)
      );


      this->m_eventOut_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::WARNING_HI,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_textEventOut_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: No available buffers of size %u";
#else
      const char* _formatString =
        "%s: No available buffers of size %u";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "NoBuffsAvailable "
        , size
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_textEventOut_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::WARNING_HI,
          _logString
      );

    }
#endif

  }

    void BufferManagerComponentBase::log_WARNING_HI_NoBuffsAvailable_ThrottleClear() {
        // reset throttle counter
        this->m_NoBuffsAvailableThrottle = 0;
    }

  void BufferManagerComponentBase ::
    log_WARNING_HI_ZeroSizeBuffer(
        
    )
  {

    // check throttle value
    if (this->m_ZeroSizeBufferThrottle >= EVENTID_ZEROSIZEBUFFER_THROTTLE) {
        return;
    } else {
        this->m_ZeroSizeBufferThrottle++;
    }

    // Get the time
    Fw::Time _logTime;
    if (this->m_timeCaller_OutputPort[0].isConnected()) {
       this->m_timeCaller_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_ZEROSIZEBUFFER;

    // Emit the event on the log port
    if (this->m_eventOut_OutputPort[0].isConnected()) {

      Fw::LogBuffer _logBuff;
#if FW_AMPCS_COMPATIBLE
      // for AMPCS, need to encode zero arguments
      Fw::SerializeStatus _zero_status = Fw::FW_SERIALIZE_OK;
      _zero_status = _logBuff.serialize(static_cast<U8>(0));
      FW_ASSERT(
          _zero_status == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(_zero_status)
      );
#endif


      this->m_eventOut_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::WARNING_HI,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_textEventOut_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: Received zero size buffer";
#else
      const char* _formatString =
        "%s: Received zero size buffer";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "ZeroSizeBuffer "
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_textEventOut_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::WARNING_HI,
          _logString
      );

    }
#endif

  }

    void BufferManagerComponentBase::log_WARNING_HI_ZeroSizeBuffer_ThrottleClear() {
        // reset throttle counter
        this->m_ZeroSizeBufferThrottle = 0;
    }

  // ----------------------------------------------------------------------
  // Mutex functions for guarded ports
  // ----------------------------------------------------------------------

  void BufferManagerComponentBase ::
    lock()
  {
    this->m_guardedPortMutex.lock();
  }

  void BufferManagerComponentBase ::
    unLock()
  {
    this->m_guardedPortMutex.unLock();
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  Fw::Buffer BufferManagerComponentBase ::
    m_p_bufferGetCallee_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        U32 size
    )
  {
    FW_ASSERT(callComp);
    BufferManagerComponentBase* compPtr = static_cast<BufferManagerComponentBase*>(callComp);
    return compPtr->bufferGetCallee_handlerBase(portNum, size);
  }

  void BufferManagerComponentBase ::
    m_p_bufferSendIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(callComp);
    BufferManagerComponentBase* compPtr = static_cast<BufferManagerComponentBase*>(callComp);
    compPtr->bufferSendIn_handlerBase(portNum, fwBuffer);
  }

  void BufferManagerComponentBase ::
    m_p_schedIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(callComp);
    BufferManagerComponentBase* compPtr = static_cast<BufferManagerComponentBase*>(callComp);
    compPtr->schedIn_handlerBase(portNum, context);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  Fw::Buffer BufferManagerComponentBase ::
    bufferGetCallee_handlerBase(
        NATIVE_INT_TYPE portNum,
        U32 size
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_bufferGetCallee_InputPorts(),static_cast<FwAssertArgType>(portNum));
    Fw::Buffer  retVal;

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    retVal = this->bufferGetCallee_handler(portNum, size);

    // Unlock guard mutex
    this->unLock();

    return retVal;

  }

  void BufferManagerComponentBase ::
    bufferSendIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_bufferSendIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->bufferSendIn_handler(portNum, fwBuffer);

    // Unlock guard mutex
    this->unLock();

  }

  void BufferManagerComponentBase ::
    schedIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_schedIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->schedIn_handler(portNum, context);

  }

} // end namespace Svc
