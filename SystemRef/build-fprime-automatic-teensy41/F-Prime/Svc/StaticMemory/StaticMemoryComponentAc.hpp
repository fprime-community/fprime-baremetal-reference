// ======================================================================
// \title  StaticMemoryComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for StaticMemory component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_STATICMEMORY_COMP_HPP_
#define SVC_STATICMEMORY_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Os/Mutex.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/BufferGetPortAc.hpp>
#include <Fw/Buffer/BufferSendPortAc.hpp>

namespace Svc {

  //! \class StaticMemoryComponentBase
  //! \brief Auto-generated base for StaticMemory component
  //!
  class StaticMemoryComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class StaticMemoryComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return bufferAllocate[portNum]
    //!
    Fw::InputBufferGetPort* get_bufferAllocate_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return bufferDeallocate[portNum]
    //!
    Fw::InputBufferSendPort* get_bufferDeallocate_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a StaticMemoryComponentBase object
    //!
    StaticMemoryComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a StaticMemoryComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a StaticMemoryComponentBase object
    //!
    virtual ~StaticMemoryComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    //! Mutex operations for guarded ports.
    // ----------------------------------------------------------------------
    //! You can override these operations to provide more sophisticated
    //! synchronization.
    // ----------------------------------------------------------------------

    //! Lock the guarded mutex
    //!
    virtual void lock();

    //! Unlock the guarded mutex
    //!
    virtual void unLock();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port bufferAllocate
    //
    virtual Fw::Buffer bufferAllocate_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 size 
    ) = 0;

    //! Handler for input port bufferDeallocate
    //
    virtual void bufferDeallocate_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port bufferAllocate
    //!
    Fw::Buffer bufferAllocate_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 size 
    );

    //! Handler base-class function for input port bufferDeallocate
    //!
    void bufferDeallocate_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of bufferAllocate input ports
    //!
    //! \return The number of bufferAllocate input ports
    //!
    NATIVE_INT_TYPE getNum_bufferAllocate_InputPorts();

    //! Get the number of bufferDeallocate input ports
    //!
    //! \return The number of bufferDeallocate input ports
    //!
    NATIVE_INT_TYPE getNum_bufferDeallocate_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_BUFFERALLOCATE_INPUT_PORTS = 4,
       NUM_BUFFERDEALLOCATE_INPUT_PORTS = 4,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port bufferAllocate
    //!
    Fw::InputBufferGetPort m_bufferAllocate_InputPort[NUM_BUFFERALLOCATE_INPUT_PORTS];

    //! Input port bufferDeallocate
    //!
    Fw::InputBufferSendPort m_bufferDeallocate_InputPort[NUM_BUFFERDEALLOCATE_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port bufferAllocate
    //!
    static Fw::Buffer m_p_bufferAllocate_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 size 
    );

    //! Callback for port bufferDeallocate
    //!
    static void m_p_bufferDeallocate_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Mutexes
    // ----------------------------------------------------------------------

    //! Mutex for guarded ports
    //!
    Os::Mutex m_guardedPortMutex;



  };

} // end namespace Svc
#endif
