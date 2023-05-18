// ======================================================================
// \title  PassiveTextLoggerComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for PassiveTextLogger component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/PassiveConsoleTextLogger/PassiveTextLoggerComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputLogTextPort *PassiveTextLoggerComponentBase ::
    get_TextLogger_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_TextLogger_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_TextLogger_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    PassiveTextLoggerComponentBase :: PassiveTextLoggerComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void PassiveTextLoggerComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port TextLogger
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_TextLogger_InputPorts());
        port++
    ) {

      this->m_TextLogger_InputPort[port].init();
      this->m_TextLogger_InputPort[port].addCallComp(
          this,
          m_p_TextLogger_in
      );
      this->m_TextLogger_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_TextLogger_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_TextLogger_InputPort[port].setObjName(portName);
#endif

    }


  }

  PassiveTextLoggerComponentBase::
    ~PassiveTextLoggerComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE PassiveTextLoggerComponentBase ::
    getNum_TextLogger_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_TextLogger_InputPort));
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void PassiveTextLoggerComponentBase ::
    m_p_TextLogger_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity &severity, Fw::TextLogString &text
    )
  {
    FW_ASSERT(callComp);
    PassiveTextLoggerComponentBase* compPtr = static_cast<PassiveTextLoggerComponentBase*>(callComp);
    compPtr->TextLogger_handlerBase(portNum, id, timeTag, severity, text);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void PassiveTextLoggerComponentBase ::
    TextLogger_handlerBase(
        NATIVE_INT_TYPE portNum,
        FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity &severity, Fw::TextLogString &text
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_TextLogger_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->TextLogger_handler(portNum, id, timeTag, severity, text);

  }

} // end namespace Svc
