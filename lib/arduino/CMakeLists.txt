####
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding files
# MOD_DEPS: (optional) module dependencies
#
# Note: using PROJECT_NAME as EXECUTABLE_NAME
####
string(FIND "${FPRIME_TOOLCHAIN_NAME}" "teensy" index)
if (NOT index EQUAL -1)
    set(SOURCE_FILES
        "${CMAKE_CURRENT_LIST_DIR}/RadioHead/RH_RF69.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/RadioHead/RHHardwareSPI.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/RadioHead/RHGenericSPI.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/RadioHead/RHGenericDriver.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/RadioHead/RHSPIDriver.cpp"
    )

    string(FIND "${FPRIME_TOOLCHAIN_NAME}" "teensy4" index2)
    if (NOT index2 EQUAL -1)
        set(SOURCE_FILES
            "${SOURCE_FILES}"
            "${CMAKE_CURRENT_LIST_DIR}/RadioHead/RHHardwareSP1I.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/RadioHead/RHHardwareSP12.cpp"
        )
    endif()

    add_library(RadioHead ${SOURCE_FILES})
    target_include_directories(RadioHead PUBLIC "${CMAKE_CURRENT_LIST_DIR}/RadioHead")
endif()
