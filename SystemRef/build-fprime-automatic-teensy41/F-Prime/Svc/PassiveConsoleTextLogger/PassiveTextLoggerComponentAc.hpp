// ======================================================================
// \title  PassiveTextLoggerComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for PassiveTextLogger component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_PASSIVETEXTLOGGER_COMP_HPP_
#define SVC_PASSIVETEXTLOGGER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif

namespace Svc {

  //! \class PassiveTextLoggerComponentBase
  //! \brief Auto-generated base for PassiveTextLogger component
  //!
  class PassiveTextLoggerComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class PassiveTextLoggerComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return TextLogger[portNum]
    //!
    Fw::InputLogTextPort* get_TextLogger_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a PassiveTextLoggerComponentBase object
    //!
    PassiveTextLoggerComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a PassiveTextLoggerComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a PassiveTextLoggerComponentBase object
    //!
    virtual ~PassiveTextLoggerComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port TextLogger
    //
    virtual void TextLogger_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwEventIdType id, /*!< 
      Log ID
      */
        Fw::Time &timeTag, /*!< 
      Time Tag
      */
        const Fw::LogSeverity &severity, /*!< 
      The severity argument
      */
        Fw::TextLogString &text /*!< 
      Text of log message
      */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port TextLogger
    //!
    void TextLogger_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwEventIdType id, /*!< 
      Log ID
      */
        Fw::Time &timeTag, /*!< 
      Time Tag
      */
        const Fw::LogSeverity &severity, /*!< 
      The severity argument
      */
        Fw::TextLogString &text /*!< 
      Text of log message
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of TextLogger input ports
    //!
    //! \return The number of TextLogger input ports
    //!
    NATIVE_INT_TYPE getNum_TextLogger_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_TEXTLOGGER_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port TextLogger
    //!
    Fw::InputLogTextPort m_TextLogger_InputPort[NUM_TEXTLOGGER_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port TextLogger
    //!
    static void m_p_TextLogger_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwEventIdType id, /*!< 
      Log ID
      */
        Fw::Time &timeTag, /*!< 
      Time Tag
      */
        const Fw::LogSeverity &severity, /*!< 
      The severity argument
      */
        Fw::TextLogString &text /*!< 
      Text of log message
      */
    );



  };

} // end namespace Svc
#endif
