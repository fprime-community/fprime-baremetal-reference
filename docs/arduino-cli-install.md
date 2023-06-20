# Arduino CLI Installation Guide

## Install arduino-cli
```shell
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | BINDIR=~/.local/bin sh

```

## Install arduino-cli-wrapper
```shell
cd ~/.local/bin
git clone https://github.com/SterlingPeet/arduino-cli-cmake-wrapper.git
cd arduino-cli-cmake-wrapper
git checkout update/refactor
pip install .
```

## Add `~/.local/bin` to PATH
```shell
sudo nano ~/.bashrc
```

At the end of the file, add the following line:
```
export PATH=~/.local/bin:$PATH
```

## Setup arduino-cli for Teensy and Adafruit boards
```shell
arduino-cli config init
sudo nano ~/.arduino15/arduino-cli.yaml
```

Add the following URLs to the `board_manager` section:
```
board_manager:
  additional_urls:
    - https://www.pjrc.com/teensy/package_teensy_index.json
    - https://adafruit.github.io/arduino-board-index/package_adafruit_index.json
```

Download the new board package:
```shell
arduino-cli core update-index
arduino-cli core install teensy:avr
arduino-cli core install adafruit:samd
```

## Adding udev rules
Add udev rules. Save the `.rules` files located in `./docs/rules` into `/etc/udev/rules.d/`.

### Next Step: [Building and Running the Base Deployment on Hardware](./run-base-deployment.md)