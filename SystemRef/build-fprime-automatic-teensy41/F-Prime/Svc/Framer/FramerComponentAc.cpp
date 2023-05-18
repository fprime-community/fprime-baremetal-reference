// ======================================================================
// \title  FramerComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for Framer component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/Framer/FramerComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputBufferSendPort *FramerComponentBase ::
    get_bufferIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_bufferIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_bufferIn_InputPort[portNum];
  }

  Fw::InputComPort *FramerComponentBase ::
    get_comIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_comIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_comIn_InputPort[portNum];
  }

  Fw::InputSuccessConditionPort *FramerComponentBase ::
    get_comStatusIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_comStatusIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_comStatusIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void FramerComponentBase ::
    set_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferDeallocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_bufferDeallocate_OutputPort[portNum].addCallPort(port);
  }

  void FramerComponentBase ::
    set_comStatusOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSuccessConditionPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_comStatusOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_comStatusOut_OutputPort[portNum].addCallPort(port);
  }

  void FramerComponentBase ::
    set_framedAllocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferGetPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_framedAllocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_framedAllocate_OutputPort[portNum].addCallPort(port);
  }

  void FramerComponentBase ::
    set_framedOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Drv::InputByteStreamSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_framedOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_framedOut_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void FramerComponentBase ::
    set_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferDeallocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_bufferDeallocate_OutputPort[portNum].registerSerialPort(port);
  }

  void FramerComponentBase ::
    set_comStatusOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_comStatusOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_comStatusOut_OutputPort[portNum].registerSerialPort(port);
  }

  void FramerComponentBase ::
    set_framedAllocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_framedAllocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_framedAllocate_OutputPort[portNum].registerSerialPort(port);
  }

  void FramerComponentBase ::
    set_framedOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_framedOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_framedOut_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    FramerComponentBase :: FramerComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void FramerComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port bufferIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_bufferIn_InputPorts());
        port++
    ) {

      this->m_bufferIn_InputPort[port].init();
      this->m_bufferIn_InputPort[port].addCallComp(
          this,
          m_p_bufferIn_in
      );
      this->m_bufferIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_bufferIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_bufferIn_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port comIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_comIn_InputPorts());
        port++
    ) {

      this->m_comIn_InputPort[port].init();
      this->m_comIn_InputPort[port].addCallComp(
          this,
          m_p_comIn_in
      );
      this->m_comIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_comIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_comIn_InputPort[port].setObjName(portName);
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

    // Initialize output port bufferDeallocate
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_bufferDeallocate_OutputPorts());
        port++
    ) {
      this->m_bufferDeallocate_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_bufferDeallocate_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_bufferDeallocate_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port comStatusOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_comStatusOut_OutputPorts());
        port++
    ) {
      this->m_comStatusOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_comStatusOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_comStatusOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port framedAllocate
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_framedAllocate_OutputPorts());
        port++
    ) {
      this->m_framedAllocate_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_framedAllocate_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_framedAllocate_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port framedOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_framedOut_OutputPorts());
        port++
    ) {
      this->m_framedOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_framedOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_framedOut_OutputPort[port].setObjName(portName);
#endif

    }


  }

  FramerComponentBase::
    ~FramerComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void FramerComponentBase ::
    bufferDeallocate_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferDeallocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_bufferDeallocate_OutputPort[portNum].invoke(fwBuffer);
  }

  void FramerComponentBase ::
    comStatusOut_out(
        NATIVE_INT_TYPE portNum,
        Fw::Success &condition
    )
  {
    FW_ASSERT(portNum < this->getNum_comStatusOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_comStatusOut_OutputPort[portNum].invoke(condition);
  }

  Fw::Buffer FramerComponentBase ::
    framedAllocate_out(
        NATIVE_INT_TYPE portNum,
        U32 size
    )
  {
    FW_ASSERT(portNum < this->getNum_framedAllocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_framedAllocate_OutputPort[portNum].invoke(size);
  }

  Drv::SendStatus FramerComponentBase ::
    framedOut_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &sendBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_framedOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_framedOut_OutputPort[portNum].invoke(sendBuffer);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE FramerComponentBase ::
    getNum_bufferDeallocate_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_bufferDeallocate_OutputPort));
  }

  NATIVE_INT_TYPE FramerComponentBase ::
    getNum_bufferIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_bufferIn_InputPort));
  }

  NATIVE_INT_TYPE FramerComponentBase ::
    getNum_comIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_comIn_InputPort));
  }

  NATIVE_INT_TYPE FramerComponentBase ::
    getNum_comStatusIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_comStatusIn_InputPort));
  }

  NATIVE_INT_TYPE FramerComponentBase ::
    getNum_comStatusOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_comStatusOut_OutputPort));
  }

  NATIVE_INT_TYPE FramerComponentBase ::
    getNum_framedAllocate_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_framedAllocate_OutputPort));
  }

  NATIVE_INT_TYPE FramerComponentBase ::
    getNum_framedOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_framedOut_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool FramerComponentBase ::
    isConnected_bufferDeallocate_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_bufferDeallocate_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_bufferDeallocate_OutputPort[portNum].isConnected();
  }

  bool FramerComponentBase ::
    isConnected_comStatusOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_comStatusOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_comStatusOut_OutputPort[portNum].isConnected();
  }

  bool FramerComponentBase ::
    isConnected_framedAllocate_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_framedAllocate_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_framedAllocate_OutputPort[portNum].isConnected();
  }

  bool FramerComponentBase ::
    isConnected_framedOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_framedOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_framedOut_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Mutex functions for guarded ports
  // ----------------------------------------------------------------------

  void FramerComponentBase ::
    lock()
  {
    this->m_guardedPortMutex.lock();
  }

  void FramerComponentBase ::
    unLock()
  {
    this->m_guardedPortMutex.unLock();
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void FramerComponentBase ::
    m_p_bufferIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(callComp);
    FramerComponentBase* compPtr = static_cast<FramerComponentBase*>(callComp);
    compPtr->bufferIn_handlerBase(portNum, fwBuffer);
  }

  void FramerComponentBase ::
    m_p_comIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {
    FW_ASSERT(callComp);
    FramerComponentBase* compPtr = static_cast<FramerComponentBase*>(callComp);
    compPtr->comIn_handlerBase(portNum, data, context);
  }

  void FramerComponentBase ::
    m_p_comStatusIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Success &condition
    )
  {
    FW_ASSERT(callComp);
    FramerComponentBase* compPtr = static_cast<FramerComponentBase*>(callComp);
    compPtr->comStatusIn_handlerBase(portNum, condition);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void FramerComponentBase ::
    bufferIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_bufferIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->bufferIn_handler(portNum, fwBuffer);

    // Unlock guard mutex
    this->unLock();

  }

  void FramerComponentBase ::
    comIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_comIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->comIn_handler(portNum, data, context);

    // Unlock guard mutex
    this->unLock();

  }

  void FramerComponentBase ::
    comStatusIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Success &condition
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_comStatusIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->comStatusIn_handler(portNum, condition);

    // Unlock guard mutex
    this->unLock();

  }

} // end namespace Svc
