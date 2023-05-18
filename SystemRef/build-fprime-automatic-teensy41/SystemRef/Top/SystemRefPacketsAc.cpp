

#include <Svc/TlmPacketizer/TlmPacketizerTypes.hpp>
#include <SystemRef/Top/SystemRefPacketsAc.hpp>

#include <FpConfig.hpp>
#include <FpConfig.hpp>
#include <Fw/Time/Time.hpp>

// Verify packets not too large for ComBuffer
// if this macro gives a compile error, that means the packets are too large

void check_func(void) {
    static_assert((111 <= (FW_COM_BUFFER_MAX_SIZE - Fw::Time::SERIALIZED_SIZE - sizeof(FwTlmPacketizeIdType) - sizeof(FwPacketDescriptorType))), "PacketsTooBig");
}

namespace SystemRef {

  static const Svc::TlmPacketizerChannelEntry CDHList[] = {
      {1280, 4}, // cmdDisp.CommandsDispatched
      {512, 4}, // rateGroup1.RgMaxTime
      {1536, 4}, // cmdSeq.CS_LoadCommands
      {1537, 4}, // cmdSeq.CS_CancelCommands
      {1539, 4}, // cmdSeq.CS_CommandsExecuted
      {1540, 4}, // cmdSeq.CS_SequencesCompleted
      {2304, 4}, // fileUplink.FilesReceived
      {2305, 4}, // fileUplink.PacketsReceived
      {17408, 4}, // fileUplinkBufferManager.TotalBuffs
      {17409, 4}, // fileUplinkBufferManager.CurrBuffs
      {17410, 4}, // fileUplinkBufferManager.HiBuffs
      {1792, 4}, // fileDownlink.FilesSent
      {1793, 4}, // fileDownlink.PacketsSent
      {2048, 4}, // fileManager.CommandsExecuted
  };

  static const Svc::TlmPacketizerPacket CDH = { CDHList, 1, 1, FW_NUM_ARRAY_ELEMENTS(CDHList) };

  static const Svc::TlmPacketizerChannelEntry CDHErrorsList[] = {
      {513, 4}, // rateGroup1.RgCycleSlips
      {1538, 4}, // cmdSeq.CS_Errors
      {2306, 4}, // fileUplink.Warnings
      {1794, 4}, // fileDownlink.Warnings
      {2049, 4}, // fileManager.Errors
      {17411, 4}, // fileUplinkBufferManager.NoBuffs
      {17412, 4}, // fileUplinkBufferManager.EmptyBuffs
      {2049, 4}, // fileManager.Errors
  };

  static const Svc::TlmPacketizerPacket CDHErrors = { CDHErrorsList, 2, 1, FW_NUM_ARRAY_ELEMENTS(CDHErrorsList) };

  static const Svc::TlmPacketizerChannelEntry DriveTlmList[] = {
      {256, 4}, // blockDrv.BD_Cycles
  };

  static const Svc::TlmPacketizerPacket DriveTlm = { DriveTlmList, 3, 1, FW_NUM_ARRAY_ELEMENTS(DriveTlmList) };

  static const Svc::TlmPacketizerChannelEntry SystemRes1List[] = {
      {18944, 8}, // systemResources.MEMORY_TOTAL
      {18945, 8}, // systemResources.MEMORY_USED
      {18946, 8}, // systemResources.NON_VOLATILE_TOTAL
      {18947, 8}, // systemResources.NON_VOLATILE_FREE
  };

  static const Svc::TlmPacketizerPacket SystemRes1 = { SystemRes1List, 5, 2, FW_NUM_ARRAY_ELEMENTS(SystemRes1List) };

  static const Svc::TlmPacketizerChannelEntry SystemRes2List[] = {
      {18965, 42}, // systemResources.FRAMEWORK_VERSION
      {18966, 42}, // systemResources.PROJECT_VERSION
  };

  static const Svc::TlmPacketizerPacket SystemRes2 = { SystemRes2List, 6, 2, FW_NUM_ARRAY_ELEMENTS(SystemRes2List) };

  static const Svc::TlmPacketizerChannelEntry SystemRes3List[] = {
      {18948, 4}, // systemResources.CPU
      {18949, 4}, // systemResources.CPU_00
      {18950, 4}, // systemResources.CPU_01
      {18951, 4}, // systemResources.CPU_02
      {18952, 4}, // systemResources.CPU_03
      {18953, 4}, // systemResources.CPU_04
      {18954, 4}, // systemResources.CPU_05
      {18955, 4}, // systemResources.CPU_06
      {18956, 4}, // systemResources.CPU_07
      {18957, 4}, // systemResources.CPU_08
      {18958, 4}, // systemResources.CPU_09
      {18959, 4}, // systemResources.CPU_10
      {18960, 4}, // systemResources.CPU_11
      {18961, 4}, // systemResources.CPU_12
      {18962, 4}, // systemResources.CPU_13
      {18963, 4}, // systemResources.CPU_14
      {18964, 4}, // systemResources.CPU_15
  };

  static const Svc::TlmPacketizerPacket SystemRes3 = { SystemRes3List, 7, 2, FW_NUM_ARRAY_ELEMENTS(SystemRes3List) };

  static const Svc::TlmPacketizerChannelEntry BlinkerChannelsList[] = {
      {3841, 8}, // blinker.LedTransitions
      {3840, 4}, // blinker.BlinkingState
  };

  static const Svc::TlmPacketizerPacket BlinkerChannels = { BlinkerChannelsList, 8, 1, FW_NUM_ARRAY_ELEMENTS(BlinkerChannelsList) };



  const Svc::TlmPacketizerPacketList SystemRefPacketsPkts = {
      {
         &CDH,
         &CDHErrors,
         &DriveTlm,
         &SystemRes1,
         &SystemRes2,
         &SystemRes3,
         &BlinkerChannels,
      },
      7
  };


  static const Svc::TlmPacketizerChannelEntry ignoreList[] = {
      {1281, 0}, // cmdDisp.CommandErrors
  };

  const Svc::TlmPacketizerPacket SystemRefPacketsIgnore = { ignoreList, 0, 0, FW_NUM_ARRAY_ELEMENTS(ignoreList) };

} // end namespace SystemRef

