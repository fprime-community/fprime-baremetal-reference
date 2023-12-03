####
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding files
# MOD_DEPS: (optional) module dependencies
# UT_SOURCE_FILES: list of source files for unit tests
#
####
set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/RFM69.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/RFM69.cpp"
)

# Uncomment and add any modules that this component depends on, else
# they might not be available when cmake tries to build this component.

string(FIND "${FPRIME_TOOLCHAIN_NAME}" "teensy" index)
if (NOT index EQUAL -1)
  set(MOD_DEPS
    RadioHead
  )
  target_use_arduino_libraries("SPI")
else()
  target_use_arduino_libraries("SPI" "RH_RF69")
endif()

register_fprime_module()
