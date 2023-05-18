// ======================================================================
// \title  DeframerComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for Deframer component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/Deframer/DeframerComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputCmdResponsePort *DeframerComponentBase ::
    get_cmdResponseIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_cmdResponseIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_cmdResponseIn_InputPort[portNum];
  }

  Drv::InputByteStreamRecvPort *DeframerComponentBase ::
    get_framedIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_framedIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_framedIn_InputPort[portNum];
  }

  Svc::InputSchedPort *DeframerComponentBase ::
    get_schedIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_schedIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_schedIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void DeframerComponentBase ::
    set_bufferAllocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferGetPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferAllocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_bufferAllocate_OutputPort[portNum].addCallPort(port);
  }

  void DeframerComponentBase ::
    set_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferDeallocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_bufferDeallocate_OutputPort[portNum].addCallPort(port);
  }

  void DeframerComponentBase ::
    set_bufferOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_bufferOut_OutputPort[portNum].addCallPort(port);
  }

  void DeframerComponentBase ::
    set_comOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputComPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_comOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_comOut_OutputPort[portNum].addCallPort(port);
  }

  void DeframerComponentBase ::
    set_framedDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_framedDeallocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_framedDeallocate_OutputPort[portNum].addCallPort(port);
  }

  void DeframerComponentBase ::
    set_framedPoll_OutputPort(
        NATIVE_INT_TYPE portNum,
        Drv::InputByteStreamPollPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_framedPoll_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_framedPoll_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void DeframerComponentBase ::
    set_bufferAllocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferAllocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_bufferAllocate_OutputPort[portNum].registerSerialPort(port);
  }

  void DeframerComponentBase ::
    set_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferDeallocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_bufferDeallocate_OutputPort[portNum].registerSerialPort(port);
  }

  void DeframerComponentBase ::
    set_bufferOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_bufferOut_OutputPort[portNum].registerSerialPort(port);
  }

  void DeframerComponentBase ::
    set_comOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_comOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_comOut_OutputPort[portNum].registerSerialPort(port);
  }

  void DeframerComponentBase ::
    set_framedDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_framedDeallocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_framedDeallocate_OutputPort[portNum].registerSerialPort(port);
  }

  void DeframerComponentBase ::
    set_framedPoll_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_framedPoll_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_framedPoll_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    DeframerComponentBase :: DeframerComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void DeframerComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port cmdResponseIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_cmdResponseIn_InputPorts());
        port++
    ) {

      this->m_cmdResponseIn_InputPort[port].init();
      this->m_cmdResponseIn_InputPort[port].addCallComp(
          this,
          m_p_cmdResponseIn_in
      );
      this->m_cmdResponseIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_cmdResponseIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_cmdResponseIn_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port framedIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_framedIn_InputPorts());
        port++
    ) {

      this->m_framedIn_InputPort[port].init();
      this->m_framedIn_InputPort[port].addCallComp(
          this,
          m_p_framedIn_in
      );
      this->m_framedIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_framedIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_framedIn_InputPort[port].setObjName(portName);
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

    // Initialize output port bufferAllocate
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_bufferAllocate_OutputPorts());
        port++
    ) {
      this->m_bufferAllocate_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_bufferAllocate_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_bufferAllocate_OutputPort[port].setObjName(portName);
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

    // Initialize output port bufferOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_bufferOut_OutputPorts());
        port++
    ) {
      this->m_bufferOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_bufferOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_bufferOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port comOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_comOut_OutputPorts());
        port++
    ) {
      this->m_comOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_comOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_comOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port framedDeallocate
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_framedDeallocate_OutputPorts());
        port++
    ) {
      this->m_framedDeallocate_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_framedDeallocate_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_framedDeallocate_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port framedPoll
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_framedPoll_OutputPorts());
        port++
    ) {
      this->m_framedPoll_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_framedPoll_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_framedPoll_OutputPort[port].setObjName(portName);
#endif

    }


  }

  DeframerComponentBase::
    ~DeframerComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  Fw::Buffer DeframerComponentBase ::
    bufferAllocate_out(
        NATIVE_INT_TYPE portNum,
        U32 size
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferAllocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_bufferAllocate_OutputPort[portNum].invoke(size);
  }

  void DeframerComponentBase ::
    bufferDeallocate_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferDeallocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_bufferDeallocate_OutputPort[portNum].invoke(fwBuffer);
  }

  void DeframerComponentBase ::
    bufferOut_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_bufferOut_OutputPort[portNum].invoke(fwBuffer);
  }

  void DeframerComponentBase ::
    comOut_out(
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {
    FW_ASSERT(portNum < this->getNum_comOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_comOut_OutputPort[portNum].invoke(data, context);
  }

  void DeframerComponentBase ::
    framedDeallocate_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_framedDeallocate_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_framedDeallocate_OutputPort[portNum].invoke(fwBuffer);
  }

  Drv::PollStatus DeframerComponentBase ::
    framedPoll_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &pollBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_framedPoll_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_framedPoll_OutputPort[portNum].invoke(pollBuffer);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE DeframerComponentBase ::
    getNum_bufferAllocate_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_bufferAllocate_OutputPort));
  }

  NATIVE_INT_TYPE DeframerComponentBase ::
    getNum_bufferDeallocate_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_bufferDeallocate_OutputPort));
  }

  NATIVE_INT_TYPE DeframerComponentBase ::
    getNum_bufferOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_bufferOut_OutputPort));
  }

  NATIVE_INT_TYPE DeframerComponentBase ::
    getNum_cmdResponseIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_cmdResponseIn_InputPort));
  }

  NATIVE_INT_TYPE DeframerComponentBase ::
    getNum_comOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_comOut_OutputPort));
  }

  NATIVE_INT_TYPE DeframerComponentBase ::
    getNum_framedDeallocate_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_framedDeallocate_OutputPort));
  }

  NATIVE_INT_TYPE DeframerComponentBase ::
    getNum_framedIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_framedIn_InputPort));
  }

  NATIVE_INT_TYPE DeframerComponentBase ::
    getNum_framedPoll_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_framedPoll_OutputPort));
  }

  NATIVE_INT_TYPE DeframerComponentBase ::
    getNum_schedIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_schedIn_InputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool DeframerComponentBase ::
    isConnected_bufferAllocate_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_bufferAllocate_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_bufferAllocate_OutputPort[portNum].isConnected();
  }

  bool DeframerComponentBase ::
    isConnected_bufferDeallocate_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_bufferDeallocate_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_bufferDeallocate_OutputPort[portNum].isConnected();
  }

  bool DeframerComponentBase ::
    isConnected_bufferOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_bufferOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_bufferOut_OutputPort[portNum].isConnected();
  }

  bool DeframerComponentBase ::
    isConnected_comOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_comOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_comOut_OutputPort[portNum].isConnected();
  }

  bool DeframerComponentBase ::
    isConnected_framedDeallocate_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_framedDeallocate_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_framedDeallocate_OutputPort[portNum].isConnected();
  }

  bool DeframerComponentBase ::
    isConnected_framedPoll_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_framedPoll_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_framedPoll_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Mutex functions for guarded ports
  // ----------------------------------------------------------------------

  void DeframerComponentBase ::
    lock()
  {
    this->m_guardedPortMutex.lock();
  }

  void DeframerComponentBase ::
    unLock()
  {
    this->m_guardedPortMutex.unLock();
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void DeframerComponentBase ::
    m_p_cmdResponseIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        FwOpcodeType opCode, U32 cmdSeq, const Fw::CmdResponse &response
    )
  {
    FW_ASSERT(callComp);
    DeframerComponentBase* compPtr = static_cast<DeframerComponentBase*>(callComp);
    compPtr->cmdResponseIn_handlerBase(portNum, opCode, cmdSeq, response);
  }

  void DeframerComponentBase ::
    m_p_framedIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &recvBuffer, const Drv::RecvStatus &recvStatus
    )
  {
    FW_ASSERT(callComp);
    DeframerComponentBase* compPtr = static_cast<DeframerComponentBase*>(callComp);
    compPtr->framedIn_handlerBase(portNum, recvBuffer, recvStatus);
  }

  void DeframerComponentBase ::
    m_p_schedIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(callComp);
    DeframerComponentBase* compPtr = static_cast<DeframerComponentBase*>(callComp);
    compPtr->schedIn_handlerBase(portNum, context);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void DeframerComponentBase ::
    cmdResponseIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        FwOpcodeType opCode, U32 cmdSeq, const Fw::CmdResponse &response
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_cmdResponseIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->cmdResponseIn_handler(portNum, opCode, cmdSeq, response);

  }

  void DeframerComponentBase ::
    framedIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &recvBuffer, const Drv::RecvStatus &recvStatus
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_framedIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->framedIn_handler(portNum, recvBuffer, recvStatus);

    // Unlock guard mutex
    this->unLock();

  }

  void DeframerComponentBase ::
    schedIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_schedIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->schedIn_handler(portNum, context);

    // Unlock guard mutex
    this->unLock();

  }

} // end namespace Svc
