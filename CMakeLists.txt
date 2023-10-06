cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)
project ("MyPlugin" CXX C)

include_directories(${PROJECT_SOURCE_DIR}/headers)

set(CMAKE_BUILD_TYPE "Release")

# Êä³öÂ·¾¶
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/debug/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/release/)

add_library(MyPlugin.plg SHARED  "src/example.cpp")

# ºó×º
set_target_properties(MyPlugin.plg PROPERTIES PREFIX "" SUFFIX "")