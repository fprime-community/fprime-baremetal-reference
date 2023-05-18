// ======================================================================
// \title  FatalHandlerComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for FatalHandler component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_FATALHANDLER_COMP_HPP_
#define SVC_FATALHANDLER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Svc/Fatal/FatalEventPortAc.hpp>

namespace Svc {

  //! \class FatalHandlerComponentBase
  //! \brief Auto-generated base for FatalHandler component
  //!
  class FatalHandlerComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class FatalHandlerComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return FatalReceive[portNum]
    //!
    Svc::InputFatalEventPort* get_FatalReceive_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a FatalHandlerComponentBase object
    //!
    FatalHandlerComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a FatalHandlerComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a FatalHandlerComponentBase object
    //!
    virtual ~FatalHandlerComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port FatalReceive
    //
    virtual void FatalReceive_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwEventIdType Id /*!< 
      The ID of the FATAL event
      */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port FatalReceive
    //!
    void FatalReceive_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwEventIdType Id /*!< 
      The ID of the FATAL event
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of FatalReceive input ports
    //!
    //! \return The number of FatalReceive input ports
    //!
    NATIVE_INT_TYPE getNum_FatalReceive_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_FATALRECEIVE_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port FatalReceive
    //!
    Svc::InputFatalEventPort m_FatalReceive_InputPort[NUM_FATALRECEIVE_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port FatalReceive
    //!
    static void m_p_FatalReceive_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwEventIdType Id /*!< 
      The ID of the FATAL event
      */
    );



  };

} // end namespace Svc
#endif
