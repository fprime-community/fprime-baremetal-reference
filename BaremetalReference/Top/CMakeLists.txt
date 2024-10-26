####
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding files
# MOD_DEPS: (optional) module dependencies
####

set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/instances.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/topology.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/BaremetalReferenceTopology.cpp"
)
set(MOD_DEPS
  Fw/Logger
  Arduino/ArduinoTime
  Arduino/Drv/StreamDriver
  Arduino/Drv/I2cDriver
#  Os/Baremetal/TaskRunner
)

register_fprime_module()
