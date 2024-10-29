####
# 
####
cmake_minimum_required(VERSION 3.13)
project(BareMetal C CXX)
###
# F' Core Setup
# This includes all of the F prime core components, and imports the make-system.
###
include("${CMAKE_CURRENT_LIST_DIR}/lib/fprime/cmake/FPrime.cmake")
# NOTE: register custom targets between these two lines
include("${FPRIME_FRAMEWORK_PATH}/cmake/FPrime-Code.cmake")

# This includes project-wide objects
include("${CMAKE_CURRENT_LIST_DIR}/project.cmake")
set_target_properties(Svc_FatalHandler PROPERTIES EXCLUDE_FROM_ALL TRUE)
