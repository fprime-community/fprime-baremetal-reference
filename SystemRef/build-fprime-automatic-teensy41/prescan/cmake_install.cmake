# Install script for directory: /home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-artifacts")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "1")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/home/ethanchee/.arduino15/packages/teensy/tools/teensy-compile/11.3.1/arm/bin/arm-none-eabi-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/F-Prime/Autocoders/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/config/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/F-Prime/Fw/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/F-Prime/Svc/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/F-Prime/Os/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/F-Prime/Drv/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/F-Prime/CFDP/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/F-Prime/Utils/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/Arduino/Os/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/Arduino/ArduinoTime/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/Arduino/Drv/GpioDriver/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/Arduino/Drv/SerialDriver/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/Arduino/Drv/HardwareRateDriver/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/SystemRef/LedBlinker/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/SystemRef/Top/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/prescan/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
