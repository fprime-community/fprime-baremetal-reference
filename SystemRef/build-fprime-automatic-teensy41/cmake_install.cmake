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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/bin" TYPE EXECUTABLE FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/bin/teensy41/SystemRef")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/bin/SystemRef" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/bin/SystemRef")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/ethanchee/.arduino15/packages/teensy/tools/teensy-compile/11.3.1/arm/bin/arm-none-eabi-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/bin/SystemRef")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libconfig.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_Cfg.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_Types.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_Logger.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_Obj.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_Port.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_Time.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_Comp.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_Time.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libArduino_ArduinoTime.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_Com.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_Tlm.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_Log.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_Cmd.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_Prm.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_Buffer.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libUtils_Hash.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libOs.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libDrv_ByteStreamDriverModel.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_Sched.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libArduino_Drv_SerialDriver.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libDrv_GpioDriverPorts.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_CompQueued.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSystemRef_LedBlinker.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libArduino_Drv_GpioDriver.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_Cycle.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libArduino_Drv_HardwareRateDriver.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libDrv_DataTypes.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_Ping.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libDrv_BlockDriver.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_Fatal.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_ActiveLogger.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_ActiveRateGroup.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_AssertFatalAdapter.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_BufferManager.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_CmdDispatcher.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_Seq.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_CmdSequencer.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_Ports_SuccessCondition.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_ComStub.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libUtils_Types.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_FramingProtocol.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_Deframer.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_FatalHandler.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libCFDP_Checksum.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libFw_FilePacket.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_FileDownlinkPorts.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_FileDownlink.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_FileManager.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_FileUplink.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_Framer.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_PassiveConsoleTextLogger.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_RateGroupDriver.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_StaticMemory.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_SystemResources.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSvc_TlmChan.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/lib/static" TYPE STATIC_LIBRARY FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/lib/teensy41/libSystemRef_Top.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xSystemRefx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/teensy41/SystemRef/dict" TYPE FILE FILES "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/SystemRef/Top/SystemRefTopologyAppDictionary.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/F-Prime/Autocoders/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/config/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/F-Prime/Fw/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/F-Prime/Svc/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/F-Prime/Os/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/F-Prime/Drv/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/F-Prime/CFDP/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/F-Prime/Utils/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/Arduino/Os/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/Arduino/ArduinoTime/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/Arduino/Drv/GpioDriver/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/Arduino/Drv/SerialDriver/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/Arduino/Drv/HardwareRateDriver/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/SystemRef/LedBlinker/cmake_install.cmake")
  include("/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/SystemRef/Top/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ethanchee/Documents/fprime-projects/fprime-baremetal/SystemRef/build-fprime-automatic-teensy41/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
