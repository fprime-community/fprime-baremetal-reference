// ======================================================================
// \title  RateGroupDriverComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for RateGroupDriver component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/RateGroupDriver/RateGroupDriverComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Svc::InputCyclePort *RateGroupDriverComponentBase ::
    get_CycleIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_CycleIn_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_CycleIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void RateGroupDriverComponentBase ::
    set_CycleOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Svc::InputCyclePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_CycleOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_CycleOut_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void RateGroupDriverComponentBase ::
    set_CycleOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_CycleOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_CycleOut_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    RateGroupDriverComponentBase :: RateGroupDriverComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void RateGroupDriverComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port CycleIn
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_CycleIn_InputPorts());
        port++
    ) {

      this->m_CycleIn_InputPort[port].init();
      this->m_CycleIn_InputPort[port].addCallComp(
          this,
          m_p_CycleIn_in
      );
      this->m_CycleIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_CycleIn_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_CycleIn_InputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port CycleOut
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_CycleOut_OutputPorts());
        port++
    ) {
      this->m_CycleOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_CycleOut_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_CycleOut_OutputPort[port].setObjName(portName);
#endif

    }


  }

  RateGroupDriverComponentBase::
    ~RateGroupDriverComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void RateGroupDriverComponentBase ::
    CycleOut_out(
        NATIVE_INT_TYPE portNum,
        Svc::TimerVal &cycleStart
    )
  {
    FW_ASSERT(portNum < this->getNum_CycleOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_CycleOut_OutputPort[portNum].invoke(cycleStart);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE RateGroupDriverComponentBase ::
    getNum_CycleIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_CycleIn_InputPort));
  }

  NATIVE_INT_TYPE RateGroupDriverComponentBase ::
    getNum_CycleOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_CycleOut_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool RateGroupDriverComponentBase ::
    isConnected_CycleOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_CycleOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_CycleOut_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void RateGroupDriverComponentBase ::
    m_p_CycleIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Svc::TimerVal &cycleStart
    )
  {
    FW_ASSERT(callComp);
    RateGroupDriverComponentBase* compPtr = static_cast<RateGroupDriverComponentBase*>(callComp);
    compPtr->CycleIn_handlerBase(portNum, cycleStart);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void RateGroupDriverComponentBase ::
    CycleIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Svc::TimerVal &cycleStart
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_CycleIn_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->CycleIn_handler(portNum, cycleStart);

  }

} // end namespace Svc
