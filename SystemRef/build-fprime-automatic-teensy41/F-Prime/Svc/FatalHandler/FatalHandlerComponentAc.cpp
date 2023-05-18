// ======================================================================
// \title  FatalHandlerComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for FatalHandler component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/FatalHandler/FatalHandlerComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Svc::InputFatalEventPort *FatalHandlerComponentBase ::
    get_FatalReceive_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_FatalReceive_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_FatalReceive_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    FatalHandlerComponentBase :: FatalHandlerComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void FatalHandlerComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port FatalReceive
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_FatalReceive_InputPorts());
        port++
    ) {

      this->m_FatalReceive_InputPort[port].init();
      this->m_FatalReceive_InputPort[port].addCallComp(
          this,
          m_p_FatalReceive_in
      );
      this->m_FatalReceive_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_FatalReceive_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_FatalReceive_InputPort[port].setObjName(portName);
#endif

    }


  }

  FatalHandlerComponentBase::
    ~FatalHandlerComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE FatalHandlerComponentBase ::
    getNum_FatalReceive_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_FatalReceive_InputPort));
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void FatalHandlerComponentBase ::
    m_p_FatalReceive_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        FwEventIdType Id
    )
  {
    FW_ASSERT(callComp);
    FatalHandlerComponentBase* compPtr = static_cast<FatalHandlerComponentBase*>(callComp);
    compPtr->FatalReceive_handlerBase(portNum, Id);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void FatalHandlerComponentBase ::
    FatalReceive_handlerBase(
        NATIVE_INT_TYPE portNum,
        FwEventIdType Id
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_FatalReceive_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->FatalReceive_handler(portNum, Id);

  }

} // end namespace Svc
