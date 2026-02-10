# Programming and Running the BaseDeployment Application on Hardware
The goal is to be able to establish a connection bewteen a microcontroller and fprime-gds. From there, you will be able to enable/disable the LED blinking as well as adjusting the blinking interval. This base deployment utilizes minimal F' components and an LED blinker component.

## Generating the Cache and Building the Project
Unless you're targeting the FeatherM0, change your default toolchain in ```settings.ini``` located at the root of this reference repository. Common toolchains can be found [here](https://github.com/fprime-community/fprime-arduino/tree/main/cmake/toolchain).

Make sure to run ```fprime-util generate -f``` and ```fprime-util build``` before proceeding to the following steps. If you suspect any erroneous errors with ```fprime-util generate -f```, switch to the "make" build system from the default,which is "ninja", by running ```fprime-util generate -f --make```.

## Uploading hex file for the Teensy
The Teensyduino application should have appeared after running `fprime-util build`. Choose the hex file to load into Teensyduino located in `./build-artifacts/ReferenceDeployment/bin/`. Manually press the reset button on the Teensy to upload the program.

## Uploading binary file for the Feather M0
Double press on the reset button on the Feather to set it to programming mode. Then run the following commands below.
```sh
~/.arduino15/packages/adafruit/tools/bossac/1.8.0-48-gb176eee/bossac -i -d --port=ttyACM0 -U -i --offset=0x2000 -w -v ./build-artifacts/featherM0/ReferenceDeployment/bin/ReferenceDeployment.bin -R
```

## Uploading hex file for the STM32
Find the hex file after running ```fprime-util build``` in ```./build-artifacts/ReferenceDeployment/bin/```. Use STLink to flash it onto your STM32 board. Make sure to have the correct udev permissions if you're on Linux.

# Using GDS over serial
Make sure to ensure that the framing protocol between your board and ```fprime-gds``` are consistent with each other. ```fprime-gds -h``` for more detail about proper flag usage to change framing protocol.
```sh
fprime-gds -n --dictionary ./build-artifacts/YOUR_DEVICE/ReferenceDeployment/dict/ReferenceDeploymentTopologyAppDictionary.json --communication-selection uart --uart-device /dev/ttyACM0 --uart-baud 115200
```

Note:
  - If you have more than one device connected, or if you are using a different OS, `/dev/ttyACM0` may differ for your system.
  - Change `YOUR_DEVICE` to the respective device. (i.e. `teensy41`, `featherM0`)

### Next Step: [Building and Running the Baremetal Reference on Hardware](./run-baremetal-reference.md)
