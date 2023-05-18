// ======================================================================
// \title  DeframerComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for Deframer component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_DEFRAMER_COMP_HPP_
#define SVC_DEFRAMER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Os/Mutex.hpp>
#include <Drv/ByteStreamDriverModel/PollStatusEnumAc.hpp>
#include <Drv/ByteStreamDriverModel/RecvStatusEnumAc.hpp>
#include <Fw/Cmd/CmdResponseEnumAc.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Com/ComBuffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Com/ComBuffer.hpp>
#include <Drv/ByteStreamDriverModel/ByteStreamPollPortAc.hpp>
#include <Drv/ByteStreamDriverModel/ByteStreamRecvPortAc.hpp>
#include <Fw/Buffer/BufferGetPortAc.hpp>
#include <Fw/Buffer/BufferSendPortAc.hpp>
#include <Fw/Cmd/CmdResponsePortAc.hpp>
#include <Fw/Com/ComPortAc.hpp>
#include <Svc/Sched/SchedPortAc.hpp>

namespace Svc {

  //! \class DeframerComponentBase
  //! \brief Auto-generated base for Deframer component
  //!
  class DeframerComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class DeframerComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return cmdResponseIn[portNum]
    //!
    Fw::InputCmdResponsePort* get_cmdResponseIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return framedIn[portNum]
    //!
    Drv::InputByteStreamRecvPort* get_framedIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return schedIn[portNum]
    //!
    Svc::InputSchedPort* get_schedIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to bufferAllocate[portNum]
    //!
    void set_bufferAllocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferGetPort *port /*!< The port*/
    );

    //! Connect port to bufferDeallocate[portNum]
    //!
    void set_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to bufferOut[portNum]
    //!
    void set_bufferOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to comOut[portNum]
    //!
    void set_comOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputComPort *port /*!< The port*/
    );

    //! Connect port to framedDeallocate[portNum]
    //!
    void set_framedDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to framedPoll[portNum]
    //!
    void set_framedPoll_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::InputByteStreamPollPort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to bufferAllocate[portNum]
    //!
    void set_bufferAllocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to bufferDeallocate[portNum]
    //!
    void set_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to bufferOut[portNum]
    //!
    void set_bufferOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to comOut[portNum]
    //!
    void set_comOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to framedDeallocate[portNum]
    //!
    void set_framedDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to framedPoll[portNum]
    //!
    void set_framedPoll_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a DeframerComponentBase object
    //!
    DeframerComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a DeframerComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a DeframerComponentBase object
    //!
    virtual ~DeframerComponentBase();

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

    //! Handler for input port cmdResponseIn
    //
    virtual void cmdResponseIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwOpcodeType opCode, /*!< 
      Command Op Code
      */
        U32 cmdSeq, /*!< 
      Command Sequence
      */
        const Fw::CmdResponse &response /*!< 
      The command response argument
      */
    ) = 0;

    //! Handler for input port framedIn
    //
    virtual void framedIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &recvBuffer, 
        const Drv::RecvStatus &recvStatus 
    ) = 0;

    //! Handler for input port schedIn
    //
    virtual void schedIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port cmdResponseIn
    //!
    void cmdResponseIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwOpcodeType opCode, /*!< 
      Command Op Code
      */
        U32 cmdSeq, /*!< 
      Command Sequence
      */
        const Fw::CmdResponse &response /*!< 
      The command response argument
      */
    );

    //! Handler base-class function for input port framedIn
    //!
    void framedIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &recvBuffer, 
        const Drv::RecvStatus &recvStatus 
    );

    //! Handler base-class function for input port schedIn
    //!
    void schedIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port bufferAllocate
    //!
    Fw::Buffer bufferAllocate_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 size 
    );

    //! Invoke output port bufferDeallocate
    //!
    void bufferDeallocate_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Invoke output port bufferOut
    //!
    void bufferOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Invoke output port comOut
    //!
    void comOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::ComBuffer &data, /*!< 
      Buffer containing packet data
      */
        U32 context /*!< 
      Call context value; meaning chosen by user
      */
    );

    //! Invoke output port framedDeallocate
    //!
    void framedDeallocate_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Invoke output port framedPoll
    //!
    Drv::PollStatus framedPoll_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &pollBuffer 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of cmdResponseIn input ports
    //!
    //! \return The number of cmdResponseIn input ports
    //!
    NATIVE_INT_TYPE getNum_cmdResponseIn_InputPorts();

    //! Get the number of framedIn input ports
    //!
    //! \return The number of framedIn input ports
    //!
    NATIVE_INT_TYPE getNum_framedIn_InputPorts();

    //! Get the number of schedIn input ports
    //!
    //! \return The number of schedIn input ports
    //!
    NATIVE_INT_TYPE getNum_schedIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_CMDRESPONSEIN_INPUT_PORTS = 1,
       NUM_FRAMEDIN_INPUT_PORTS = 1,
       NUM_SCHEDIN_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of bufferAllocate output ports
    //!
    //! \return The number of bufferAllocate output ports
    //!
    NATIVE_INT_TYPE getNum_bufferAllocate_OutputPorts();

    //! Get the number of bufferDeallocate output ports
    //!
    //! \return The number of bufferDeallocate output ports
    //!
    NATIVE_INT_TYPE getNum_bufferDeallocate_OutputPorts();

    //! Get the number of bufferOut output ports
    //!
    //! \return The number of bufferOut output ports
    //!
    NATIVE_INT_TYPE getNum_bufferOut_OutputPorts();

    //! Get the number of comOut output ports
    //!
    //! \return The number of comOut output ports
    //!
    NATIVE_INT_TYPE getNum_comOut_OutputPorts();

    //! Get the number of framedDeallocate output ports
    //!
    //! \return The number of framedDeallocate output ports
    //!
    NATIVE_INT_TYPE getNum_framedDeallocate_OutputPorts();

    //! Get the number of framedPoll output ports
    //!
    //! \return The number of framedPoll output ports
    //!
    NATIVE_INT_TYPE getNum_framedPoll_OutputPorts();


    enum {
       NUM_BUFFERALLOCATE_OUTPUT_PORTS = 1,
       NUM_BUFFERDEALLOCATE_OUTPUT_PORTS = 1,
       NUM_BUFFEROUT_OUTPUT_PORTS = 1,
       NUM_COMOUT_OUTPUT_PORTS = 1,
       NUM_FRAMEDDEALLOCATE_OUTPUT_PORTS = 1,
       NUM_FRAMEDPOLL_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port bufferAllocate is connected
    //!
    //! \return Whether port bufferAllocate is connected
    //!
    bool isConnected_bufferAllocate_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port bufferDeallocate is connected
    //!
    //! \return Whether port bufferDeallocate is connected
    //!
    bool isConnected_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port bufferOut is connected
    //!
    //! \return Whether port bufferOut is connected
    //!
    bool isConnected_bufferOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port comOut is connected
    //!
    //! \return Whether port comOut is connected
    //!
    bool isConnected_comOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port framedDeallocate is connected
    //!
    //! \return Whether port framedDeallocate is connected
    //!
    bool isConnected_framedDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port framedPoll is connected
    //!
    //! \return Whether port framedPoll is connected
    //!
    bool isConnected_framedPoll_OutputPort(
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

    //! Input port cmdResponseIn
    //!
    Fw::InputCmdResponsePort m_cmdResponseIn_InputPort[NUM_CMDRESPONSEIN_INPUT_PORTS];

    //! Input port framedIn
    //!
    Drv::InputByteStreamRecvPort m_framedIn_InputPort[NUM_FRAMEDIN_INPUT_PORTS];

    //! Input port schedIn
    //!
    Svc::InputSchedPort m_schedIn_InputPort[NUM_SCHEDIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port bufferAllocate
    //!
    Fw::OutputBufferGetPort m_bufferAllocate_OutputPort[NUM_BUFFERALLOCATE_OUTPUT_PORTS];

    //! Output port bufferDeallocate
    //!
    Fw::OutputBufferSendPort m_bufferDeallocate_OutputPort[NUM_BUFFERDEALLOCATE_OUTPUT_PORTS];

    //! Output port bufferOut
    //!
    Fw::OutputBufferSendPort m_bufferOut_OutputPort[NUM_BUFFEROUT_OUTPUT_PORTS];

    //! Output port comOut
    //!
    Fw::OutputComPort m_comOut_OutputPort[NUM_COMOUT_OUTPUT_PORTS];

    //! Output port framedDeallocate
    //!
    Fw::OutputBufferSendPort m_framedDeallocate_OutputPort[NUM_FRAMEDDEALLOCATE_OUTPUT_PORTS];

    //! Output port framedPoll
    //!
    Drv::OutputByteStreamPollPort m_framedPoll_OutputPort[NUM_FRAMEDPOLL_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port cmdResponseIn
    //!
    static void m_p_cmdResponseIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwOpcodeType opCode, /*!< 
      Command Op Code
      */
        U32 cmdSeq, /*!< 
      Command Sequence
      */
        const Fw::CmdResponse &response /*!< 
      The command response argument
      */
    );

    //! Callback for port framedIn
    //!
    static void m_p_framedIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &recvBuffer, 
        const Drv::RecvStatus &recvStatus 
    );

    //! Callback for port schedIn
    //!
    static void m_p_schedIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
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
