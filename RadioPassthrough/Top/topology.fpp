module BaremetalReference {

  # ----------------------------------------------------------------------
  # Symbolic constants for port numbers
  # ----------------------------------------------------------------------

    enum Ports_RateGroups {
      rateGroup1
      rateGroup2
    }

    enum Ports_StaticMemory {
      downlink
      uplink
      deframing
    }

  topology BaremetalReference {

    # ----------------------------------------------------------------------
    # Instances used in the topology
    # ----------------------------------------------------------------------

    instance tlmSend
    instance commDriver
    instance commQueue
    instance downlink
    instance eventLogger
    instance fatalAdapter
    instance fatalHandler
    instance rateDriver
    instance rateGroup1
    instance rateGroup2
    instance rateGroupDriver
    instance rfm69
    instance staticMemory
    instance streamCrossoverUplink
    instance streamCrossoverDownlink
    instance systemResources
    instance systemTime
    instance textLogger

    # ----------------------------------------------------------------------
    # Pattern graph specifiers
    # ----------------------------------------------------------------------

    event connections instance eventLogger

    telemetry connections instance tlmSend

    text event connections instance textLogger

    time connections instance systemTime

    # ----------------------------------------------------------------------
    # Direct graph specifiers
    # ----------------------------------------------------------------------

    connections Downlink {

      tlmSend.PktSend -> commQueue.comQueueIn[0]
      eventLogger.PktSend -> commQueue.comQueueIn[1]

      commQueue.comQueueSend -> downlink.comIn

      downlink.framedAllocate -> staticMemory.bufferAllocate[Ports_StaticMemory.downlink]
      downlink.framedOut -> rfm69.comDataIn
      commDriver.deallocate -> staticMemory.bufferDeallocate[Ports_StaticMemory.downlink]

      rfm69.comDataOut -> streamCrossoverDownlink.streamIn
      streamCrossoverDownlink.streamOut -> commDriver.send

      rfm69.comStatus -> commQueue.comStatusIn

    }

    connections FaultProtection {
      eventLogger.FatalAnnounce -> fatalHandler.FatalReceive
    }

    connections RateGroups {
      # Block driver
      rateDriver.CycleOut -> rateGroupDriver.CycleIn

      # Rate group 1
      rateGroupDriver.CycleOut[Ports_RateGroups.rateGroup1] -> rateGroup1.CycleIn
      rateGroup1.RateGroupMemberOut[0] -> commDriver.schedIn
      rateGroup1.RateGroupMemberOut[1] -> systemResources.run
      rateGroup1.RateGroupMemberOut[2] -> rfm69.run

      # Rate group 2
      rateGroupDriver.CycleOut[Ports_RateGroups.rateGroup2] -> rateGroup2.CycleIn
      rateGroup2.RateGroupMemberOut[0] -> tlmSend.Run
    }

    connections Uplink {

      commDriver.allocate -> staticMemory.bufferAllocate[Ports_StaticMemory.uplink]
      commDriver.$recv -> streamCrossoverUplink.streamIn
      streamCrossoverUplink.streamOut -> rfm69.comDataIn
      rfm69.deallocate -> staticMemory.bufferDeallocate[Ports_StaticMemory.uplink]

    }

    connections BaremetalReference {
      # Add here connections to user-defined components
      blinker.gpioSet -> gpioDriver.gpioWrite
    }

  }

}
