# Programming and Running BaremetalReference Application in Serial Mode
Current BaremetalReference has been set to communicate by serial and without the radio. Radio can be re-enabled (currently commented out), see this [section](#programming-and-running-the-baremetalreference-and-radiopassthrough-applications) for instructions.

## Uploading hex file for the Teensy
1. Use `fprime-util build` to make the hex file to load onto Teensy.

Note: There are depencies that may need to be updated. Change file extension of this file from .pde to .ino: `fprime-baremetal-reference/lib/arduino/fprime-arduino/ATmega/vendor/libraries/TimerOne/examples/FanSpeed/FanSpeed.pde`
Without doing this during upload you will get the following message:
`Sketches with .pde extension are deprecated, please rename the following files to .ino`

2. Have the Teensy connected to the computer and press the button the board to put it in the HalfKay bootloader mode. Board should now have a solid red led lit by the usb port.

Note: Teensy has 2 different serial addresses, one for when programming is running and one for when the board is in HalfKay bootloader mode. Right now you will need the latter. To determine the address do one of three things (after putting the board in HalfKay bootloader mode):
- Run command `arduino-cli board list`. Look for `usb:xxxxxxx` that should have protocol `teensy`. This also lists the fully qualified board name (FQBN) that we will use in the next step.
- Use Arduino IDE. Under Tools -> Port, select port listed under teensy port. After this go to Tools tab again and now Port should print out the usb address similar to `usb:xxxxxxxx`.
- if on a Mac, About -> System Report. Look for USB Serial device. Manufacturer should be Teensyduino. Location id given is the address.

3. Program the reference hex file:
```sh
arduino-cli upload --fqbn teensy:avr:teensy41 -p usb:3120000 -i /full_path/fprime-baremetal-reference/build-artifacts/teensy41/BaremetalReference/bin/BaremetalReference.hex
```

Note: It has to be the full path to the BaremetalReference.hex file for arduino-cli. So no `./`

4. While programming the red led will be brighter and then flash. Once done the board will get out of HalfKay bootloader mode (red led off) and run the BaremetalReference application. You should now see an orange flashing led by the button.

### Alternate option for hex file upload
Instead of using arduino-cli, you can also use teensy_loader_cli. This alternative is best if you are running on a headless machine / SBC and using SSH. teensy_loader_cli requires compiling on the host machine but usage is simpler.

1. After building the hex file, simply call:
```
teensy_loader_cli --mcu=TEENSY41 -v -s /full_path/fprime-baremetal-reference/build-artifacts/teensy41/BaremetalReference/bin/BaremetalReference.hex
```

## Using GDS via serial
1. Find the serial port, this varies by your host system but it should show up as a `/dev/tty*` device. On the mac, it's /dev/tty.usbmodem*(9 digit number).
2. Launch GDS: 
```sh
fprime-gds -n --dictionary ./build-artifacts/teensy41/BaremetalReference/dict/BaremetalReferenceTopologyAppDictionary.xml --communication-selection uart --uart-device /dev/tty.usbmodem159910601 --uart-baud 115200
```
3. GDS should now launch in your browser. Connection should be good, you should see a green circle in the upper right by the warning hi, fatal, and GDS errors counter table. If connection is bad, instead of a green circle you would see a red X.

## Running BaremetalReference integration tests
BaremetalReference comes with a set of integration tests. With board connecting and GDS running:
```sh
pytest BaremetalReference/test/int/baremetal_ref_integration_test.py --dictionary ./build-artifacts/teensy41/BaremetalReference/dict/BaremetalReferenceTopologyAppDictionary.xml
```
This will run through the test and give you results. With GDS up you can check the Events tab and see EVRs come in as the test runs.

There are various options that you can try with pytest, see their documentation for more information. To run the test with a more verbose output, try options `-s` `-rP`. Both offer similar verbose outputs but `-s` outputs real time while `-rP` outputs at the end of testing and shows the beginning and end of tests.

You can also run specific tests:
```sh
pytest BaremetalReference/test/int/baremetal_ref_integration_test.py --dictionary ./build-artifacts/teensy41/BaremetalReference/dict/BaremetalReferenceTopologyAppDictionary.xml -k 'test_id'
```
This runs just the `test_id_filter` test. Note that this is string / pattern matching so you don't need to type in the full name. With this comes limitations:
```
pytest BaremetalReference/test/int/baremetal_ref_integration_test.py --dictionary ./build-artifacts/teensy41/BaremetalReference/dict/BaremetalReferenceTopologyAppDictionary.xml -k 'test_send_command'
```
This runs both `test_send_command` and `test_send_command_args` because both tests satisfy the pattern.

# Programming and Running the BaremetalReference and RadioPassthrough Applications
You will need two microcontrollers: one that will run the BaremetalReference and the other for the RadioPassthrough. The goal is to command the BaremetalReference deployment wirelessly from the RadioPassthrough deployment using a radio and fprime-gds. The BaremetalReference deployment is a reference of components that spacecrafts are expected to have, such as the LED blinker and radio components.

## Uploading hex file for the Teensy
The Teensyduino application should have appeared after running `fprime-util build`. Choose the appropriate hex file to load into Teensyduino, either BaremetalReference or RadioPassthrough, located in `./build-artifacts/BareMetalReference/bin/` or `./build-artifacts/RadioPassthrough/bin/`, respectively. Manually press the reset button on the Teensy to upload the program.

## Uploading binary file for the Feather M0
Double press on the reset button on the Feather to set it to programming mode. Then run the following commands below for the respective port. There are two binary files: one for the Baremetal Reference and another for the Radio Passthrough. 
```sh
~/.arduino15/packages/adafruit/tools/bossac/1.8.0-48-gb176eee/bossac -i -d --port=ttyACM0 -U -i --offset=0x2000 -w -v ./build-artifacts/featherM0/RadioPassthrough/bin/RadioPassthrough.bin -R
~/.arduino15/packages/adafruit/tools/bossac/1.8.0-48-gb176eee/bossac -i -d --port=ttyACM1 -U -i --offset=0x2000 -w -v ./build-artifacts/featherM0/BaremetalReference/bin/BaremetalReference.bin -R

```
Note:
  - If you have other devices connected, or if you are using a different OS, `ttyACM0` and/or `ttyACM1` may differ for your system.

## Using GDS over serial
```sh
fprime-gds -n --dictionary ./build-artifacts/YOUR_DEVICE/BaremetalReference/dict/BaremetalReferenceTopologyAppDictionary.xml --communication-selection uart --uart-device /dev/ttyACM0 --uart-baud 115200
```
Note:
  - If you have more than one device connected, or if you are using a different OS, `/dev/ttyACM0` may differ for your system.
  - Change `YOUR_DEVICE` to the respective device of the Baremetal Reference. (i.e. `teensy41`, `featherM0`)