// ======================================================================
// \title  ByteStreamDriverModelComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for ByteStreamDriverModel component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef DRV_BYTESTREAMDRIVERMODEL_COMP_HPP_
#define DRV_BYTESTREAMDRIVERMODEL_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Os/Mutex.hpp>
#include <Drv/ByteStreamDriverModel/PollStatusEnumAc.hpp>
#include <Drv/ByteStreamDriverModel/RecvStatusEnumAc.hpp>
#include <Drv/ByteStreamDriverModel/SendStatusEnumAc.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Drv/ByteStreamDriverModel/ByteStreamPollPortAc.hpp>
#include <Drv/ByteStreamDriverModel/ByteStreamReadyPortAc.hpp>
#include <Drv/ByteStreamDriverModel/ByteStreamRecvPortAc.hpp>
#include <Drv/ByteStreamDriverModel/ByteStreamSendPortAc.hpp>
#include <Fw/Buffer/BufferGetPortAc.hpp>
#include <Fw/Buffer/BufferSendPortAc.hpp>

namespace Drv {

  //! \class ByteStreamDriverModelComponentBase
  //! \brief Auto-generated base for ByteStreamDriverModel component
  //!
  class ByteStreamDriverModelComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class ByteStreamDriverModelComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return poll[portNum]
    //!
    Drv::InputByteStreamPollPort* get_poll_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return send[portNum]
    //!
    Drv::InputByteStreamSendPort* get_send_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to allocate[portNum]
    //!
    void set_allocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferGetPort *port /*!< The port*/
    );

    //! Connect port to deallocate[portNum]
    //!
    void set_deallocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to ready[portNum]
    //!
    void set_ready_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::InputByteStreamReadyPort *port /*!< The port*/
    );

    //! Connect port to recv[portNum]
    //!
    void set_recv_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::InputByteStreamRecvPort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to allocate[portNum]
    //!
    void set_allocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to deallocate[portNum]
    //!
    void set_deallocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to ready[portNum]
    //!
    void set_ready_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to recv[portNum]
    //!
    void set_recv_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a ByteStreamDriverModelComponentBase object
    //!
    ByteStreamDriverModelComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a ByteStreamDriverModelComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a ByteStreamDriverModelComponentBase object
    //!
    virtual ~ByteStreamDriverModelComponentBase();

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

    //! Handler for input port poll
    //
    virtual Drv::PollStatus poll_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &pollBuffer 
    ) = 0;

    //! Handler for input port send
    //
    virtual Drv::SendStatus send_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &sendBuffer 
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port poll
    //!
    Drv::PollStatus poll_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &pollBuffer 
    );

    //! Handler base-class function for input port send
    //!
    Drv::SendStatus send_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &sendBuffer 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port allocate
    //!
    Fw::Buffer allocate_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 size 
    );

    //! Invoke output port deallocate
    //!
    void deallocate_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Invoke output port ready
    //!
    void ready_out(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Invoke output port recv
    //!
    void recv_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &recvBuffer, 
        const Drv::RecvStatus &recvStatus 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of poll input ports
    //!
    //! \return The number of poll input ports
    //!
    NATIVE_INT_TYPE getNum_poll_InputPorts();

    //! Get the number of send input ports
    //!
    //! \return The number of send input ports
    //!
    NATIVE_INT_TYPE getNum_send_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_POLL_INPUT_PORTS = 1,
       NUM_SEND_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of allocate output ports
    //!
    //! \return The number of allocate output ports
    //!
    NATIVE_INT_TYPE getNum_allocate_OutputPorts();

    //! Get the number of deallocate output ports
    //!
    //! \return The number of deallocate output ports
    //!
    NATIVE_INT_TYPE getNum_deallocate_OutputPorts();

    //! Get the number of ready output ports
    //!
    //! \return The number of ready output ports
    //!
    NATIVE_INT_TYPE getNum_ready_OutputPorts();

    //! Get the number of recv output ports
    //!
    //! \return The number of recv output ports
    //!
    NATIVE_INT_TYPE getNum_recv_OutputPorts();


    enum {
       NUM_ALLOCATE_OUTPUT_PORTS = 1,
       NUM_DEALLOCATE_OUTPUT_PORTS = 1,
       NUM_READY_OUTPUT_PORTS = 1,
       NUM_RECV_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port allocate is connected
    //!
    //! \return Whether port allocate is connected
    //!
    bool isConnected_allocate_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port deallocate is connected
    //!
    //! \return Whether port deallocate is connected
    //!
    bool isConnected_deallocate_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port ready is connected
    //!
    //! \return Whether port ready is connected
    //!
    bool isConnected_ready_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port recv is connected
    //!
    //! \return Whether port recv is connected
    //!
    bool isConnected_recv_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port poll
    //!
    Drv::InputByteStreamPollPort m_poll_InputPort[NUM_POLL_INPUT_PORTS];

    //! Input port send
    //!
    Drv::InputByteStreamSendPort m_send_InputPort[NUM_SEND_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port allocate
    //!
    Fw::OutputBufferGetPort m_allocate_OutputPort[NUM_ALLOCATE_OUTPUT_PORTS];

    //! Output port deallocate
    //!
    Fw::OutputBufferSendPort m_deallocate_OutputPort[NUM_DEALLOCATE_OUTPUT_PORTS];

    //! Output port ready
    //!
    Drv::OutputByteStreamReadyPort m_ready_OutputPort[NUM_READY_OUTPUT_PORTS];

    //! Output port recv
    //!
    Drv::OutputByteStreamRecvPort m_recv_OutputPort[NUM_RECV_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port poll
    //!
    static Drv::PollStatus m_p_poll_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &pollBuffer 
    );

    //! Callback for port send
    //!
    static Drv::SendStatus m_p_send_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &sendBuffer 
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Mutexes
    // ----------------------------------------------------------------------

    //! Mutex for guarded ports
    //!
    Os::Mutex m_guardedPortMutex;



  };

} // end namespace Drv
#endif
