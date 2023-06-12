// ======================================================================
// DeframerCfg.hpp
// Configuration settings for Deframer component
// Author: bocchino
// ======================================================================

#ifndef SVC_DEFRAMER_CFG_HPP
#define SVC_DEFRAMER_CFG_HPP

#include <FpConfig.hpp>

namespace Svc {
    namespace DeframerCfg {
        //! The size of the circular buffer in bytes
        static const U32 RING_BUFFER_SIZE = FW_COM_BUFFER_MAX_SIZE + 12;
        //! The size of the polling buffer in bytes
        static const U32 POLL_BUFFER_SIZE = 1;
    }
}

#endif
