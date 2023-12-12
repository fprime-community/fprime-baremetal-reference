// ======================================================================
// \title  RFM69.cpp
// \author ethanchee
// \brief  cpp file for RFM69 component implementation class
// ======================================================================

#include <Components/Radio/RFM69/RFM69.hpp>
#include <FpConfig.hpp>
#include <Os/Log.hpp>

namespace Radio {

// ----------------------------------------------------------------------
// Construction, initialization, and destruction
// ----------------------------------------------------------------------

RFM69::RFM69(const char* const compName)
    : RFM69ComponentBase(compName),
#if defined(_BOARD_TEENSY41)
      rfm69(RFM69_CS, RFM69_INT, hardware_spi1),
#else
      rfm69(RFM69_CS, RFM69_INT),
#endif
      radio_state(Fw::On::OFF),
      pkt_rx_count(0),
      pkt_tx_count(0) {

#if defined(_BOARD_TEENSY40)
    SPI.setSCK(RFM69_SCK);
#endif

}

RFM69::~RFM69() {}

bool RFM69::send(const U8* payload, NATIVE_UINT_TYPE len) {
    FW_ASSERT(payload != nullptr);

    NATIVE_UINT_TYPE offset = 0;
    while (len > RH_RF69_MAX_MESSAGE_LEN) {
        rfm69.send(&payload[offset], RH_RF69_MAX_MESSAGE_LEN);
        if (!rfm69.waitPacketSent(500)) {
            return false;
        }
        delay(1);
        offset += RH_RF69_MAX_MESSAGE_LEN;
        len -= RH_RF69_MAX_MESSAGE_LEN;
    }

    rfm69.send(&payload[offset], len);
    if (!rfm69.waitPacketSent(500)) {
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

void RFM69::recv() {
    if (rfm69.available()) {
        U8 buf[RH_RF69_MAX_MESSAGE_LEN];
        U8 bytes_recv = RH_RF69_MAX_MESSAGE_LEN;

        if (rfm69.recv(buf, &bytes_recv)) {
            Fw::Buffer recvBuffer = this->allocate_out(0, bytes_recv);
            memcpy(recvBuffer.getData(), buf, bytes_recv);
            recvBuffer.setSize(bytes_recv);
            pkt_rx_count++;

            this->log_DIAGNOSTIC_PayloadMessageRX(recvBuffer.getSize());

            this->tlmWrite_NumPacketsReceived(pkt_rx_count);
            this->tlmWrite_RSSI(rfm69.lastRssi());

            this->comDataOut_out(0, recvBuffer, Drv::RecvStatus::RECV_OK);
        }
    }
}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

Drv::SendStatus RFM69 ::comDataIn_handler(const NATIVE_INT_TYPE portNum, Fw::Buffer& sendBuffer) {
    if ((radio_state == Fw::On::ON) && (sendBuffer.getSize() > 0) &&
        (not this->send(sendBuffer.getData(), sendBuffer.getSize()))) {
        radio_state = Fw::On::OFF;
    }
    deallocate_out(0, sendBuffer);

    return Drv::SendStatus::SEND_OK;  // Always send ok to deframer as it does not handle this anyway
}

void RFM69 ::run_handler(const NATIVE_INT_TYPE portNum, NATIVE_UINT_TYPE context) {
    this->tlmWrite_Status(radio_state);

    if (radio_state == Fw::On::OFF) {
        if (this->isConnected_gpioReset_OutputPort(0)) {
            this->gpioReset_out(0, Fw::Logic::HIGH);
            delay(10);
            this->gpioReset_out(0, Fw::Logic::LOW);
            delay(10);
        }

        if (!rfm69.init()) {
            Fw::Logger::logMsg("Failed to initialize radio... Trying again...\n");
            return;
        }

        rfm69.setFrequency(RFM69_FREQ);
        rfm69.setModemConfig(RH_RF69::ModemConfigChoice::GFSK_Rb250Fd250);
        rfm69.setTxPower(14, true);

        Fw::Success radioSuccess = Fw::Success::SUCCESS;
        if (this->isConnected_comStatus_OutputPort(0)) {
            this->comStatus_out(0, radioSuccess);
        }

        radio_state = Fw::On::ON;
    }

    this->recv();
}

}  // end namespace Radio
