// ======================================================================
// \title  RFM69Pinout.hpp
// \author ethanchee
// \brief  hpp file for RFM69 component implementation class
// ======================================================================

#ifndef RFM69PINOUT_HPP
#define RFM69PINOUT_HPP

#include <Fw/Types/BasicTypes.h>

namespace Radio
{
#if defined(_BOARD_FEATHERM0) // Adafruit Feather M0
    static const NATIVE_INT_TYPE RFM69_MISO = 22;
    static const NATIVE_INT_TYPE RFM69_MOSI = 23;
    static const NATIVE_INT_TYPE RFM69_SCK = 24;
    static const NATIVE_INT_TYPE RFM69_CS = 8;
    static const NATIVE_INT_TYPE RFM69_INT = 3;
    static const NATIVE_INT_TYPE RFM69_RST = 4;
#elif defined(_BOARD_FEATHERRP2040RFM) // Adafruit Feather RP2040
    static const NATIVE_INT_TYPE RFM69_MISO = 20;   // GPIO20
    static const NATIVE_INT_TYPE RFM69_MOSI = 19;   // GPIO19
    static const NATIVE_INT_TYPE RFM69_SCK = 18;    // GPIO18
    static const NATIVE_INT_TYPE RFM69_CS = 25;     // GPIO25
    static const NATIVE_INT_TYPE RFM69_INT = 29;    // GPIO29
    static const NATIVE_INT_TYPE RFM69_RST = 24;    // GPIO24
#elif defined(_BOARD_RPIPICOW) // Raspberry Pi Pico W
    static const NATIVE_INT_TYPE RFM69_MISO = 16;   // GP16
    static const NATIVE_INT_TYPE RFM69_MOSI = 19;   // GP19
    static const NATIVE_INT_TYPE RFM69_SCK = 18;    // GP18
    static const NATIVE_INT_TYPE RFM69_CS = 17;     // GP17
    static const NATIVE_INT_TYPE RFM69_INT = 15;    // GP15
    static const NATIVE_INT_TYPE RFM69_RST = 14;    // GP14
#elif defined(_BOARD_TEENSY32) // Teensy 3.2
    static const NATIVE_INT_TYPE RFM69_MISO = 12;
    static const NATIVE_INT_TYPE RFM69_MOSI = 11;
    static const NATIVE_INT_TYPE RFM69_SCK = 14;
    static const NATIVE_INT_TYPE RFM69_CS = 10;
    static const NATIVE_INT_TYPE RFM69_INT = 3;
    static const NATIVE_INT_TYPE RFM69_RST = 4;
#elif defined(_BOARD_TEENSY40) // Teensy 4.0
    static const NATIVE_INT_TYPE RFM69_MISO = 12;
    static const NATIVE_INT_TYPE RFM69_MOSI = 11;
    static const NATIVE_INT_TYPE RFM69_SCK = 13;
    static const NATIVE_INT_TYPE RFM69_CS = 10;
    static const NATIVE_INT_TYPE RFM69_INT = 3;
    static const NATIVE_INT_TYPE RFM69_RST = 4;
#elif defined(_BOARD_TEENSY41) // Teensy 4.1
    static const NATIVE_INT_TYPE RFM69_MISO = 1;
    static const NATIVE_INT_TYPE RFM69_MOSI = 26;
    static const NATIVE_INT_TYPE RFM69_SCK = 27;
    static const NATIVE_INT_TYPE RFM69_CS = 0;
    static const NATIVE_INT_TYPE RFM69_INT = 3;
    static const NATIVE_INT_TYPE RFM69_RST = 4;
#else // Not handled. You can modify these pins for your project
    static const NATIVE_INT_TYPE RFM69_MISO = -1;
    static const NATIVE_INT_TYPE RFM69_MOSI = -1;
    static const NATIVE_INT_TYPE RFM69_SCK = -1;
    static const NATIVE_INT_TYPE RFM69_CS = -1;
    static const NATIVE_INT_TYPE RFM69_INT = -1;
    static const NATIVE_INT_TYPE RFM69_RST = -1;
#endif
}

#endif /* RFM69PINOUT_HPP */
