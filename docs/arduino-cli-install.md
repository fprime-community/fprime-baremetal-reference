# Arduino CLI Installation Guide

## Install arduino-cli
```shell
mkdir -p ~/.local/bin
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
source ~/.bashrc  # or restart your terminal
```

Add the following line at the end of the file:
```
export PATH=~/.local/bin:$PATH
```

## Setup arduino-cli for Teensy and Adafruit boards
```shell
arduino-cli config init

# Linux
sudo nano ~/.arduino15/arduino-cli.yaml

# MacOS
sudo nano ~/Library/Arduino15/arduino-cli.yaml
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

## Adding udev rules (Linux Only)
Add udev rules. Download/save all the `.rules` files located [here](./rules/) into `/etc/udev/rules.d/`.

### Next Step: [Building and Running the Base Deployment on Hardware](./run-base-deployment.md)