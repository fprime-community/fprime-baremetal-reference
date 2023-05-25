// ======================================================================
// \title  RFM69.cpp
// \author ethanchee
// \brief  cpp file for RFM69 component implementation class
// ======================================================================

#include <vector>

#include <BaremetalReference/Radio/RFM69/RFM69.hpp>
#include <FpConfig.hpp>

// Used for logging
#include <Os/Log.hpp>
#include <Arduino/Os/StreamLog.hpp>

namespace Radio {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  RFM69 ::
    RFM69(
        const char *const compName
    ) : RFM69ComponentBase(compName),
        radio_state(Fw::On::OFF),
        pkt_rx_count(0),
        pkt_tx_count(0),
        rfm69(RFM69_CS, RFM69_INT)
  {
    
  }

  RFM69 ::
    ~RFM69()
  {

  }

  void RFM69 ::
    recv()
  {
    if (rfm69.available()) {
      std::vector<U8> payload;
      payload.resize(RH_RF69_MAX_MESSAGE_LEN);
      U8 bytes_recv = payload.size();

      if (rfm69.recv(payload.data(), &bytes_recv)) {
        pkt_rx_count++;
        this->tlmWrite_NumPacketsReceived(pkt_rx_count);
        this->tlmWrite_RSSI(rfm69.lastRssi());
        this->log_WARNING_LO_PayloadMessage(reinterpret_cast<const char*>(payload.data()));
      }
    }
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void RFM69 ::
    run_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    this->tlmWrite_Status(radio_state);

    if(radio_state == Fw::On::OFF)
    {
      if(!rfm69.init())
      {
        FW_ASSERT(0);
      }

      if (!rfm69.setFrequency(RFM69_FREQ)) {
        FW_ASSERT(0);
      }

      rfm69.setTxPower(14, true);

      radio_state = Fw::On::ON;
    }
    
    this->recv();
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void RFM69 ::
    SEND_PACKET_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CmdStringArg& payload
    )
  {
    auto cmdResp = Fw::CmdResponse::OK;
    rfm69.send(reinterpret_cast<const U8*>(payload.toChar()), payload.length());
    if(!rfm69.waitPacketSent(1000))
    {
      cmdResp = Fw::CmdResponse::VALIDATION_ERROR;
    } 
    else
    {
      pkt_tx_count++;
      this->tlmWrite_NumPacketsSent(pkt_tx_count);
    }

    this->cmdResponse_out(opCode, cmdSeq, cmdResp);
  }

} // end namespace Radio
