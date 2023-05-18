// ======================================================================
// \title  StaticMemoryComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for StaticMemory component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/StaticMemory/StaticMemoryComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputBufferGetPort *StaticMemoryComponentBase ::
    get_bufferAllocate_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_bufferAllocate_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_bufferAllocate_InputPort[portNum];
  }

  Fw::InputBufferSendPort *StaticMemoryComponentBase ::
    get_bufferDeallocate_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_bufferDeallocate_InputPorts(),static_cast<FwAssertArgType>(portNum));
    return &this->m_bufferDeallocate_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    StaticMemoryComponentBase :: StaticMemoryComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void StaticMemoryComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port bufferAllocate
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_bufferAllocate_InputPorts());
        port++
    ) {

      this->m_bufferAllocate_InputPort[port].init();
      this->m_bufferAllocate_InputPort[port].addCallComp(
          this,
          m_p_bufferAllocate_in
      );
      this->m_bufferAllocate_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_bufferAllocate_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_bufferAllocate_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port bufferDeallocate
    for (
        PlatformIntType port = 0;
        port < static_cast<PlatformIntType>(this->getNum_bufferDeallocate_InputPorts());
        port++
    ) {

      this->m_bufferDeallocate_InputPort[port].init();
      this->m_bufferDeallocate_InputPort[port].addCallComp(
          this,
          m_p_bufferDeallocate_in
      );
      this->m_bufferDeallocate_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_bufferDeallocate_InputPort[%" PRI_PlatformIntType "]",
          this->m_objName,
          port
      );
      this->m_bufferDeallocate_InputPort[port].setObjName(portName);
#endif

    }


  }

  StaticMemoryComponentBase::
    ~StaticMemoryComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE StaticMemoryComponentBase ::
    getNum_bufferAllocate_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_bufferAllocate_InputPort));
  }

  NATIVE_INT_TYPE StaticMemoryComponentBase ::
    getNum_bufferDeallocate_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_bufferDeallocate_InputPort));
  }

  // ----------------------------------------------------------------------
  // Mutex functions for guarded ports
  // ----------------------------------------------------------------------

  void StaticMemoryComponentBase ::
    lock()
  {
    this->m_guardedPortMutex.lock();
  }

  void StaticMemoryComponentBase ::
    unLock()
  {
    this->m_guardedPortMutex.unLock();
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  Fw::Buffer StaticMemoryComponentBase ::
    m_p_bufferAllocate_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        U32 size
    )
  {
    FW_ASSERT(callComp);
    StaticMemoryComponentBase* compPtr = static_cast<StaticMemoryComponentBase*>(callComp);
    return compPtr->bufferAllocate_handlerBase(portNum, size);
  }

  void StaticMemoryComponentBase ::
    m_p_bufferDeallocate_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(callComp);
    StaticMemoryComponentBase* compPtr = static_cast<StaticMemoryComponentBase*>(callComp);
    compPtr->bufferDeallocate_handlerBase(portNum, fwBuffer);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  Fw::Buffer StaticMemoryComponentBase ::
    bufferAllocate_handlerBase(
        NATIVE_INT_TYPE portNum,
        U32 size
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_bufferAllocate_InputPorts(),static_cast<FwAssertArgType>(portNum));
    Fw::Buffer  retVal;

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    retVal = this->bufferAllocate_handler(portNum, size);

    // Unlock guard mutex
    this->unLock();

    return retVal;

  }

  void StaticMemoryComponentBase ::
    bufferDeallocate_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_bufferDeallocate_InputPorts(),static_cast<FwAssertArgType>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->bufferDeallocate_handler(portNum, fwBuffer);

    // Unlock guard mutex
    this->unLock();

  }

} // end namespace Svc
