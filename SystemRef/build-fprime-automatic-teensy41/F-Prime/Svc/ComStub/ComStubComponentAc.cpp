// ======================================================================
// \title  ComStubComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for ComStub component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/ComStub/ComStubComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Drv::InputByteStreamSendPort *ComStubComponentBase ::
    get_comDataIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_comDataIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_comDataIn_InputPort[portNum];
  }

  Drv::InputByteStreamReadyPort *ComStubComponentBase ::
    get_drvConnected_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_drvConnected_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_drvConnected_InputPort[portNum];
  }

  Drv::InputByteStreamRecvPort *ComStubComponentBase ::
    get_drvDataIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_drvDataIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_drvDataIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void ComStubComponentBase ::
    set_comDataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Drv::InputByteStreamRecvPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_comDataOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_comDataOut_OutputPort[portNum].addCallPort(port);
  }

  void ComStubComponentBase ::
    set_comStatus_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSuccessConditionPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_comStatus_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_comStatus_OutputPort[portNum].addCallPort(port);
  }

  void ComStubComponentBase ::
    set_drvDataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Drv::InputByteStreamSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_drvDataOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_drvDataOut_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void ComStubComponentBase ::
    set_comDataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_comDataOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_comDataOut_OutputPort[portNum].registerSerialPort(port);
  }

  void ComStubComponentBase ::
    set_comStatus_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_comStatus_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_comStatus_OutputPort[portNum].registerSerialPort(port);
  }

  void ComStubComponentBase ::
    set_drvDataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_drvDataOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_drvDataOut_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    ComStubComponentBase :: ComStubComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void ComStubComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port comDataIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_comDataIn_InputPorts());
        port++
    ) {

      this->m_comDataIn_InputPort[port].init();
      this->m_comDataIn_InputPort[port].addCallComp(
          this,
          m_p_comDataIn_in
      );
      this->m_comDataIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_comDataIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_comDataIn_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port drvConnected
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_drvConnected_InputPorts());
        port++
    ) {

      this->m_drvConnected_InputPort[port].init();
      this->m_drvConnected_InputPort[port].addCallComp(
          this,
          m_p_drvConnected_in
      );
      this->m_drvConnected_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_drvConnected_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_drvConnected_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port drvDataIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_drvDataIn_InputPorts());
        port++
    ) {

      this->m_drvDataIn_InputPort[port].init();
      this->m_drvDataIn_InputPort[port].addCallComp(
          this,
          m_p_drvDataIn_in
      );
      this->m_drvDataIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_drvDataIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_drvDataIn_InputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port comDataOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_comDataOut_OutputPorts());
        port++
    ) {
      this->m_comDataOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_comDataOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_comDataOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port comStatus
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_comStatus_OutputPorts());
        port++
    ) {
      this->m_comStatus_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_comStatus_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_comStatus_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port drvDataOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_drvDataOut_OutputPorts());
        port++
    ) {
      this->m_drvDataOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_drvDataOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_drvDataOut_OutputPort[port].setObjName(portName);
#endif

    }


  }

  ComStubComponentBase::
    ~ComStubComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void ComStubComponentBase ::
    comDataOut_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &recvBuffer, const Drv::RecvStatus &recvStatus
    )
  {
    FW_ASSERT(portNum < this->getNum_comDataOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_comDataOut_OutputPort[portNum].invoke(recvBuffer, recvStatus);
  }

  void ComStubComponentBase ::
    comStatus_out(
        NATIVE_INT_TYPE portNum,
        Fw::Success &condition
    )
  {
    FW_ASSERT(portNum < this->getNum_comStatus_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_comStatus_OutputPort[portNum].invoke(condition);
  }

  Drv::SendStatus ComStubComponentBase ::
    drvDataOut_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &sendBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_drvDataOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_drvDataOut_OutputPort[portNum].invoke(sendBuffer);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE ComStubComponentBase ::
    getNum_comDataIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_comDataIn_InputPort));
  }

  NATIVE_INT_TYPE ComStubComponentBase ::
    getNum_comDataOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_comDataOut_OutputPort));
  }

  NATIVE_INT_TYPE ComStubComponentBase ::
    getNum_comStatus_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_comStatus_OutputPort));
  }

  NATIVE_INT_TYPE ComStubComponentBase ::
    getNum_drvConnected_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_drvConnected_InputPort));
  }

  NATIVE_INT_TYPE ComStubComponentBase ::
    getNum_drvDataIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_drvDataIn_InputPort));
  }

  NATIVE_INT_TYPE ComStubComponentBase ::
    getNum_drvDataOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_drvDataOut_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool ComStubComponentBase ::
    isConnected_comDataOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_comDataOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_comDataOut_OutputPort[portNum].isConnected();
  }

  bool ComStubComponentBase ::
    isConnected_comStatus_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_comStatus_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_comStatus_OutputPort[portNum].isConnected();
  }

  bool ComStubComponentBase ::
    isConnected_drvDataOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_drvDataOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_drvDataOut_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  Drv::SendStatus ComStubComponentBase ::
    m_p_comDataIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &sendBuffer
    )
  {
    FW_ASSERT(callComp);
    ComStubComponentBase* compPtr = static_cast<ComStubComponentBase*>(callComp);
    return compPtr->comDataIn_handlerBase(portNum, sendBuffer);
  }

  void ComStubComponentBase ::
    m_p_drvConnected_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum
    )
  {
    FW_ASSERT(callComp);
    ComStubComponentBase* compPtr = static_cast<ComStubComponentBase*>(callComp);
    compPtr->drvConnected_handlerBase(portNum);
  }

  void ComStubComponentBase ::
    m_p_drvDataIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &recvBuffer, const Drv::RecvStatus &recvStatus
    )
  {
    FW_ASSERT(callComp);
    ComStubComponentBase* compPtr = static_cast<ComStubComponentBase*>(callComp);
    compPtr->drvDataIn_handlerBase(portNum, recvBuffer, recvStatus);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  Drv::SendStatus ComStubComponentBase ::
    comDataIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &sendBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_comDataIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    Drv::SendStatus  retVal;

    // Down call to pure virtual handler method implemented in Impl class
    retVal = this->comDataIn_handler(portNum, sendBuffer);

    return retVal;

  }

  void ComStubComponentBase ::
    drvConnected_handlerBase(NATIVE_INT_TYPE portNum)
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_drvConnected_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->drvConnected_handler(portNum);

  }

  void ComStubComponentBase ::
    drvDataIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &recvBuffer, const Drv::RecvStatus &recvStatus
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_drvDataIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->drvDataIn_handler(portNum, recvBuffer, recvStatus);

  }

} // end namespace Svc
