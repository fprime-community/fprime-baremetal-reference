// ======================================================================
// \title  RateGroupDriverComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for RateGroupDriver component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_RATEGROUPDRIVER_COMP_HPP_
#define SVC_RATEGROUPDRIVER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Svc/Cycle/TimerVal.hpp>
#include <Svc/Cycle/TimerVal.hpp>
#include <Svc/Cycle/CyclePortAc.hpp>

namespace Svc {

  //! \class RateGroupDriverComponentBase
  //! \brief Auto-generated base for RateGroupDriver component
  //!
  class RateGroupDriverComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class RateGroupDriverComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return CycleIn[portNum]
    //!
    Svc::InputCyclePort* get_CycleIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to CycleOut[portNum]
    //!
    void set_CycleOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::InputCyclePort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to CycleOut[portNum]
    //!
    void set_CycleOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a RateGroupDriverComponentBase object
    //!
    RateGroupDriverComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a RateGroupDriverComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a RateGroupDriverComponentBase object
    //!
    virtual ~RateGroupDriverComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port CycleIn
    //
    virtual void CycleIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::TimerVal &cycleStart /*!< 
      Cycle start timer value
      */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port CycleIn
    //!
    void CycleIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::TimerVal &cycleStart /*!< 
      Cycle start timer value
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port CycleOut
    //!
    void CycleOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::TimerVal &cycleStart /*!< 
      Cycle start timer value
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of CycleIn input ports
    //!
    //! \return The number of CycleIn input ports
    //!
    NATIVE_INT_TYPE getNum_CycleIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_CYCLEIN_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of CycleOut output ports
    //!
    //! \return The number of CycleOut output ports
    //!
    NATIVE_INT_TYPE getNum_CycleOut_OutputPorts();


    enum {
       NUM_CYCLEOUT_OUTPUT_PORTS = 3,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port CycleOut is connected
    //!
    //! \return Whether port CycleOut is connected
    //!
    bool isConnected_CycleOut_OutputPort(
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

    //! Input port CycleIn
    //!
    Svc::InputCyclePort m_CycleIn_InputPort[NUM_CYCLEIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port CycleOut
    //!
    Svc::OutputCyclePort m_CycleOut_OutputPort[NUM_CYCLEOUT_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port CycleIn
    //!
    static void m_p_CycleIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::TimerVal &cycleStart /*!< 
      Cycle start timer value
      */
    );



  };

} // end namespace Svc
#endif
