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
fprime-gds -n --dictionary ./build-artifacts/YOUR_DEVICE/BaremetalReference/dict/BaremetalReferenceTopologyAppDictionary.xml --comm-adapter uart --uart-device /dev/ttyACM0 --uart-baud 115200
```
Note:
  - If you have more than one device connected, or if you are using a different OS, `/dev/ttyACM0` may differ for your system.
  - Change `YOUR_DEVICE` to the respective device of the Baremetal Reference. (i.e. `teensy41`, `featherM0`)