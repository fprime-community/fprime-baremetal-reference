// ======================================================================
// \title  RFM69.cpp
// \author ethanchee
// \brief  cpp file for RFM69 component implementation class
// ======================================================================

#include <vector>

#include <BaremetalReference/Radio/RFM69/RFM69.hpp>
#include <FpConfig.hpp>

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
        rfm69(RFM69_CS, RFM69_INT),
        m_circular(m_data, sizeof m_data),
        m_reinit(true)
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

  Drv::SendStatus RFM69 ::
    comDataIn_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &sendBuffer
    )
  {
    Fw::Success radioReady = Fw::Success::SUCCESS;

    Drv::SendStatus driverStatus = drvDataOut_out(0, const_cast<Fw::Buffer&>(sendBuffer));
    radioReady = (driverStatus.e == Drv::SendStatus::SEND_OK) ? Fw::Success::SUCCESS : Fw::Success::FAILURE;

    if (isConnected_comStatus_OutputPort(0)) {
        comStatus_out(0, radioReady);
    }
    return Drv::SendStatus::SEND_OK;
  }

  void RFM69 ::
    drvConnected_handler(
        const NATIVE_INT_TYPE portNum
    )
  {
    if (m_reinit) {
        Fw::Success radioReady = Fw::Success::SUCCESS;
        if (isConnected_comStatus_OutputPort(0)) {
            comStatus_out(0, radioReady);
        }
        m_reinit = false;
    }
  }

  void RFM69 ::
    drvDataIn_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &recvBuffer,
        const Drv::RecvStatus &recvStatus
    )
  {
    if (recvStatus == Drv::RecvStatus::RECV_OK) {
        m_circular.serialize(recvBuffer.getData(), recvBuffer.getSize());
        deallocate_out(0, recvBuffer);
    } else {
      comDataOut_out(0, recvBuffer, recvStatus);
    }
  }

  void RFM69 ::
    run_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // this->tlmWrite_Status(radio_state);

    // if(radio_state == Fw::On::OFF)
    // {
    //   if(!rfm69.init())
    //   {
    //     FW_ASSERT(0);
    //   }

    //   if (!rfm69.setFrequency(RFM69_FREQ)) {
    //     FW_ASSERT(0);
    //   }

    //   rfm69.setTxPower(14, true);

    //   radio_state = Fw::On::ON;
    // }
    
    // this->recv();
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
