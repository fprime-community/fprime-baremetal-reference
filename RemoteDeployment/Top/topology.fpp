module RemoteDeployment {

  # ----------------------------------------------------------------------
  # Symbolic constants for port numbers
  # ----------------------------------------------------------------------

    enum Ports_RateGroups {
      rateGroup1
      rateGroup2
      rateGroup3
    }

    enum Ports_StaticMemory {
      hub
      hubFraming
      hubDeframer
      hubDriver
    }

  topology RemoteDeployment {

    # ----------------------------------------------------------------------
    # Instances used in the topology
    # ----------------------------------------------------------------------

    instance r_health
    instance r_blockDrv
    instance r_cmdDisp
    instance r_fatalAdapter
    instance r_fatalHandler
    instance r_fileDownlink
    instance r_fileManager
    instance r_bufferManager
    instance r_linuxTime
    instance r_prmDb
    instance r_rateGroup1
    instance r_rateGroup2
    instance r_rateGroup3
    instance r_rateGroupDriver
    instance r_systemResources
    instance r_textLogger

    instance r_hub
    instance r_hubDeframer
    instance r_hubDriver
    instance r_hubFramer

    # ----------------------------------------------------------------------
    # Pattern graph specifiers
    # ----------------------------------------------------------------------

    command connections instance r_cmdDisp

    event connections instance r_hub

    param connections instance r_prmDb

    telemetry connections instance r_hub

    text event connections instance r_textLogger

    time connections instance r_linuxTime

    health connections instance r_health

    # ----------------------------------------------------------------------
    # Direct graph specifiers
    # ----------------------------------------------------------------------

    connections RateGroups {
      # Block driver
      r_blockDrv.CycleOut -> r_rateGroupDriver.CycleIn

      # Rate group 1
      r_rateGroupDriver.CycleOut[Ports_RateGroups.rateGroup1] -> r_rateGroup1.CycleIn
      r_rateGroup1.RateGroupMemberOut[0] -> r_fileDownlink.Run

      # Rate group 2
      r_rateGroupDriver.CycleOut[Ports_RateGroups.rateGroup2] -> r_rateGroup2.CycleIn

      # Rate group 3
      r_rateGroupDriver.CycleOut[Ports_RateGroups.rateGroup3] -> r_rateGroup3.CycleIn
      r_rateGroup3.RateGroupMemberOut[0] -> r_health.Run
      r_rateGroup3.RateGroupMemberOut[1] -> r_blockDrv.Sched
      r_rateGroup3.RateGroupMemberOut[2] -> r_bufferManager.schedIn
      r_rateGroup3.RateGroupMemberOut[3] -> r_systemResources.run
    }

    connections HubToDriver {
      # Hub -> Framer -> Uart Driver
      r_hub.dataOutAllocate -> r_bufferManager.bufferGetCallee
      r_hub.dataOut -> r_hubFramer.bufferIn
      r_hubFramer.bufferDeallocate -> r_bufferManager.bufferSendIn
      r_hubFramer.framedAllocate -> r_bufferManager.bufferGetCallee
      r_hubFramer.framedOut -> r_hubDriver.send
      r_hubDriver.deallocate -> r_bufferManager.bufferSendIn

      # Uart Driver -> Deframer -> Hub
      r_hubDriver.allocate -> r_bufferManager.bufferGetCallee
      r_hubDriver.$recv -> r_hubDeframer.framedIn
      r_hubDeframer.framedDeallocate -> r_bufferManager.bufferSendIn
      r_hubDeframer.bufferAllocate -> r_bufferManager.bufferGetCallee
      r_hubDeframer.bufferOut -> r_hub.dataIn
      r_hub.dataInDeallocate -> r_bufferManager.bufferSendIn
    }

    connections HubToDeployment {
      r_hub.portOut[0] -> r_cmdDisp.seqCmdBuff
      r_cmdDisp.seqCmdStatus -> r_hub.portIn[0]
    }

  }

}
