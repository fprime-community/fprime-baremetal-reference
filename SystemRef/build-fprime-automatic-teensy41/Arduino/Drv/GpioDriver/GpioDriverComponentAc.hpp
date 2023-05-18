// ======================================================================
// \title  GpioDriverComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for GpioDriver component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef ARDUINO_GPIODRIVER_COMP_HPP_
#define ARDUINO_GPIODRIVER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Types/LogicEnumAc.hpp>
#include <Drv/GpioDriverPorts/GpioReadPortAc.hpp>
#include <Drv/GpioDriverPorts/GpioWritePortAc.hpp>

namespace Arduino {

  //! \class GpioDriverComponentBase
  //! \brief Auto-generated base for GpioDriver component
  //!
  class GpioDriverComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class GpioDriverComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return gpioRead[portNum]
    //!
    Drv::InputGpioReadPort* get_gpioRead_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return gpioWrite[portNum]
    //!
    Drv::InputGpioWritePort* get_gpioWrite_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a GpioDriverComponentBase object
    //!
    GpioDriverComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a GpioDriverComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a GpioDriverComponentBase object
    //!
    virtual ~GpioDriverComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port gpioRead
    //
    virtual void gpioRead_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Logic &state 
    ) = 0;

    //! Handler for input port gpioWrite
    //
    virtual void gpioWrite_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        const Fw::Logic &state 
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port gpioRead
    //!
    void gpioRead_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Logic &state 
    );

    //! Handler base-class function for input port gpioWrite
    //!
    void gpioWrite_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        const Fw::Logic &state 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of gpioRead input ports
    //!
    //! \return The number of gpioRead input ports
    //!
    NATIVE_INT_TYPE getNum_gpioRead_InputPorts();

    //! Get the number of gpioWrite input ports
    //!
    //! \return The number of gpioWrite input ports
    //!
    NATIVE_INT_TYPE getNum_gpioWrite_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_GPIOREAD_INPUT_PORTS = 1,
       NUM_GPIOWRITE_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port gpioRead
    //!
    Drv::InputGpioReadPort m_gpioRead_InputPort[NUM_GPIOREAD_INPUT_PORTS];

    //! Input port gpioWrite
    //!
    Drv::InputGpioWritePort m_gpioWrite_InputPort[NUM_GPIOWRITE_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port gpioRead
    //!
    static void m_p_gpioRead_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Logic &state 
    );

    //! Callback for port gpioWrite
    //!
    static void m_p_gpioWrite_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        const Fw::Logic &state 
    );



  };

} // end namespace Arduino
#endif
