<h1 align="center">
  understanding_software_dynamics
</h1>

<h4 align="center">Reading the book "Understanding Software Dynamics" by Richard L. Sites</h4>

<p align="center">
  <a href="#prerequisites">Prerequisites</a> •
  <a href="#building-the-project">Building the project</a> •
  <a href="#running-the-binaries">Running the binaries</a> •
  <a href="#chapter-2---measuring-cpus">Chapter 2 - Measuring CPUs</a>
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

### Installing prerequisites on Linux

You can install the required tools using your distribution's package manager. For example, on Ubuntu:

```sh
sudo apt-get update
sudo apt-get install cmake g++
```

## Building the project

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

## Running the binaries

After building the project, you can run the binaries from the `build/bin` directory. For example:

```sh
sudo ./build/aarch64/src/mystery0
sudo ./build/aarch64/src/mystery0_opt
sudo ./build/aarch64/src/mystery0_unroll
sudo ./build/aarch64/src/mystery0_unroll2
sudo ./build/aarch64/src/mystery0_unroll2_sums
```

Each binary will execute its respective functionality and print the instrumentation report. You need to use `sudo`
because we need privileged access to performance counters.

## Chapter 2 - Measuring CPUs

We are trying to estimate the number of cycles required to execute an add operation on a CPU. In doing so, we learn
about what lets a CPU running a single thread of instructions to execute them in parallel.

### Experiment summary

We use different versions of a simple loop incrementing a sum variable:

1. **`mystery0`**: Baseline version with no loop unrolling.
2. **`mystery0_unroll`**: Loop unrolling with 4 additions in each iteration.
3. **`mystery0_unroll2`**: Loop unrolling with 2 additions per iteration.
4. **`mystery0_unroll2_sums`**: Using two separate sum variables with loop unrolling.

### Performance metrics

Here are the key performance metrics observed from each experiment, rounded to three significant figures:

| Metric                       | `mystery0` | `mystery0_unroll` | `mystery0_unroll2` | `mystery0_unroll2_sums` |
|------------------------------|------------|-------------------|--------------------|-------------------------|
| Cycles per iteration         | 3.01       | 1.18              | 1.74               | 0.305                   |
| Elapsed time (ns)            | 1.91e9     | 3.01e9            | 2.23e9             | 7.89e8                  |
| Instructions                 | 2.80e10    | 1.15e10           | 1.70e10            | 1.15e10                 |
| Cycles                       | 6.02e9     | 9.42e9            | 6.98e9             | 2.44e9                  |
| Branches                     | 8.00e9     | 2.00e9            | 4.00e9             | 2.00e9                  |
| Branch misses                | 23,400     | 45,100            | 52,700             | 6,270                   |
| IPC                          | 4.65       | 1.22              | 2.44               | 4.72                    |
| Branch prediction miss rate  | 0.00       | 0.00              | 0.00               | 0.00                    |
| Branch prediction hit rate   | 1.00       | 1.00              | 1.00               | 1.00                    |
| Instructions per branch miss | 1.20e6     | 2.55e5            | 3.23e5             | 1.83e6                  |
| Instructions per branch hit  | 3.50       | 5.75              | 4.25               | 5.75                    |

- IPC is the number of instructions executed per cycle.
- Branch prediction miss rate is the percentage of branch instructions that were mispredicted.
- Branch prediction hit rate is the percentage of branch instructions that were correctly predicted.

### Key findings

When we unroll the loop from `mystery0` to `mystery0_unroll`, the number of cycles per iteration drops from 3.01 to
1.18. This happens because the CPU can handle more work in parallel with fewer loop control instructions. The
instruction count also falls from 2.80e10 to 1.15e10, which makes sense because we are checking the loop condition less
often. However, it's surprising that `mystery0_unroll` has the longest elapsed time of 3.01e9 ns. This shows that even
though we're running fewer instructions, it takes longer to finish. This could mean there is more competition for CPU
resources or other inefficiencies from unrolling the loop too much.

In `mystery0_unroll2`, we unroll the loop only twice instead of four times. Here, the cycles per iteration, instructions
executed, elapsed time, and IPC are all about halfway between `mystery0` and `mystery0_unroll`. This suggests that
unrolling the loop twice strikes a balance. We're reducing the loop overhead without causing as many inefficiencies.

In `mystery0_unroll2_sums`, we use two separate sum variables. This gives us the best results: the lowest cycles per
iteration (0.305), the shortest execution time, and the highest IPC (4.72). This shows the power of parallelism. By
using two separate sum variables, there is less waiting for previous calculations to finish. This allows the CPU to work
on more instructions at the same time, making better use of its resources.

To sum up, these experiments teach us several things about loop unrolling and parallel execution:

1. **Reducing loop overhead**: Unrolling the loop reduces how often the loop control instructions run, cutting down the
   total instruction count.
2. **Increasing parallelism**: Unrolling helps the CPU do more work in parallel, lowering the cycles per iteration.
3. **Resource competition**: Unrolling too much can cause more competition for CPU resources, which can slow down the
   overall execution time.
4. **Minimizing dependencies**: Using multiple sum variables reduces dependencies, allowing more parallel execution and
   better performance.

These points show the trade-offs involved in loop unrolling. It's important to balance reducing the loop overhead with
managing CPU resources and dependencies. While we see clear performance changes from these experiments, some guesses
about why (like resource competition) would need more detailed testing to confirm.

## License

This project is licensed under the Mozilla Public License 2.0 - see the [LICENSE](LICENSE) file for details.
