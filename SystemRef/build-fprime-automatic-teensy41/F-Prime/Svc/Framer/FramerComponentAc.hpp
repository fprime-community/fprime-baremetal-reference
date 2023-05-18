// ======================================================================
// \title  FramerComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for Framer component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_FRAMER_COMP_HPP_
#define SVC_FRAMER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Os/Mutex.hpp>
#include <Drv/ByteStreamDriverModel/SendStatusEnumAc.hpp>
#include <Fw/Types/SuccessEnumAc.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Com/ComBuffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Com/ComBuffer.hpp>
#include <Drv/ByteStreamDriverModel/ByteStreamSendPortAc.hpp>
#include <Fw/Buffer/BufferGetPortAc.hpp>
#include <Fw/Buffer/BufferSendPortAc.hpp>
#include <Fw/Com/ComPortAc.hpp>
#include <Fw/Ports/SuccessCondition/SuccessConditionPortAc.hpp>

namespace Svc {

  //! \class FramerComponentBase
  //! \brief Auto-generated base for Framer component
  //!
  class FramerComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class FramerComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return bufferIn[portNum]
    //!
    Fw::InputBufferSendPort* get_bufferIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return comIn[portNum]
    //!
    Fw::InputComPort* get_comIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return comStatusIn[portNum]
    //!
    Fw::InputSuccessConditionPort* get_comStatusIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to bufferDeallocate[portNum]
    //!
    void set_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to comStatusOut[portNum]
    //!
    void set_comStatusOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSuccessConditionPort *port /*!< The port*/
    );

    //! Connect port to framedAllocate[portNum]
    //!
    void set_framedAllocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferGetPort *port /*!< The port*/
    );

    //! Connect port to framedOut[portNum]
    //!
    void set_framedOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::InputByteStreamSendPort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to bufferDeallocate[portNum]
    //!
    void set_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to comStatusOut[portNum]
    //!
    void set_comStatusOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to framedAllocate[portNum]
    //!
    void set_framedAllocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to framedOut[portNum]
    //!
    void set_framedOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a FramerComponentBase object
    //!
    FramerComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a FramerComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a FramerComponentBase object
    //!
    virtual ~FramerComponentBase();

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

    //! Handler for input port bufferIn
    //
    virtual void bufferIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    ) = 0;

    //! Handler for input port comIn
    //
    virtual void comIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::ComBuffer &data, /*!< 
      Buffer containing packet data
      */
        U32 context /*!< 
      Call context value; meaning chosen by user
      */
    ) = 0;

    //! Handler for input port comStatusIn
    //
    virtual void comStatusIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Success &condition /*!< 
      Condition success/failure
      */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port bufferIn
    //!
    void bufferIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Handler base-class function for input port comIn
    //!
    void comIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::ComBuffer &data, /*!< 
      Buffer containing packet data
      */
        U32 context /*!< 
      Call context value; meaning chosen by user
      */
    );

    //! Handler base-class function for input port comStatusIn
    //!
    void comStatusIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Success &condition /*!< 
      Condition success/failure
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port bufferDeallocate
    //!
    void bufferDeallocate_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Invoke output port comStatusOut
    //!
    void comStatusOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Success &condition /*!< 
      Condition success/failure
      */
    );

    //! Invoke output port framedAllocate
    //!
    Fw::Buffer framedAllocate_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 size 
    );

    //! Invoke output port framedOut
    //!
    Drv::SendStatus framedOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &sendBuffer 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of bufferIn input ports
    //!
    //! \return The number of bufferIn input ports
    //!
    NATIVE_INT_TYPE getNum_bufferIn_InputPorts();

    //! Get the number of comIn input ports
    //!
    //! \return The number of comIn input ports
    //!
    NATIVE_INT_TYPE getNum_comIn_InputPorts();

    //! Get the number of comStatusIn input ports
    //!
    //! \return The number of comStatusIn input ports
    //!
    NATIVE_INT_TYPE getNum_comStatusIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_BUFFERIN_INPUT_PORTS = 1,
       NUM_COMIN_INPUT_PORTS = 1,
       NUM_COMSTATUSIN_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of bufferDeallocate output ports
    //!
    //! \return The number of bufferDeallocate output ports
    //!
    NATIVE_INT_TYPE getNum_bufferDeallocate_OutputPorts();

    //! Get the number of comStatusOut output ports
    //!
    //! \return The number of comStatusOut output ports
    //!
    NATIVE_INT_TYPE getNum_comStatusOut_OutputPorts();

    //! Get the number of framedAllocate output ports
    //!
    //! \return The number of framedAllocate output ports
    //!
    NATIVE_INT_TYPE getNum_framedAllocate_OutputPorts();

    //! Get the number of framedOut output ports
    //!
    //! \return The number of framedOut output ports
    //!
    NATIVE_INT_TYPE getNum_framedOut_OutputPorts();


    enum {
       NUM_BUFFERDEALLOCATE_OUTPUT_PORTS = 1,
       NUM_COMSTATUSOUT_OUTPUT_PORTS = 1,
       NUM_FRAMEDALLOCATE_OUTPUT_PORTS = 1,
       NUM_FRAMEDOUT_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port bufferDeallocate is connected
    //!
    //! \return Whether port bufferDeallocate is connected
    //!
    bool isConnected_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port comStatusOut is connected
    //!
    //! \return Whether port comStatusOut is connected
    //!
    bool isConnected_comStatusOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port framedAllocate is connected
    //!
    //! \return Whether port framedAllocate is connected
    //!
    bool isConnected_framedAllocate_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port framedOut is connected
    //!
    //! \return Whether port framedOut is connected
    //!
    bool isConnected_framedOut_OutputPort(
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

    //! Input port bufferIn
    //!
    Fw::InputBufferSendPort m_bufferIn_InputPort[NUM_BUFFERIN_INPUT_PORTS];

    //! Input port comIn
    //!
    Fw::InputComPort m_comIn_InputPort[NUM_COMIN_INPUT_PORTS];

    //! Input port comStatusIn
    //!
    Fw::InputSuccessConditionPort m_comStatusIn_InputPort[NUM_COMSTATUSIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port bufferDeallocate
    //!
    Fw::OutputBufferSendPort m_bufferDeallocate_OutputPort[NUM_BUFFERDEALLOCATE_OUTPUT_PORTS];

    //! Output port comStatusOut
    //!
    Fw::OutputSuccessConditionPort m_comStatusOut_OutputPort[NUM_COMSTATUSOUT_OUTPUT_PORTS];

    //! Output port framedAllocate
    //!
    Fw::OutputBufferGetPort m_framedAllocate_OutputPort[NUM_FRAMEDALLOCATE_OUTPUT_PORTS];

    //! Output port framedOut
    //!
    Drv::OutputByteStreamSendPort m_framedOut_OutputPort[NUM_FRAMEDOUT_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port bufferIn
    //!
    static void m_p_bufferIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Callback for port comIn
    //!
    static void m_p_comIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::ComBuffer &data, /*!< 
      Buffer containing packet data
      */
        U32 context /*!< 
      Call context value; meaning chosen by user
      */
    );

    //! Callback for port comStatusIn
    //!
    static void m_p_comStatusIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Success &condition /*!< 
      Condition success/failure
      */
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
