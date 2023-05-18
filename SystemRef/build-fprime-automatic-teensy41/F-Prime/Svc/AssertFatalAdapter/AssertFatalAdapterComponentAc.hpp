// ======================================================================
// \title  AssertFatalAdapterComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for AssertFatalAdapter component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SVC_ASSERTFATALADAPTER_COMP_HPP_
#define SVC_ASSERTFATALADAPTER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Time/TimePortAc.hpp>

namespace Svc {

  //! \class AssertFatalAdapterComponentBase
  //! \brief Auto-generated base for AssertFatalAdapter component
  //!
  class AssertFatalAdapterComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class AssertFatalAdapterComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to Log[portNum]
    //!
    void set_Log_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogPort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogTextPort *port /*!< The port*/
    );
#endif

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTimePort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to Log[portNum]
    //!
    void set_Log_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );
#endif

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a AssertFatalAdapterComponentBase object
    //!
    AssertFatalAdapterComponentBase(
        const char* compName = "" /*!< Component name*/
    );

  public:
    //! Initialize a AssertFatalAdapterComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

  PROTECTED:
    //! Destroy a AssertFatalAdapterComponentBase object
    //!
    virtual ~AssertFatalAdapterComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of Log output ports
    //!
    //! \return The number of Log output ports
    //!
    NATIVE_INT_TYPE getNum_Log_OutputPorts();

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Get the number of LogText output ports
    //!
    //! \return The number of LogText output ports
    //!
    NATIVE_INT_TYPE getNum_LogText_OutputPorts();
#endif

    //! Get the number of Time output ports
    //!
    //! \return The number of Time output ports
    //!
    NATIVE_INT_TYPE getNum_Time_OutputPorts();


    enum {
       NUM_LOG_OUTPUT_PORTS = 1,
       NUM_LOGTEXT_OUTPUT_PORTS = 1,
       NUM_TIME_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port Log is connected
    //!
    //! \return Whether port Log is connected
    //!
    bool isConnected_Log_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Check whether port LogText is connected
    //!
    //! \return Whether port LogText is connected
    //!
    bool isConnected_LogText_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );
#endif

    //! Check whether port Time is connected
    //!
    //! \return Whether port Time is connected
    //!
    bool isConnected_Time_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_AF_ASSERT_0 = 0x0, /* An assert happened */
      EVENTID_AF_ASSERT_1 = 0x1, /* An assert happened */
      EVENTID_AF_ASSERT_2 = 0x2, /* An assert happened */
      EVENTID_AF_ASSERT_3 = 0x3, /* An assert happened */
      EVENTID_AF_ASSERT_4 = 0x4, /* An assert happened */
      EVENTID_AF_ASSERT_5 = 0x5, /* An assert happened */
      EVENTID_AF_ASSERT_6 = 0x6, /* An assert happened */
      EVENTID_AF_UNEXPECTED_ASSERT = 0x7, /* An unexpected assert happened */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event AF_ASSERT_0
    //!
    /* An assert happened */
    void log_FATAL_AF_ASSERT_0(
        const Fw::LogStringArg& file, /*!< The source file of the assert*/
        U32 line /*!< Line number of the assert*/
    );


    //! Log event AF_ASSERT_1
    //!
    /* An assert happened */
    void log_FATAL_AF_ASSERT_1(
        const Fw::LogStringArg& file, /*!< The source file of the assert*/
        U32 line, /*!< Line number of the assert*/
        U32 arg1 /*!< First assert argument*/
    );


    //! Log event AF_ASSERT_2
    //!
    /* An assert happened */
    void log_FATAL_AF_ASSERT_2(
        const Fw::LogStringArg& file, /*!< The source file of the assert*/
        U32 line, /*!< Line number of the assert*/
        U32 arg1, /*!< First assert argument*/
        U32 arg2 /*!< Second assert argument*/
    );


    //! Log event AF_ASSERT_3
    //!
    /* An assert happened */
    void log_FATAL_AF_ASSERT_3(
        const Fw::LogStringArg& file, /*!< The source file of the assert*/
        U32 line, /*!< Line number of the assert*/
        U32 arg1, /*!< First assert argument*/
        U32 arg2, /*!< Second assert argument*/
        U32 arg3 /*!< Third assert argument*/
    );


    //! Log event AF_ASSERT_4
    //!
    /* An assert happened */
    void log_FATAL_AF_ASSERT_4(
        const Fw::LogStringArg& file, /*!< The source file of the assert*/
        U32 line, /*!< Line number of the assert*/
        U32 arg1, /*!< First assert argument*/
        U32 arg2, /*!< Second assert argument*/
        U32 arg3, /*!< Third assert argument*/
        U32 arg4 /*!< Fourth assert argument*/
    );


    //! Log event AF_ASSERT_5
    //!
    /* An assert happened */
    void log_FATAL_AF_ASSERT_5(
        const Fw::LogStringArg& file, /*!< The source file of the assert*/
        U32 line, /*!< Line number of the assert*/
        U32 arg1, /*!< First assert argument*/
        U32 arg2, /*!< Second assert argument*/
        U32 arg3, /*!< Third assert argument*/
        U32 arg4, /*!< Fourth assert argument*/
        U32 arg5 /*!< Fifth assert argument*/
    );


    //! Log event AF_ASSERT_6
    //!
    /* An assert happened */
    void log_FATAL_AF_ASSERT_6(
        const Fw::LogStringArg& file, /*!< The source file of the assert*/
        U32 line, /*!< Line number of the assert*/
        U32 arg1, /*!< First assert argument*/
        U32 arg2, /*!< Second assert argument*/
        U32 arg3, /*!< Third assert argument*/
        U32 arg4, /*!< Fourth assert argument*/
        U32 arg5, /*!< Fifth assert argument*/
        U32 arg6 /*!< Sixth assert argument*/
    );


    //! Log event AF_UNEXPECTED_ASSERT
    //!
    /* An unexpected assert happened */
    void log_FATAL_AF_UNEXPECTED_ASSERT(
        const Fw::LogStringArg& file, /*!< The source file of the assert*/
        U32 line, /*!< Line number of the assert*/
        U32 numArgs /*!< Number of unexpected arguments*/
    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Time
    // ----------------------------------------------------------------------

    //! Get the time
    //!
    //! \return The current time
    //!
    Fw::Time getTime();


  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port Log
    //!
    Fw::OutputLogPort m_Log_OutputPort[NUM_LOG_OUTPUT_PORTS];

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Output port LogText
    //!
    Fw::OutputLogTextPort m_LogText_OutputPort[NUM_LOGTEXT_OUTPUT_PORTS];
#endif

    //! Output port Time
    //!
    Fw::OutputTimePort m_Time_OutputPort[NUM_TIME_OUTPUT_PORTS];


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------

  };

} // end namespace Svc
#endif
