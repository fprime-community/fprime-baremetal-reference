module RadioPassthrough {

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
    }

  topology RadioPassthrough {

    # ----------------------------------------------------------------------
    # Instances used in the topology
    # ----------------------------------------------------------------------

    instance blinker
    instance commDriver
    instance eventLogger
    instance gpioDriver
    instance gpioRadioReset
    instance rateDriver
    instance rateGroup1
    instance rateGroup2
    instance rateGroupDriver
    instance rfm69
    instance staticMemory
    instance streamCrossoverUplink
    instance streamCrossoverDownlink
    instance systemTime

    # ----------------------------------------------------------------------
    # Pattern graph specifiers
    # ----------------------------------------------------------------------

    event connections instance eventLogger

    time connections instance systemTime

    # ----------------------------------------------------------------------
    # Direct graph specifiers
    # ----------------------------------------------------------------------

    connections RateGroups {
      # Block driver
      rateDriver.CycleOut -> rateGroupDriver.CycleIn

      # Rate group 1
      rateGroupDriver.CycleOut[Ports_RateGroups.rateGroup1] -> rateGroup1.CycleIn
      rateGroup1.RateGroupMemberOut[0] -> commDriver.schedIn
      rateGroup1.RateGroupMemberOut[1] -> rfm69.run

      # Rate group 2
      rateGroupDriver.CycleOut[Ports_RateGroups.rateGroup2] -> rateGroup2.CycleIn
      rateGroup2.RateGroupMemberOut[0] -> blinker.run
    }

    connections Comms {

      # Downlink
      rfm69.allocate -> staticMemory.bufferAllocate[Ports_StaticMemory.downlink]
      rfm69.comDataOut -> streamCrossoverDownlink.streamIn
      streamCrossoverDownlink.streamOut -> commDriver.send
      commDriver.deallocate -> staticMemory.bufferDeallocate[Ports_StaticMemory.downlink]

      streamCrossoverDownlink.errorDeallocate -> staticMemory.bufferDeallocate[Ports_StaticMemory.downlink]

      # Uplink
      commDriver.allocate -> staticMemory.bufferAllocate[Ports_StaticMemory.uplink]
      commDriver.$recv -> streamCrossoverUplink.streamIn
      streamCrossoverUplink.streamOut -> rfm69.comDataIn
      rfm69.deallocate -> staticMemory.bufferDeallocate[Ports_StaticMemory.uplink]
      
      streamCrossoverUplink.errorDeallocate -> staticMemory.bufferDeallocate[Ports_StaticMemory.uplink]

    }

    connections RadioPassthrough {
      # Add here connections to user-defined components
      blinker.gpioSet -> gpioDriver.gpioWrite
      rfm69.gpioReset -> gpioRadioReset.gpioWrite
    }

  }

}
