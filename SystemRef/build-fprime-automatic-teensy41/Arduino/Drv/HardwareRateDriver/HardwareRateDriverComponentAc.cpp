// ======================================================================
// \title  HardwareRateDriverComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for HardwareRateDriver component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Arduino/Drv/HardwareRateDriver/HardwareRateDriverComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Arduino {

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void HardwareRateDriverComponentBase ::
    set_CycleOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Svc::InputCyclePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_CycleOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_CycleOut_OutputPort[portNum].addCallPort(port);
  }

  void HardwareRateDriverComponentBase ::
    set_error_OutputPort(
        NATIVE_INT_TYPE portNum,
        Drv::InputGpioWritePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_error_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_error_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void HardwareRateDriverComponentBase ::
    set_CycleOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_CycleOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_CycleOut_OutputPort[portNum].registerSerialPort(port);
  }

  void HardwareRateDriverComponentBase ::
    set_error_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_error_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    return this->m_error_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    HardwareRateDriverComponentBase :: HardwareRateDriverComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void HardwareRateDriverComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

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

    // Initialize output port error
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_error_OutputPorts());
        port++
    ) {
      this->m_error_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_error_OutputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_error_OutputPort[port].setObjName(portName);
#endif

    }


  }

  HardwareRateDriverComponentBase::
    ~HardwareRateDriverComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void HardwareRateDriverComponentBase ::
    CycleOut_out(
        NATIVE_INT_TYPE portNum,
        Svc::TimerVal &cycleStart
    )
  {
    FW_ASSERT(portNum < this->getNum_CycleOut_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_CycleOut_OutputPort[portNum].invoke(cycleStart);
  }

  void HardwareRateDriverComponentBase ::
    error_out(
        NATIVE_INT_TYPE portNum,
        const Fw::Logic &state
    )
  {
    FW_ASSERT(portNum < this->getNum_error_OutputPorts(),static_cast<FwAssertArgType>(portNum));
    this->m_error_OutputPort[portNum].invoke(state);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE HardwareRateDriverComponentBase ::
    getNum_CycleOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_CycleOut_OutputPort));
  }

  NATIVE_INT_TYPE HardwareRateDriverComponentBase ::
    getNum_error_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_error_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool HardwareRateDriverComponentBase ::
    isConnected_CycleOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_CycleOut_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_CycleOut_OutputPort[portNum].isConnected();
  }

  bool HardwareRateDriverComponentBase ::
    isConnected_error_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_error_OutputPorts(),
        static_cast<FwAssertArgType>(portNum)
     );
     return this->m_error_OutputPort[portNum].isConnected();
  }

} // end namespace Arduino
