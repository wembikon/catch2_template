enable_testing()

add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/Catch2 Catch2)
# Tell cmake to locate the Catch2 test registration cmake scripts
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
    ${CMAKE_SOURCE_DIR}/thirdparty/Catch2/contrib)

add_executable(UnitTest main.cpp calc_test.cpp)
target_link_libraries(UnitTest CalcLib Catch2::Catch2)

include(Catch)
catch_discover_tests(UnitTest)

