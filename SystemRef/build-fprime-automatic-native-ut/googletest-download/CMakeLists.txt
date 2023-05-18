cmake_minimum_required(VERSION 2.8.12)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           a3460d1
  SOURCE_DIR        "/home/ethan/jpl/projects/BareMetal/fprime/gtest/googletest-src"
  BINARY_DIR        "/home/ethan/jpl/projects/BareMetal/fprime/gtest/googletest-build-Linux"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
