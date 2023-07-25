module BaremetalReference {

  # ----------------------------------------------------------------------
  # Symbolic constants for port numbers
  # ----------------------------------------------------------------------

    enum Ports_RateGroups {
      rateGroup1
      rateGroup2
    }

    enum Ports_StaticMemory {
      hub
      hubFramer
      hubDeframer
      hubDriver
    }

  topology BaremetalReference {

    # ----------------------------------------------------------------------
    # Instances used in the topology
    # ----------------------------------------------------------------------

    instance blinker
    instance bufferManager
    instance cmdDisp
    instance commQueue
    instance deframer
    instance eventLogger
    instance fatalAdapter
    instance fatalHandler
    instance framer
    instance gpioDriver
    instance gpioRadioReset
    instance i2cDriver
    instance imu
    instance rateDriver
    instance rateGroup1
    instance rateGroup2
    instance rateGroupDriver
    instance rfm69
    instance systemResources
    instance systemTime
    instance textLogger
    instance tlmSend
    instance hub
    instance hubDeframer
    instance hubFramer
    instance hubDriver
    instance splitter
    instance staticMemory

    # ----------------------------------------------------------------------
    # Pattern graph specifiers
    # ----------------------------------------------------------------------

    command connections instance cmdDisp

    event connections instance eventLogger

    telemetry connections instance tlmSend

    text event connections instance textLogger

    time connections instance systemTime

    # ----------------------------------------------------------------------
    # Direct graph specifiers
    # ----------------------------------------------------------------------

    connections RateGroups {
      # Block driver
      rateDriver.CycleOut -> rateGroupDriver.CycleIn

      # Rate group 1
      rateGroupDriver.CycleOut[Ports_RateGroups.rateGroup1] -> rateGroup1.CycleIn
      rateGroup1.RateGroupMemberOut[0] -> rfm69.run
      rateGroup1.RateGroupMemberOut[1] -> hubDriver.schedIn

      # Rate group 2
      rateGroupDriver.CycleOut[Ports_RateGroups.rateGroup2] -> rateGroup2.CycleIn
      rateGroup2.RateGroupMemberOut[0] -> systemResources.run
      rateGroup2.RateGroupMemberOut[1] -> tlmSend.Run
      rateGroup2.RateGroupMemberOut[2] -> imu.run
      rateGroup2.RateGroupMemberOut[3] -> bufferManager.schedIn
      rateGroup2.RateGroupMemberOut[4] -> blinker.run
    }

    connections FaultProtection {
      eventLogger.FatalAnnounce -> fatalHandler.FatalReceive
    }

    connections Comms {

      # Downlink
      tlmSend.PktSend -> commQueue.comQueueIn[0]
      eventLogger.PktSend -> commQueue.comQueueIn[1]

      commQueue.comQueueSend -> framer.comIn

      framer.framedAllocate -> bufferManager.bufferGetCallee
      framer.framedOut -> rfm69.comDataIn
      rfm69.deallocate -> bufferManager.bufferSendIn

      rfm69.comStatus -> commQueue.comStatusIn

      # Uplink
      rfm69.allocate -> bufferManager.bufferGetCallee
      rfm69.comDataOut -> deframer.framedIn
      deframer.framedDeallocate -> bufferManager.bufferSendIn

      # deframer.comOut -> cmdDisp.seqCmdBuff
      # cmdDisp.seqCmdStatus -> deframer.cmdResponseIn

      deframer.comOut -> splitter.CmdBuff
      splitter.LocalCmd -> cmdDisp.seqCmdBuff
      cmdDisp.seqCmdStatus -> splitter.seqCmdStatus
      splitter.forwardSeqCmdStatus -> deframer.cmdResponseIn

      deframer.bufferAllocate -> bufferManager.bufferGetCallee
      deframer.bufferDeallocate -> bufferManager.bufferSendIn

    }

    connections I2c {
      imu.read -> i2cDriver.read
      imu.write -> i2cDriver.write
    }

    connections BaremetalReference {
      # Add here connections to user-defined components
      blinker.gpioSet -> gpioDriver.gpioWrite
      rfm69.gpioReset -> gpioRadioReset.gpioWrite
    }

    connections HubToDriver {
      # Hub -> Framer -> Uart Driver
      hub.dataOutAllocate -> staticMemory.bufferAllocate[Ports_StaticMemory.hub]
      hub.dataOut -> hubFramer.bufferIn
      hubFramer.bufferDeallocate -> staticMemory.bufferDeallocate[Ports_StaticMemory.hub]
      hubFramer.framedAllocate -> staticMemory.bufferAllocate[Ports_StaticMemory.hubFramer]
      hubFramer.framedOut -> hubDriver.send
      hubDriver.deallocate -> staticMemory.bufferDeallocate[Ports_StaticMemory.hubFramer]

      # Uart Driver -> Deframer -> Hub
      hubDriver.allocate -> staticMemory.bufferAllocate[Ports_StaticMemory.hubDriver]
      hubDriver.$recv -> hubDeframer.framedIn
      hubDeframer.framedDeallocate -> staticMemory.bufferDeallocate[Ports_StaticMemory.hubDriver]
      hubDeframer.bufferAllocate -> staticMemory.bufferAllocate[Ports_StaticMemory.hubDeframer]
      hubDeframer.bufferOut -> hub.dataIn
      hub.dataInDeallocate -> staticMemory.bufferDeallocate[Ports_StaticMemory.hubDeframer]
    }


    connections HubToDeployment {
      hub.LogSend -> eventLogger.LogRecv
      hub.TlmSend -> tlmSend.TlmRecv

      splitter.RemoteCmd -> hub.portIn[0]
      hub.portOut[0] -> splitter.seqCmdStatus

    }

  }

}
