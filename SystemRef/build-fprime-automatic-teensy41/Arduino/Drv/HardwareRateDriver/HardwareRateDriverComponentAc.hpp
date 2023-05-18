// ======================================================================
// \title  HardwareRateDriverComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for HardwareRateDriver component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef ARDUINO_HARDWARERATEDRIVER_COMP_HPP_
#define ARDUINO_HARDWARERATEDRIVER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Types/LogicEnumAc.hpp>
#include <Svc/Cycle/TimerVal.hpp>
#include <Svc/Cycle/TimerVal.hpp>
#include <Drv/GpioDriverPorts/GpioWritePortAc.hpp>
#include <Svc/Cycle/CyclePortAc.hpp>

namespace Arduino {

  //! \class HardwareRateDriverComponentBase
  //! \brief Auto-generated base for HardwareRateDriver component
  //!
  class HardwareRateDriverComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class HardwareRateDriverComponentBaseFriend;

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

    //! Connect port to error[portNum]
    //!
    void set_error_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::InputGpioWritePort *port /*!< The port*/
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

    //! Connect port to error[portNum]
    //!
    void set_error_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a HardwareRateDriverComponentBase object
    //!
    HardwareRateDriverComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a HardwareRateDriverComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a HardwareRateDriverComponentBase object
    //!
    virtual ~HardwareRateDriverComponentBase();

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

    //! Invoke output port error
    //!
    void error_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        const Fw::Logic &state 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of CycleOut output ports
    //!
    //! \return The number of CycleOut output ports
    //!
    NATIVE_INT_TYPE getNum_CycleOut_OutputPorts();

    //! Get the number of error output ports
    //!
    //! \return The number of error output ports
    //!
    NATIVE_INT_TYPE getNum_error_OutputPorts();


    enum {
       NUM_CYCLEOUT_OUTPUT_PORTS = 1,
       NUM_ERROR_OUTPUT_PORTS = 1,
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

    //! Check whether port error is connected
    //!
    //! \return Whether port error is connected
    //!
    bool isConnected_error_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------


  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port CycleOut
    //!
    Svc::OutputCyclePort m_CycleOut_OutputPort[NUM_CYCLEOUT_OUTPUT_PORTS];

    //! Output port error
    //!
    Drv::OutputGpioWritePort m_error_OutputPort[NUM_ERROR_OUTPUT_PORTS];



  };

} // end namespace Arduino
#endif
