\# SPI Emulator Project



A C++ project that emulates the SPI (Serial Peripheral Interface) protocol to demonstrate master-slave communication. Includes unit tests and automated CI/CD setup with GitHub Actions.



\*\*\*



\## Folder Structure



```

/SPI\_Emulator\_Project

├── /src                # Source files

│   ├── SPI.h           # SPI master-slave interface

│   ├── SlaveDevice.h   # SPI slave implementation

│   └── main.cpp        # Demo program entry-point

├── /tests              # Unit tests

│   └── test\_spi.cpp    # GoogleTest unit tests

├── /.github/workflows  # CI/CD pipeline configs

│   └── ci.yml          # GitHub Actions workflow

├── CMakeLists.txt      # Build configuration

└── README.md           # Project documentation

```



\*\*\*



\## Getting Started (Visual Studio)



\### Prerequisites



\- \*\*Visual Studio 2017 or later\*\*, with C++ development workload installed  

\- \*\*CMake support\*\* is built into Visual Studio  

\- \*\*GoogleTest\*\* can be installed via \[vcpkg](https://github.com/microsoft/vcpkg/) or integrated manually  



\### Build and Run



1\. Open Visual Studio and select \*\*File → Open → Folder\*\*  

2\. Open the project root folder containing `CMakeLists.txt`  

3\. Visual Studio will automatically configure and generate build files using CMake  

4\. Use the \*\*Solution Explorer\*\* to build targets:  

&nbsp;  - `spi\_demo` to run the SPI demo program  

&nbsp;  - `spi\_test` to run unit tests (also accessible via Test Explorer)  



No manual `mkdir build` or `cmake ..` commands are necessary unless you want to build outside Visual Studio.



\*\*\*



\## Using Git and CI/CD



\- When you edit code and push to your GitHub repository, \*\*you do NOT need to build or run tests locally\*\*.  

\- The \*\*GitHub Actions CI/CD pipeline\*\* defined in `.github/workflows/ci.yml` will automatically:  

&nbsp; - Build your code  

&nbsp; - Run all unit tests  

&nbsp; - Report build/test results on GitHub for your pull requests and pushes  



This helps maintain code quality and verifies your changes without manual build steps.



\*\*\*



\## Build and Test Commands (If using command line)



Alternatively, if building manually on any system with CMake and compiler installed, run from the project root:



```bash

mkdir build  #creates a new folder in root as build

cd build

cmake ..

make

./spi\_demo             # Run demo program

ctest --output-on-failure  # Run unit tests, show details if failures occur

```



\*\*\*



\## File Descriptions



\- `src/SPI.h`: Defines SPI master and slave classes  

\- `src/SlaveDevice.h`: A sample slave device that echoes data  

\- `src/main.cpp`: Program demonstrating SPI data transfer  

\- `tests/test\_spi.cpp`: Unit tests verifying SPI behavior  

\- `CMakeLists.txt`: Build configuration integrating GoogleTest and executables  

\- `.github/workflows/ci.yml`: Automates build/test on GitHub



\*\*\*

