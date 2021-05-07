cmake_minimum_required(VERSION 3.16)

project(catch2_template LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# - make this visible in ccmake by making this an `option` instead of a `set`.
# - you can still set it using cmake . -DCMAKE...=OFF/ON command
# - this is used by clang-tidy. refer to STATIC_ANALYSIS.md
option(CMAKE_EXPORT_COMPILE_COMMANDS "Generate compile_commands.json" OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

include(CTest)
add_subdirectory(src)
add_subdirectory(exe)
add_subdirectory(test)

