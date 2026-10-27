cmake_minimum_required(VERSION 3.14)
project(MonteCarloCurrency VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.2
)
FetchContent_MakeAvailable(Catch2)

FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG        v1.8.3
)
set(BENCHMARK_ENABLE_TESTING OFF)
FetchContent_MakeAvailable(benchmark)

add_library(monte_carlo_lib src/monte_carlo.cpp)
target_include_directories(monte_carlo_lib PUBLIC include)

add_executable(monte_carlo_app src/main.cpp)
target_link_libraries(monte_carlo_app PRIVATE monte_carlo_lib)

enable_testing()
add_executable(test_monte_carlo tests/test_monte_carlo.cpp)
target_link_libraries(test_monte_carlo PRIVATE monte_carlo_lib Catch2::Catch2WithMain)
add_test(NAME MonteCarloTests COMMAND test_monte_carlo)

add_executable(bench_monte_carlo benchmarks/bench_monte_carlo.cpp)
target_link_libraries(bench_monte_carlo PRIVATE monte_carlo_lib benchmark::benchmark)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
endif()