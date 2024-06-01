# understanding_software_dynamics

## Introduction

Reading the
book ["Understanding Software Dynamics" by Richard L. Sites](https://www.goodreads.com/book/show/57850403-understanding-software-dynamics).

## Prerequisites

Before you can build and run the project, you need to have the following installed:

- **CMake** (version 3.8 or higher)
- **A C++ compiler** (GCC, Clang, etc.)

### Installing Prerequisites on Mac

You can install the required tools using Homebrew:

```sh
brew install cmake
brew install gcc
```

### Installing Prerequisites on Linux

You can install the required tools using your distribution's package manager. For example, on Ubuntu:

```sh
sudo apt-get update
sudo apt-get install cmake g++
```

## Building the Project

### Building on Mac (AARCH64)

To build the project for Mac (AARCH64), run the following commands:

```sh
./scripts/build-mac-aarch64.sh
```

### Building on Linux

To build the project for Linux, run the following commands:

```sh
mkdir -p build
cd build
cmake ..
make
```

## Running the Binaries

After building the project, you can run the binaries from the `build/bin` directory. For example:

```sh
./build/bin/mystery0
./build/bin/mystery0_opt
./build/bin/mystery0_unroll
./build/bin/mystery0_unroll2
./build/bin/mystery0_unroll2_sums
```

Each binary will execute its respective functionality and print the instrumentation report.
