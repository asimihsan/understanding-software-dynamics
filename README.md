<h1 align="center">
  understanding_software_dynamics
</h1>

<h4 align="center">Reading the book "Understanding Software Dynamics" by Richard L. Sites</h4>

<p align="center">
  <a href="#prerequisites">Prerequisites</a> •
  <a href="#building-the-project">Building the Project</a> •
  <a href="#running-the-binaries">Running the Binaries</a>
</p>

`understanding_software_dynamics` is a project that involves reading and implementing concepts from the
book ["Understanding Software Dynamics" by Richard L. Sites](https://www.goodreads.com/book/show/57850403-understanding-software-dynamics).

## Prerequisites

Before you can build and run the project, you need to have the following installed:

- **CMake** (version 3.8 or higher)
- **A C++ compiler** (GCC, Clang, etc.)

### Installing Prerequisites on Mac

You can install the required tools using Homebrew:

```sh
brew install cmake
brew install clang
```

### Installing Prerequisites on Linux

You can install the required tools using your distribution's package manager. For example, on Ubuntu:

```sh
sudo apt-get update
sudo apt-get install cmake g++
```

## Building the Project

### Building on Mac (aarch64)

To build the project for Mac (aarch64), run the following commands:

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
