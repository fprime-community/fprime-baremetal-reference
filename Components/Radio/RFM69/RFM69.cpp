// ======================================================================
// \title  RFM69.cpp
// \author ethanchee
// \brief  cpp file for RFM69 component implementation class
// ======================================================================

#include <vector>

#include <Components/Radio/RFM69/RFM69.hpp>
#include <FpConfig.hpp>

#include <Fw/Logger/Logger.hpp>

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

  bool RFM69 ::
    send(const U8* payload, NATIVE_UINT_TYPE len)
  {
    if(len == 0)
    {
      return true;
    }

    NATIVE_UINT_TYPE offset = 0;
    while(len > RH_RF69_MAX_MESSAGE_LEN)
    {
      rfm69.send(&payload[offset], RH_RF69_MAX_MESSAGE_LEN);
      if(!rfm69.waitPacketSent(500))
      {
        return false;
      } 
      delay(10);
      offset += RH_RF69_MAX_MESSAGE_LEN;
      len -= RH_RF69_MAX_MESSAGE_LEN;
    }

    rfm69.send(&payload[offset], len);
    if(!rfm69.waitPacketSent(500))
    {
      return false;
    }

    pkt_tx_count++;
    this->tlmWrite_NumPacketsSent(pkt_tx_count);
    this->log_DIAGNOSTIC_PayloadMessageTX(len);

    Fw::Success radioSuccess = Fw::Success::SUCCESS;
    if (this->isConnected_comStatus_OutputPort(0)) {
        this->comStatus_out(0, radioSuccess);
    }

    return true;
  }

  void RFM69 ::
    recv(Fw::Buffer &recvBuffer)
  {
    if (rfm69.available()) {
      U8 bytes_recv = RH_RF69_MAX_MESSAGE_LEN;

      if (rfm69.recv(recvBuffer.getData(), &bytes_recv)) {
        recvBuffer.setSize(bytes_recv);
        pkt_rx_count++;

        this->log_DIAGNOSTIC_PayloadMessageRX(recvBuffer.getSize());

        this->tlmWrite_NumPacketsReceived(pkt_rx_count);
        this->tlmWrite_RSSI(rfm69.lastRssi());

        return;
      }

      return;
    }

    recvBuffer.setSize(0);
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  Drv::SendStatus RFM69 ::
    comDataIn_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &sendBuffer
    )
  {
    if(!(this->send(sendBuffer.getData(), sendBuffer.getSize())))
    {
      radio_state = Fw::On::OFF;
    }
    deallocate_out(0, sendBuffer);

    return Drv::SendStatus::SEND_OK;  // Always send ok to deframer as it does not handle this anyway
  }

  void RFM69 ::
    run_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    if(radio_state == Fw::On::OFF)
    {
      FW_ASSERT(rfm69.init());
      FW_ASSERT(rfm69.setFrequency(RFM69_FREQ));

      rfm69.setTxPower(14, true);

      Fw::Success radioSuccess = Fw::Success::SUCCESS;
      if (this->isConnected_comStatus_OutputPort(0)) {
          this->comStatus_out(0, radioSuccess);
      }

      radio_state = Fw::On::ON;
    }
    
    Fw::Buffer recvBuffer = this->allocate_out(0, RH_RF69_MAX_MESSAGE_LEN);
    this->recv(recvBuffer);
    this->comDataOut_out(0, recvBuffer, Drv::RecvStatus::RECV_OK);

    this->tlmWrite_Status(radio_state);
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
    // TODO
    auto cmdResp = Fw::CmdResponse::OK;

    this->cmdResponse_out(opCode, cmdSeq, cmdResp);
  }

} // end namespace Radio
