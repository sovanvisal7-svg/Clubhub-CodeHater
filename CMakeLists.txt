cmake_minimum_required(VERSION 3.28)
project(clubhub VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# =====================================
# Core Library
# =====================================

add_library(clubhub_core 
    src/event.cpp 
    src/event_csv.cpp
    src/Student.cpp
    src/ConsoleOutput.cpp
)

target_include_directories(clubhub_core PUBLIC include)
# target_compile_definitions(clubhub_core PRIVATE CLUBHUB_VERSION="${PROJECT_VERSION}")

# Strict compiler warnings (treat warnings as quality gates)
if(MSVC)
    target_compile_options(clubhub_core PRIVATE /W4)
else()
    target_compile_options(clubhub_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

# =====================================
# Main Application
# =====================================

add_executable(clubhub src/cli/main.cpp)

target_link_libraries(clubhub PRIVATE clubhub_core)

# =====================================
# FetchContent Dependencies
# =====================================

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
    rapidcsv
    GIT_REPOSITORY https://github.com/d99kris/rapidcsv.git
    GIT_TAG v9.07
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(googletest rapidcsv)

# =====================================
# Testing
# =====================================

enable_testing()

include(GoogleTest)

add_executable(ConsoleOutputTest
    tests/ConsoleOutputTest.cpp
    src/ConsoleOutput.cpp
)

target_include_directories(ConsoleOutputTest PRIVATE include)

target_link_libraries(
    ConsoleOutputTest
    PRIVATE GTest::gtest_main
)

gtest_discover_tests(ConsoleOutputTest)

add_executable(csv_smoke_test
    tests/csv_smoke_test.cpp
)

target_link_libraries(
    csv_smoke_test
    PRIVATE
    rapidcsv
    GTest::gtest_main
)

gtest_discover_tests(
    csv_smoke_test
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
add_executable(cancellation_rule_test
    tests/cancellation_rule_test.cpp
)

target_include_directories(cancellation_rule_test PRIVATE include)

target_link_libraries(
    cancellation_rule_test
    PRIVATE GTest::gtest_main
)

gtest_discover_tests(cancellation_rule_test)