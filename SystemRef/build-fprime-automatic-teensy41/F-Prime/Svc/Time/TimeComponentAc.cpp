// ======================================================================
// \title  TimeComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for Time component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/Time/TimeComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputTimePort *TimeComponentBase ::
    get_timeGetPort_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_timeGetPort_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_timeGetPort_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    TimeComponentBase :: TimeComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void TimeComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port timeGetPort
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_timeGetPort_InputPorts());
        port++
    ) {

      this->m_timeGetPort_InputPort[port].init();
      this->m_timeGetPort_InputPort[port].addCallComp(
          this,
          m_p_timeGetPort_in
      );
      this->m_timeGetPort_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_timeGetPort_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_timeGetPort_InputPort[port].setObjName(portName);
#endif

    }


  }

  TimeComponentBase::
    ~TimeComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE TimeComponentBase ::
    getNum_timeGetPort_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_timeGetPort_InputPort));
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void TimeComponentBase ::
    m_p_timeGetPort_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Time &time
    )
  {
    FW_ASSERT(callComp);
    TimeComponentBase* compPtr = static_cast<TimeComponentBase*>(callComp);
    compPtr->timeGetPort_handlerBase(portNum, time);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void TimeComponentBase ::
    timeGetPort_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Time &time
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_timeGetPort_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->timeGetPort_handler(portNum, time);

  }

} // end namespace Svc
