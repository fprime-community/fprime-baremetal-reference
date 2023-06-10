# ======================================================================
# AcConstants.fpp
# F Prime configuration constants
# ======================================================================

@ Number of rate group member output ports for ActiveRateGroup
constant ActiveRateGroupOutputPorts = 10

@ Number of rate group member output ports for PassiveRateGroup
constant PassiveRateGroupOutputPorts = 10

@ Used to drive rate groups
constant RateGroupDriverRateGroupPorts = 2

@ Used for command and registration ports
constant CmdDispatcherComponentCommandPorts = 5

@ Used for uplink/sequencer buffer/response ports
constant CmdDispatcherSequencePorts = 1

@ Number of static memory allocations
constant StaticMemoryAllocations = 3

@ Used to ping active components
constant HealthPingPorts = 10

@ Used for broadcasting completed file downlinks
constant FileDownCompletePorts = 1

@ Used for number of Fw::Com type ports supported by Svc::ComQueue
constant ComQueueComPorts = 2

@ Used for number of Fw::Buffer type ports supported by Svc::ComQueue
constant ComQueueBufferPorts = 1

@ Used for maximum number of connected buffer repeater consumers
constant BufferRepeaterOutputPorts = 10

# ----------------------------------------------------------------------
# Hub connections. Connections on all deployments should mirror these settings.
# ----------------------------------------------------------------------

constant GenericHubInputPorts = 5
constant GenericHubOutputPorts = 5
constant GenericHubInputBuffers = 5
constant GenericHubOutputBuffers = 5
