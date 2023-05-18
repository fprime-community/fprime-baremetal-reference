// ======================================================================
// \title  GpioDriverComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for GpioDriver component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Arduino/Drv/GpioDriver/GpioDriverComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Arduino {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Drv::InputGpioReadPort *GpioDriverComponentBase ::
    get_gpioRead_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_gpioRead_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_gpioRead_InputPort[portNum];
  }

  Drv::InputGpioWritePort *GpioDriverComponentBase ::
    get_gpioWrite_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_gpioWrite_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_gpioWrite_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    GpioDriverComponentBase :: GpioDriverComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void GpioDriverComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port gpioRead
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_gpioRead_InputPorts());
        port++
    ) {

      this->m_gpioRead_InputPort[port].init();
      this->m_gpioRead_InputPort[port].addCallComp(
          this,
          m_p_gpioRead_in
      );
      this->m_gpioRead_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_gpioRead_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_gpioRead_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port gpioWrite
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_gpioWrite_InputPorts());
        port++
    ) {

      this->m_gpioWrite_InputPort[port].init();
      this->m_gpioWrite_InputPort[port].addCallComp(
          this,
          m_p_gpioWrite_in
      );
      this->m_gpioWrite_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_gpioWrite_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_gpioWrite_InputPort[port].setObjName(portName);
#endif

    }


  }

  GpioDriverComponentBase::
    ~GpioDriverComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE GpioDriverComponentBase ::
    getNum_gpioRead_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_gpioRead_InputPort));
  }

  NATIVE_INT_TYPE GpioDriverComponentBase ::
    getNum_gpioWrite_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_gpioWrite_InputPort));
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void GpioDriverComponentBase ::
    m_p_gpioRead_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Logic &state
    )
  {
    FW_ASSERT(callComp);
    GpioDriverComponentBase* compPtr = static_cast<GpioDriverComponentBase*>(callComp);
    compPtr->gpioRead_handlerBase(portNum, state);
  }

  void GpioDriverComponentBase ::
    m_p_gpioWrite_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        const Fw::Logic &state
    )
  {
    FW_ASSERT(callComp);
    GpioDriverComponentBase* compPtr = static_cast<GpioDriverComponentBase*>(callComp);
    compPtr->gpioWrite_handlerBase(portNum, state);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void GpioDriverComponentBase ::
    gpioRead_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Logic &state
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_gpioRead_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->gpioRead_handler(portNum, state);

  }

  void GpioDriverComponentBase ::
    gpioWrite_handlerBase(
        NATIVE_INT_TYPE portNum,
        const Fw::Logic &state
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_gpioWrite_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->gpioWrite_handler(portNum, state);

  }

} // end namespace Arduino
