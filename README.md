# My C Project

This is a sample C project using CMake for building and maintaining code snippets.

## Directory Structure

```
.
├── CMakeLists.txt
├── build/
├── chapters/
│   ├── chapter1/
│   │   ├── section1/
│   │   │   ├── CMakeLists.txt
│   │   │   ├── main.c
│   │   │   ├── snippet1.c
│   │   │   └── snippet1.h
│   │   └── section2/
│   │       ├── CMakeLists.txt
│   │       ├── main.c
│   │       ├── snippet2.c
│   │       └── snippet2.h
│   └── chapter2/
│       ├── section1/
│       │   ├── CMakeLists.txt
│       │   ├── main.c
│       │   ├── snippet3.c
│       │   └── snippet3.h
│       └── section2/
│           ├── CMakeLists.txt
│           ├── main.c
│           ├── snippet4.c
│           └── snippet4.h
.
├── CMakeLists.txt
├── build/
├── chapters/
│   ├── chapter1/
│   │   ├── section1/
│   │   │   ├── CMakeLists.txt
│   │   │   ├── main.c
│   │   │   ├── snippet1.c
│   │   │   └── snippet1.h
│   │   └── section2/
│   │       ├── CMakeLists.txt
│   │       ├── main.c
│   │       ├── snippet2.c
│   │       └── snippet2.h
│   └── chapter2/
│       ├── section1/
│       │   ├── CMakeLists.txt
│       │   ├── main.c
│       │   ├── snippet3.c
│       │   └── snippet3.h
│       └── section2/
│           ├── CMakeLists.txt
│           ├── main.c
│           ├── snippet4.c
│           └── snippet4.h
└── README.md
```

## Building the Project

```sh
mkdir -p build
cd build
cmake ..
make
```

## Running the Project

```sh
./chapter1/section1/chapter1_section1
./chapter1/section1/chapter1_section1
```
