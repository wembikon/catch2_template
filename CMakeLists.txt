cmake_minimum_required(VERSION 3.16)

project(catch2_template LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

include(CTest)
add_subdirectory(src)
add_subdirectory(exe)
add_subdirectory(test)

