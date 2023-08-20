cmake_minimum_required(VERSION 3.15)

###########################################################
# Project definition and global settings                  #
###########################################################
set(PROJECT_NAME "core")

project(${PROJECT_NAME} CXX)

###########################################################
# Conan dependencies                                      #
###########################################################
conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE ../../../packages/core
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings}
                    OUTPUT_FOLDER ${CMAKE_BINARY_DIR})

###########################################################
# Find sources and dependencies                           #
###########################################################
file(GLOB_RECURSE H_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
file(GLOB_RECURSE CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_dependencies(${PROJECT_NAME} graphics)

find_package(glfw3 REQUIRED)


# Create a list to hold the directories
# Extract unique directories from the list of header files
set(INCLUDE_DIRS "")

foreach(_file ${H_FILES})
    get_filename_component(_dir ${_file} DIRECTORY)
    list(APPEND INCLUDE_DIRS ${_dir})
endforeach()

# Remove duplicate directories
list(REMOVE_DUPLICATES INCLUDE_DIRS)


###########################################################
# Create library                                          #
###########################################################
add_library(${PROJECT_NAME} STATIC ${H_FILES} ${CPP_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE graphics)
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})
