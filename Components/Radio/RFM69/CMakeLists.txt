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
set(MOD_DEPS
  RadioHead
)

# Uncomment and add any modules that this component depends on, else
# they might not be available when cmake tries to build this component.

target_use_arduino_libraries("SPI")

register_fprime_module()
