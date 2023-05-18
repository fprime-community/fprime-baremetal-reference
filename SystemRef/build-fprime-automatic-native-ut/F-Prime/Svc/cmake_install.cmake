# Install script for directory: /home/ethan/jpl/projects/BareMetal/fprime/Svc

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/ethan/jpl/projects/BareMetal/SystemRef/build-artifacts")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/Cycle/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/Fatal/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/Ping/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/PolyIf/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/Sched/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/Seq/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/WatchDog/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/ActiveLogger/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/ActiveRateGroup/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/AssertFatalAdapter/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/BufferAccumulator/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/BufferManager/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/BufferLogger/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/BufferRepeater/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/ComLogger/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/ComQueue/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/ComSplitter/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/ComStub/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/CmdDispatcher/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/CmdSequencer/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/Deframer/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/FatalHandler/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/FileDownlinkPorts/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/FileDownlink/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/FileManager/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/FileUplink/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/GenericHub/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/GroundInterface/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/Framer/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/FramingProtocol/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/Health/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/PolyDb/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/PrmDb/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/RateGroupDriver/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/StaticMemory/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/Time/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/TlmChan/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/TlmPacketizer/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/SystemResources/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/PassiveConsoleTextLogger/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/ActiveTextLogger/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/LinuxTime/cmake_install.cmake")
  include("/home/ethan/jpl/projects/BareMetal/SystemRef/build-fprime-automatic-native-ut/F-Prime/Svc/LinuxTimer/cmake_install.cmake")

endif()

