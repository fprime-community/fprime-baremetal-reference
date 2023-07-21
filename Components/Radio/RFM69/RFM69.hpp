// ======================================================================
// \title  RFM69.hpp
// \author ethanchee
// \brief  hpp file for RFM69 component implementation class
// ======================================================================

#ifndef RFM69_HPP
#define RFM69_HPP

#include "Components/Radio/RFM69/RFM69ComponentAc.hpp"
#include "RH_RF69.h"
#include <FprimeArduino.hpp>

namespace Radio {

  class RFM69 :
    public RFM69ComponentBase
  {

    public:

      static const NATIVE_INT_TYPE RFM69_FREQ = 915;
      static const NATIVE_INT_TYPE RFM69_CS   = 8;
      static const NATIVE_INT_TYPE RFM69_INT  = 3;
      static const NATIVE_INT_TYPE RFM69_RST  = 4;

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object RFM69
      //!
      RFM69(
          const char *const compName /*!< The component name*/
      );

      //! Destroy object RFM69
      //!
      ~RFM69();

      bool send(const U8* payload, NATIVE_UINT_TYPE len);
      void recv();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for comDataIn
      //!
      Drv::SendStatus comDataIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &sendBuffer 
      );

      //! Handler implementation for run
      //!
      void run_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< 
      The call order
      */
      );

      RH_RF69 rfm69;
      Fw::On radio_state;
      U16 pkt_rx_count;
      U16 pkt_tx_count;
    };

} // end namespace Radio

#endif
