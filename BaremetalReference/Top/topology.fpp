module BaremetalReference {

  # ----------------------------------------------------------------------
  # Symbolic constants for port numbers
  # ----------------------------------------------------------------------

    enum Ports_RateGroups {
      rateGroup1
      rateGroup2
    }

  topology BaremetalReference {

    # ----------------------------------------------------------------------
    # Instances used in the topology
    # ----------------------------------------------------------------------

    instance blinker
    instance bufferManager
    instance cmdDisp
    instance comDriver ## disable when using radio
    instance commQueue
    instance deframer
    instance eventLogger
#    instance fatalAdapter
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
    #instance rfm69 ## enable when using radio
    instance systemResources
    instance systemTime
    instance textLogger
    instance tlmSend

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
      rateGroup1.RateGroupMemberOut[0] -> comDriver.schedIn #rfm69.run
      rateGroup1.RateGroupMemberOut[1] -> blinker.run

      # Rate group 2
      rateGroupDriver.CycleOut[Ports_RateGroups.rateGroup2] -> rateGroup2.CycleIn
      rateGroup2.RateGroupMemberOut[0] -> systemResources.run
      rateGroup2.RateGroupMemberOut[1] -> tlmSend.Run
      rateGroup2.RateGroupMemberOut[2] -> imu.run
      rateGroup2.RateGroupMemberOut[3] -> bufferManager.schedIn
    }

    connections FaultProtection {
      eventLogger.FatalAnnounce -> fatalHandler.FatalReceive
    }

    connections SerialComms {

      # Downlink

      tlmSend.PktSend -> framer.comIn
      eventLogger.PktSend -> framer.comIn

      framer.framedAllocate -> bufferManager.bufferGetCallee
      framer.framedOut -> comDriver.$send
      comDriver.deallocate -> bufferManager.bufferSendIn

      # Uplink
      comDriver.$recv ->deframer.framedIn
      comDriver.allocate -> bufferManager.bufferGetCallee

      deframer.framedDeallocate -> bufferManager.bufferSendIn

      deframer.comOut -> cmdDisp.seqCmdBuff
      cmdDisp.seqCmdStatus -> deframer.cmdResponseIn

      deframer.bufferAllocate -> bufferManager.bufferGetCallee
      deframer.bufferDeallocate -> bufferManager.bufferSendIn
    }

    #Uncomment RadioComms and comment SerialComms to swap to radio
    #connections RadioComms {
      # Downlink
      #tlmSend.PktSend -> commQueue.comQueueIn[0]
      #eventLogger.PktSend -> commQueue.comQueueIn[1]

      #commQueue.comQueueSend -> framer.comIn

      #framer.framedAllocate -> bufferManager.bufferGetCallee
      #framer.framedOut -> rfm69.comDataIn
      #rfm69.deallocate -> bufferManager.bufferSendIn

      #rfm69.comStatus -> commQueue.comStatusIn

      # Uplink
      #rfm69.allocate -> bufferManager.bufferGetCallee
      #rfm69.comDataOut -> deframer.framedIn
      #deframer.framedDeallocate -> bufferManager.bufferSendIn

      #deframer.comOut -> cmdDisp.seqCmdBuff
      #cmdDisp.seqCmdStatus -> deframer.cmdResponseIn

      #deframer.bufferAllocate -> bufferManager.bufferGetCallee
      #deframer.bufferDeallocate -> bufferManager.bufferSendIn
    #}

    connections I2c {
      imu.read -> i2cDriver.read
      imu.write -> i2cDriver.write
    }

    connections BaremetalReference {
      # Add here connections to user-defined components
      blinker.gpioSet -> gpioDriver.gpioWrite
      #rfm69.gpioReset -> gpioRadioReset.gpioWrite ### //Turn off for Uart Comm
    }

  }

}
