cmake_minimum_required(VERSION 3.10)
project(
    OrbitalMechanics
    VERSION 0.0.1
    DESCRIPTION "Modelling 2-Body Problem"
    LANGUAGES CXX
)

# Build OrbitalMechanics
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
    ${PROJECT_SOURCE_DIR}/dependencies/asio/
    ${PROJECT_SOURCE_DIR}/dependencies/crow/
)

add_executable(
    ${PROJECT_NAME} 
    src/main.cpp
    src/Body.cpp
    src/nbody_simulation.cpp
    src/two_body_model.cpp
)

find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)

# Build Test Suites
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Test Body struct
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

# Test nbody simulation
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