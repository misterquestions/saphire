cmake_minimum_required(VERSION 3.15)

###########################################################
# Project definition and global settings                  #
###########################################################
set(PROJECT_NAME "graphics")

project(${PROJECT_NAME} CXX)

###########################################################
# Conan dependencies                                      #
###########################################################
conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE ../../../packages/graphics
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings}
                    OUTPUT_FOLDER ${CMAKE_BINARY_DIR})

###########################################################
# Find sources and dependencies                           #
###########################################################
file(GLOB_RECURSE H_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)
file(GLOB_RECURSE CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

find_package(glfw3 3.3 REQUIRED)

###########################################################
# Create library                                          #
###########################################################
add_library(${PROJECT_NAME} STATIC ${H_FILES} ${CPP_FILES})

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
target_include_directories(${PROJECT_NAME} PUBLIC ${glfw3_INCLUDE_DIRS})