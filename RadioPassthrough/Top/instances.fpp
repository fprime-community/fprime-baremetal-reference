module RadioPassthrough {

  # ----------------------------------------------------------------------
  # Defaults
  # ----------------------------------------------------------------------

  module Default {
    constant QUEUE_SIZE = 3
    constant STACK_SIZE = 64 * 1024
  }

  # ----------------------------------------------------------------------
  # Active component instances
  # ----------------------------------------------------------------------

  instance rateGroup1: Svc.ActiveRateGroup base id 0x0200 \
    queue size Default.QUEUE_SIZE \
    stack size Default.STACK_SIZE \
    priority 120

  instance rateGroup2: Svc.ActiveRateGroup base id 0x0300 \
    queue size Default.QUEUE_SIZE \
    stack size Default.STACK_SIZE \
    priority 120

  instance commQueue: Svc.ComQueue base id 0x0600 \
      queue size 5 \
      stack size Default.STACK_SIZE \
      priority 100 \

  instance eventLogger: Svc.ActiveLogger base id 0x0B00 \
    queue size Default.QUEUE_SIZE \
    stack size Default.STACK_SIZE \
    priority 98

  instance tlmSend: Svc.TlmChan base id 0x0C00 \
    queue size Default.QUEUE_SIZE \
    stack size Default.STACK_SIZE \
    priority 97

  # ----------------------------------------------------------------------
  # Queued component instances
  # ----------------------------------------------------------------------

  # ----------------------------------------------------------------------
  # Passive component instances
  # ----------------------------------------------------------------------

  instance downlink: Svc.Framer base id 0x4000

  instance fatalAdapter: Svc.AssertFatalAdapter base id 0x4100

  instance fatalHandler: Svc.FatalHandler base id 0x4200

  instance systemTime: Svc.Time base id 0x4300 \
    type "Svc::ArduinoTimeImpl" \
    at "../../lib/arduino/fprime-arduino/Arduino/ArduinoTime/ArduinoTimeImpl.hpp"

  instance rateGroupDriver: Svc.RateGroupDriver base id 0x4400

  instance staticMemory: Svc.StaticMemory base id 0x4500

  instance textLogger: Svc.PassiveTextLogger base id 0x4600

  instance systemResources: Svc.SystemResources base id 0x4800

  instance rateDriver: Arduino.HardwareRateDriver base id 0x4900

  instance commDriver: Arduino.StreamDriver base id 0x4B00
  
  instance gpioDriver: Arduino.GpioDriver base id 0x4C00

  instance streamCrossoverUplink: Drv.StreamCrossover base id 0x4D00

  instance streamCrossoverDownlink: Drv.StreamCrossover base id 0x4E00

  instance blinker: Components.LedBlinker base id 0x6000

  instance rfm69: Radio.RFM69 base id 0x6100

}
