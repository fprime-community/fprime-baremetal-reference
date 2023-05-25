module Radio {
    @ Example radio component using the RFM69HCW radio
    active component RFM69 {

        @ Command to send packet
        async command SEND_PACKET(
                payload: string size 60
        )

        @ Telemetry channel for radio status
        telemetry Status: Fw.On

        @ Telemetry channel counting packets sent
        telemetry NumPacketsSent: U16

        @ Telemetry channel counting packets received
        telemetry NumPacketsReceived: U16

        @ Telemetry channel for radio RSSI
        telemetry RSSI: I16

        @ Prints received packet payload
        event PayloadMessage(msg: string size 60) \
            severity warning low \
            format "Payload: {}"

        @ Port receiving calls from the rate group
        sync input port run: Svc.Sched

        @ Port sending calls to the GPIO driver
        output port gpioSet: Drv.GpioWrite

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