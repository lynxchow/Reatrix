cmake_minimum_required(VERSION 2.8)

project(Reatrix)

get_filename_component(RTX_LIB_DIR
                       ${CMAKE_SOURCE_DIR}/src
                       ABSOLUTE)

#set(PROJECT_SRC_DIR ${CMAKE_SOURCE_DIR})

include_directories(src/display)
include_directories(src/mac)
include_directories(src)
#file(GLOB_RECURSE DIR_SRCS mac/*.cpp mac/*.h mac/*.c mac/*cc mac/*.m mac/*.mm)

file(GLOB RTX_LIB_SRC
     ${RTX_LIB_DIR}/*.h
     ${RTX_LIB_DIR}/*.cpp
     ${RTX_LIB_DIR}/display/*.h
     ${RTX_LIB_DIR}/display/*.cpp
     ${RTX_LIB_DIR}/mac/*.h
     ${RTX_LIB_DIR}/mac/*.cpp
     ${RTX_LIB_DIR}/mac/*.m
     ${RTX_LIB_DIR}/mac/*.mm
     )

add_library(Reatrix ${RTX_LIB_SRC})
