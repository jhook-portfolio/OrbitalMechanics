cmake_minimum_required(VERSION 3.10)
project(
    OrbitalMechanics
    VERSION 0.0.1
    DESCRIPTION "Modelling 2-Body Problem"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
    main 
    src/main.cpp
    src/Body.cpp
    src/nbody_simulation.cpp
)

enable_testing()
add_executable(
    body_test
    tests/body_test.cc
    src/Body.cpp
)

target_link_libraries(
    body_test
    GTest::gtest
    GTest::gtest_main
)

add_executable(
    nbody_simulation_test
    tests/nbody_simulation_test.cc
    src/nbody_simulation.cpp
    src/Body.cpp
)

target_link_libraries(
    nbody_simulation_test
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(body_test)
gtest_discover_tests(nbody_simulation_test)