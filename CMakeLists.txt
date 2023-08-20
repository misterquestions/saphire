cmake_minimum_required(VERSION 3.15)

###########################################################
# Project definition and global settings                  #
###########################################################
project(Saphire)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE STRING "" FORCE)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "")

###########################################################
# Conan setup                                             #
###########################################################
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

add_definitions("-std=c++11")

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

###########################################################
# Include sub-projects or libraries                       #
###########################################################
add_subdirectory(examples/starter_template)
add_subdirectory(packages/core)
add_subdirectory(packages/graphics)
