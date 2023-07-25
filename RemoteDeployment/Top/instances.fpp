module RemoteDeployment {

  constant REMOTE_TOPOLOGY_BASE = 0x10000000

  # ----------------------------------------------------------------------
  # Defaults
  # ----------------------------------------------------------------------

  module Default {
    constant QUEUE_SIZE = 10
    constant STACK_SIZE = 64 * 1024
  }

  # ----------------------------------------------------------------------
  # Active component instances
  # ----------------------------------------------------------------------

  instance r_blockDrv: Drv.BlockDriver base id REMOTE_TOPOLOGY_BASE + 0x0100 \
    queue size Default.QUEUE_SIZE \
    stack size Default.STACK_SIZE \
    priority 140

  instance r_rateGroup1: Svc.ActiveRateGroup base id REMOTE_TOPOLOGY_BASE + 0x0200 \
    queue size Default.QUEUE_SIZE \
    stack size Default.STACK_SIZE \
    priority 120

  instance r_rateGroup2: Svc.ActiveRateGroup base id REMOTE_TOPOLOGY_BASE + 0x0300 \
    queue size Default.QUEUE_SIZE \
    stack size Default.STACK_SIZE \
    priority 119

  instance r_rateGroup3: Svc.ActiveRateGroup base id REMOTE_TOPOLOGY_BASE + 0x0400 \
    queue size Default.QUEUE_SIZE \
    stack size Default.STACK_SIZE \
    priority 118

  instance r_cmdDisp: Svc.CommandDispatcher base id REMOTE_TOPOLOGY_BASE + 0x0500 \
    queue size 20 \
    stack size Default.STACK_SIZE \
    priority 101

  instance r_fileDownlink: Svc.FileDownlink base id REMOTE_TOPOLOGY_BASE + 0x0800 \
    queue size 30 \
    stack size Default.STACK_SIZE \
    priority 100

  instance r_fileManager: Svc.FileManager base id REMOTE_TOPOLOGY_BASE + 0x0900 \
    queue size 30 \
    stack size Default.STACK_SIZE \
    priority 100

  instance r_prmDb: Svc.PrmDb base id REMOTE_TOPOLOGY_BASE + 0x0D00 \
    queue size Default.QUEUE_SIZE \
    stack size Default.STACK_SIZE \
    priority 96

  # ----------------------------------------------------------------------
  # Queued component instances
  # ----------------------------------------------------------------------

  instance r_health: Svc.Health base id REMOTE_TOPOLOGY_BASE + 0x2000 \
    queue size 25

  # ----------------------------------------------------------------------
  # Passive component instances
  # ----------------------------------------------------------------------

  instance r_fatalAdapter: Svc.AssertFatalAdapter base id REMOTE_TOPOLOGY_BASE + 0x4200

  instance r_fatalHandler: Svc.FatalHandler base id REMOTE_TOPOLOGY_BASE + 0x4300

  instance r_bufferManager: Svc.BufferManager base id REMOTE_TOPOLOGY_BASE + 0x4400

  instance r_linuxTime: Svc.Time base id REMOTE_TOPOLOGY_BASE + 0x4500 \
    type "Svc::LinuxTime" \
    at "../../Svc/LinuxTime/LinuxTime.hpp"

  instance r_rateGroupDriver: Svc.RateGroupDriver base id REMOTE_TOPOLOGY_BASE + 0x4600

  instance r_textLogger: Svc.PassiveTextLogger base id REMOTE_TOPOLOGY_BASE + 0x4800

  instance r_systemResources: Svc.SystemResources base id REMOTE_TOPOLOGY_BASE + 0x4A00


  instance r_hub: Svc.GenericHub base id REMOTE_TOPOLOGY_BASE + 0x100000

  instance r_hubFramer: Svc.Framer base id REMOTE_TOPOLOGY_BASE + 0x100100

  instance r_hubDeframer: Svc.Deframer base id REMOTE_TOPOLOGY_BASE + 0x100200

  instance r_hubDriver: Drv.LinuxUartDriver base id REMOTE_TOPOLOGY_BASE + 0x100300

}
