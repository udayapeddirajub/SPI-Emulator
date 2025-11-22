cmake_minimum_required(VERSION 3.10)
project(SPI_Emulator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Header-only SPI library
add_library(spi_lib INTERFACE)
target_include_directories(spi_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(spi_test tests/test_spi.cpp)
target_link_libraries(spi_test PRIVATE gtest gtest_main pthread spi_lib)

add_executable(spi_demo src/main.cpp)
target_link_libraries(spi_demo PRIVATE spi_lib)

add_test(NAME SPITests COMMAND spi_test)
