// ======================================================================
// \title  ComStubComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for ComStub component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_COMSTUB_COMP_HPP_
#define SVC_COMSTUB_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Drv/ByteStreamDriverModel/RecvStatusEnumAc.hpp>
#include <Drv/ByteStreamDriverModel/SendStatusEnumAc.hpp>
#include <Fw/Types/SuccessEnumAc.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Drv/ByteStreamDriverModel/ByteStreamReadyPortAc.hpp>
#include <Drv/ByteStreamDriverModel/ByteStreamRecvPortAc.hpp>
#include <Drv/ByteStreamDriverModel/ByteStreamSendPortAc.hpp>
#include <Fw/Ports/SuccessCondition/SuccessConditionPortAc.hpp>

namespace Svc {

  //! \class ComStubComponentBase
  //! \brief Auto-generated base for ComStub component
  //!
  class ComStubComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class ComStubComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return comDataIn[portNum]
    //!
    Drv::InputByteStreamSendPort* get_comDataIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return drvConnected[portNum]
    //!
    Drv::InputByteStreamReadyPort* get_drvConnected_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return drvDataIn[portNum]
    //!
    Drv::InputByteStreamRecvPort* get_drvDataIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to comDataOut[portNum]
    //!
    void set_comDataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::InputByteStreamRecvPort *port /*!< The port*/
    );

    //! Connect port to comStatus[portNum]
    //!
    void set_comStatus_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSuccessConditionPort *port /*!< The port*/
    );

    //! Connect port to drvDataOut[portNum]
    //!
    void set_drvDataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::InputByteStreamSendPort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to comDataOut[portNum]
    //!
    void set_comDataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to comStatus[portNum]
    //!
    void set_comStatus_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to drvDataOut[portNum]
    //!
    void set_drvDataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a ComStubComponentBase object
    //!
    ComStubComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a ComStubComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a ComStubComponentBase object
    //!
    virtual ~ComStubComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port comDataIn
    //
    virtual Drv::SendStatus comDataIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &sendBuffer 
    ) = 0;

    //! Handler for input port drvConnected
    //
    virtual void drvConnected_handler(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    ) = 0;

    //! Handler for input port drvDataIn
    //
    virtual void drvDataIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &recvBuffer, 
        const Drv::RecvStatus &recvStatus 
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port comDataIn
    //!
    Drv::SendStatus comDataIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &sendBuffer 
    );

    //! Handler base-class function for input port drvConnected
    //!
    void drvConnected_handlerBase(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Handler base-class function for input port drvDataIn
    //!
    void drvDataIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &recvBuffer, 
        const Drv::RecvStatus &recvStatus 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port comDataOut
    //!
    void comDataOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &recvBuffer, 
        const Drv::RecvStatus &recvStatus 
    );

    //! Invoke output port comStatus
    //!
    void comStatus_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Success &condition /*!< 
      Condition success/failure
      */
    );

    //! Invoke output port drvDataOut
    //!
    Drv::SendStatus drvDataOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &sendBuffer 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of comDataIn input ports
    //!
    //! \return The number of comDataIn input ports
    //!
    NATIVE_INT_TYPE getNum_comDataIn_InputPorts();

    //! Get the number of drvConnected input ports
    //!
    //! \return The number of drvConnected input ports
    //!
    NATIVE_INT_TYPE getNum_drvConnected_InputPorts();

    //! Get the number of drvDataIn input ports
    //!
    //! \return The number of drvDataIn input ports
    //!
    NATIVE_INT_TYPE getNum_drvDataIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_COMDATAIN_INPUT_PORTS = 1,
       NUM_DRVCONNECTED_INPUT_PORTS = 1,
       NUM_DRVDATAIN_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of comDataOut output ports
    //!
    //! \return The number of comDataOut output ports
    //!
    NATIVE_INT_TYPE getNum_comDataOut_OutputPorts();

    //! Get the number of comStatus output ports
    //!
    //! \return The number of comStatus output ports
    //!
    NATIVE_INT_TYPE getNum_comStatus_OutputPorts();

    //! Get the number of drvDataOut output ports
    //!
    //! \return The number of drvDataOut output ports
    //!
    NATIVE_INT_TYPE getNum_drvDataOut_OutputPorts();


    enum {
       NUM_COMDATAOUT_OUTPUT_PORTS = 1,
       NUM_COMSTATUS_OUTPUT_PORTS = 1,
       NUM_DRVDATAOUT_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port comDataOut is connected
    //!
    //! \return Whether port comDataOut is connected
    //!
    bool isConnected_comDataOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port comStatus is connected
    //!
    //! \return Whether port comStatus is connected
    //!
    bool isConnected_comStatus_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port drvDataOut is connected
    //!
    //! \return Whether port drvDataOut is connected
    //!
    bool isConnected_drvDataOut_OutputPort(
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

    //! Input port comDataIn
    //!
    Drv::InputByteStreamSendPort m_comDataIn_InputPort[NUM_COMDATAIN_INPUT_PORTS];

    //! Input port drvConnected
    //!
    Drv::InputByteStreamReadyPort m_drvConnected_InputPort[NUM_DRVCONNECTED_INPUT_PORTS];

    //! Input port drvDataIn
    //!
    Drv::InputByteStreamRecvPort m_drvDataIn_InputPort[NUM_DRVDATAIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port comDataOut
    //!
    Drv::OutputByteStreamRecvPort m_comDataOut_OutputPort[NUM_COMDATAOUT_OUTPUT_PORTS];

    //! Output port comStatus
    //!
    Fw::OutputSuccessConditionPort m_comStatus_OutputPort[NUM_COMSTATUS_OUTPUT_PORTS];

    //! Output port drvDataOut
    //!
    Drv::OutputByteStreamSendPort m_drvDataOut_OutputPort[NUM_DRVDATAOUT_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port comDataIn
    //!
    static Drv::SendStatus m_p_comDataIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &sendBuffer 
    );

    //! Callback for port drvConnected
    //!
    static void m_p_drvConnected_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Callback for port drvDataIn
    //!
    static void m_p_drvDataIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &recvBuffer, 
        const Drv::RecvStatus &recvStatus 
    );



  };

} // end namespace Svc
#endif
