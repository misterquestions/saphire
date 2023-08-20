cmake_minimum_required(VERSION 3.10)

###########################################################
# Project definition and global settings                  #
###########################################################
set(PROJECT_NAME "starter-template")

project(${PROJECT_NAME} CXX)

###########################################################
# Create executable                                       #
###########################################################
add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE core)