module Sensors {

    @ The power state enumeration
    enum PowerState {OFF, ON}

    @ 3-tuple type used for telemetry
    array imuTlm = [3] F32

    @ Component for the SparkFun MPU9250 IMU Breakout
    passive component IMU_MPU9250 {

        @ Port that reads data from device
        output port read: Drv.I2c

        @ Port that writes data to device
        output port write: Drv.I2c

        # ----------------------------------------------------------------------
        # Telemetry
        # ----------------------------------------------------------------------

        @ X, Y, Z acceleration from accelerometer
        telemetry accelerometer: imuTlm id 0 update always format "{} g"

        @ X, Y, Z degrees from gyroscope
        telemetry gyroscope: imuTlm id 1 update always format "{} deg/s"

        # ----------------------------------------------------------------------
        # Special ports
        # ----------------------------------------------------------------------

        @ Port receiving calls from the rate group
        sync input port run: Svc.Sched

        # ----------------------------------------------------------------------
        # Commands
        # ----------------------------------------------------------------------

        @ Command to turn on the device
        guarded command PowerSwitch(powerState: PowerState)

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