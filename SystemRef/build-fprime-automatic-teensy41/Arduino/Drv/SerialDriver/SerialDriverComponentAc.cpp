// ======================================================================
// \title  SerialDriverComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for SerialDriver component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Arduino/Drv/SerialDriver/SerialDriverComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Arduino {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Svc::InputSchedPort *SerialDriverComponentBase ::
    get_schedIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_schedIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_schedIn_InputPort[portNum];
  }

  Drv::InputByteStreamSendPort *SerialDriverComponentBase ::
    get_send_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_send_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_send_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void SerialDriverComponentBase ::
    set_allocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferGetPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_allocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_allocate_OutputPort[portNum].addCallPort(port);
  }

  void SerialDriverComponentBase ::
    set_deallocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_deallocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_deallocate_OutputPort[portNum].addCallPort(port);
  }

  void SerialDriverComponentBase ::
    set_ready_OutputPort(
        NATIVE_INT_TYPE portNum,
        Drv::InputByteStreamReadyPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_ready_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_ready_OutputPort[portNum].addCallPort(port);
  }

  void SerialDriverComponentBase ::
    set_recv_OutputPort(
        NATIVE_INT_TYPE portNum,
        Drv::InputByteStreamRecvPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_recv_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_recv_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void SerialDriverComponentBase ::
    set_allocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_allocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_allocate_OutputPort[portNum].registerSerialPort(port);
  }

  void SerialDriverComponentBase ::
    set_deallocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_deallocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_deallocate_OutputPort[portNum].registerSerialPort(port);
  }

  void SerialDriverComponentBase ::
    set_ready_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_ready_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_ready_OutputPort[portNum].registerSerialPort(port);
  }

  void SerialDriverComponentBase ::
    set_recv_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_recv_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_recv_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    SerialDriverComponentBase :: SerialDriverComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void SerialDriverComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

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

    // Connect input port send
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_send_InputPorts());
        port++
    ) {

      this->m_send_InputPort[port].init();
      this->m_send_InputPort[port].addCallComp(
          this,
          m_p_send_in
      );
      this->m_send_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_send_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_send_InputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port allocate
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_allocate_OutputPorts());
        port++
    ) {
      this->m_allocate_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_allocate_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_allocate_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port deallocate
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_deallocate_OutputPorts());
        port++
    ) {
      this->m_deallocate_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_deallocate_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_deallocate_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port ready
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_ready_OutputPorts());
        port++
    ) {
      this->m_ready_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_ready_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_ready_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port recv
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_recv_OutputPorts());
        port++
    ) {
      this->m_recv_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_recv_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_recv_OutputPort[port].setObjName(portName);
#endif

    }


  }

  SerialDriverComponentBase::
    ~SerialDriverComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  Fw::Buffer SerialDriverComponentBase ::
    allocate_out(
        NATIVE_INT_TYPE portNum,
        U32 size
    )
  {
    FW_ASSERT(portNum < this->getNum_allocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_allocate_OutputPort[portNum].invoke(size);
  }

  void SerialDriverComponentBase ::
    deallocate_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_deallocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_deallocate_OutputPort[portNum].invoke(fwBuffer);
  }

  void SerialDriverComponentBase ::
    ready_out(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_ready_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_ready_OutputPort[portNum].invoke();
  }

  void SerialDriverComponentBase ::
    recv_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &recvBuffer, const Drv::RecvStatus &recvStatus
    )
  {
    FW_ASSERT(portNum < this->getNum_recv_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_recv_OutputPort[portNum].invoke(recvBuffer, recvStatus);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE SerialDriverComponentBase ::
    getNum_allocate_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_allocate_OutputPort));
  }

  NATIVE_INT_TYPE SerialDriverComponentBase ::
    getNum_deallocate_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_deallocate_OutputPort));
  }

  NATIVE_INT_TYPE SerialDriverComponentBase ::
    getNum_ready_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_ready_OutputPort));
  }

  NATIVE_INT_TYPE SerialDriverComponentBase ::
    getNum_recv_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_recv_OutputPort));
  }

  NATIVE_INT_TYPE SerialDriverComponentBase ::
    getNum_schedIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_schedIn_InputPort));
  }

  NATIVE_INT_TYPE SerialDriverComponentBase ::
    getNum_send_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_send_InputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool SerialDriverComponentBase ::
    isConnected_allocate_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_allocate_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_allocate_OutputPort[portNum].isConnected();
  }

  bool SerialDriverComponentBase ::
    isConnected_deallocate_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_deallocate_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_deallocate_OutputPort[portNum].isConnected();
  }

  bool SerialDriverComponentBase ::
    isConnected_ready_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_ready_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_ready_OutputPort[portNum].isConnected();
  }

  bool SerialDriverComponentBase ::
    isConnected_recv_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_recv_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_recv_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Mutex functions for guarded ports
  // ----------------------------------------------------------------------

  void SerialDriverComponentBase ::
    lock()
  {
    this->m_guardedPortMutex.lock();
  }

  void SerialDriverComponentBase ::
    unLock()
  {
    this->m_guardedPortMutex.unLock();
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void SerialDriverComponentBase ::
    m_p_schedIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(callComp);
    SerialDriverComponentBase* compPtr = static_cast<SerialDriverComponentBase*>(callComp);
    compPtr->schedIn_handlerBase(portNum, context);
  }

  Drv::SendStatus SerialDriverComponentBase ::
    m_p_send_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &sendBuffer
    )
  {
    FW_ASSERT(callComp);
    SerialDriverComponentBase* compPtr = static_cast<SerialDriverComponentBase*>(callComp);
    return compPtr->send_handlerBase(portNum, sendBuffer);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void SerialDriverComponentBase ::
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

  Drv::SendStatus SerialDriverComponentBase ::
    send_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &sendBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_send_InputPorts(),static_cast<FwAssertArgType>(portNum));
    Drv::SendStatus  retVal;

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    retVal = this->send_handler(portNum, sendBuffer);

    // Unlock guard mutex
    this->unLock();

    return retVal;

  }

} // end namespace Arduino
