

#ifndef SystemRefPackets_header_h
#define SystemRefPackets_header_h

#include <Svc/TlmPacketizer/TlmPacketizerTypes.hpp>

namespace SystemRef {

    // set of packets to send
    extern const Svc::TlmPacketizerPacketList SystemRefPacketsPkts;
    // set of channels to ignore
    extern const Svc::TlmPacketizerPacket SystemRefPacketsIgnore;

}

#endif // SystemRefPackets_header_h

