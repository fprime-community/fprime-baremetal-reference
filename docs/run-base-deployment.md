# Programming and Running the BaseDeployment Application on Hardware
The goal is to be able to establish a connection bewteen a microcontroller and fprime-gds. From there, you will be able to enable/disable the LED blinking as well as adjusting the blinking interval. This base deployment utilizes minimal F' components and an LED blinker component.

## Uploading hex file for the Teensy
The Teensyduino application should have appeared after running `fprime-util build`. Choose the hex file to load into Teensyduino located in `./build-artifacts/BaseDeployment/bin/`. Manually press the reset button on the Teensy to upload the program.

## Uploading binary file for the Feather M0
Double press on the reset button on the Feather to set it to programming mode. Then run the following commands below.

```sh
~/.arduino15/packages/adafruit/tools/bossac/1.8.0-48-gb176eee/bossac -i -d --port=ttyACM0 -U -i --offset=0x2000 -w -v ./build-artifacts/featherM0/BaseDeployment/bin/BaseDeployment.bin -R

```
Note:
  - If you have more than one device connected, or if you are using a different OS, `ttyACM0` may differ for your system.

## Using GDS over serial
```sh
fprime-gds -n --dictionary ./build-artifacts/YOUR_DEVICE/BaseDeployment/dict/BaseDeploymentTopologyAppDictionary.xml --comm-adapter uart --uart-device /dev/ttyACM0 --uart-baud 115200
```
Note:
  - If you have more than one device connected, or if you are using a different OS, `/dev/ttyACM0` may differ for your system.
  - Change `YOUR_DEVICE` to the respective device. (i.e. `teensy41`, `featherM0`)

### Next Step: [Building and Running the Baremetal Reference on Hardware](./run-baremetal-reference.md)