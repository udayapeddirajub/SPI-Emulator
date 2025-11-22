#build configuration

cmake_minimum_required(VERSION 3.10)  # Set minimum required CMake version

project(SPI_Emulator)                 # Name of the project, can be any

set(CMAKE_CXX_STANDARD 14)             # Use C++14 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)   # Make C++14 mandatory

enable_testing()                     # Enable test targets to be recognized in CTest

# Define a library target from headers (headers only here)
add_library(spi_lib src/SPI.h src/SlaveDevice.h)

# Define an executable for unit tests
add_executable(spi_test tests/test_spi.cpp)

# Link GoogleTest libraries and pthread to the test executable for running tests
target_link_libraries(spi_test PRIVATE gtest gtest_main pthread)

# Define main demo executable that demonstrates SPI transfer
add_executable(spi_demo src/main.cpp)

# Link the SPI library to the demo executable
target_link_libraries(spi_demo PRIVATE spi_lib)

# Register the test executable with CTest under the name SPITests
add_test(NAME SPITests COMMAND spi_test)
