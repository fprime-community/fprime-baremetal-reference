module Radio {
    @ Example radio component using the RFM69HCW radio
    passive component RFM69 {

        # ----------------------------------------------------------------------
        # Framer, deframer, and queue ports
        # ----------------------------------------------------------------------

        @ Data coming in from the framing component
        sync input port comDataIn: Drv.ByteStreamSend

        @ Status of the last radio transmission
        output port comStatus: Fw.SuccessCondition

        @ Com data passing back out
        output port comDataOut: Drv.ByteStreamRecv

        # ----------------------------------------------------------------------
        # Implementation ports
        # ----------------------------------------------------------------------

        @ Allows for deallocation of XBee command communications
        output port deallocate: Fw.BufferSend

        @ Allows for allocation of buffers
        output port allocate: Fw.BufferGet

        # ----------------------------------------------------------------------
        # Telemetry
        # ----------------------------------------------------------------------

        @ Telemetry channel for radio status
        telemetry Status: Fw.On

        @ Telemetry channel counting packets sent
        telemetry NumPacketsSent: U16

        @ Telemetry channel counting packets received
        telemetry NumPacketsReceived: U16

        @ Telemetry channel for radio RSSI
        telemetry RSSI: I16

        @ Prints received packet payload
        event PayloadMessageTX(msg: U32) \
            severity diagnostic \
            format "Payload Size Sent: {}"

        @ Prints received packet payload
        event PayloadMessageRX(msg: U32) \
            severity diagnostic \
            format "Payload Size Recevied: {}"

        # ----------------------------------------------------------------------
        # Special ports
        # ----------------------------------------------------------------------

        @ Port receiving calls from the rate group
        sync input port run: Svc.Sched

        @ Port sending calls to the GPIO driver
        output port gpioSet: Drv.GpioWrite

        # ----------------------------------------------------------------------
        # Commands
        # ----------------------------------------------------------------------

        @ Command to send packet
        sync command SEND_PACKET(
                payload: string size 60
        )

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}