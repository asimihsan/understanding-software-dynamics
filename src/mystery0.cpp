#include "performancecounters/event_counter.h"

#include <cstdint>
#include <cstdio>
#include <iostream>

static const int kIterations = 1000 * 2000000;

event_collector collector;

int main(int argc, const char **argv) {
    uint64_t sum = 0;

    if (!collector.has_events()) {
        std::cerr
                << "I cannot access the performance counters. Make sure you run the program in privileged mode (e.g., sudo) under Linux or macOS/ARM."
                << std::endl;
        return EXIT_FAILURE;
    }

    collector.start(); // Start collecting performance events

    for (int i = 0; i < kIterations; ++i) {   // loop kIterations times
        sum += 1;                               // the add we want to measure
    }

    event_count result = collector.end(); // End collecting performance events

    // Calculate cycles per iteration
    double cycles_per_iteration = result.cycles() / kIterations;

    // Print the performance results
    printf("Elapsed time (ns): %f\n", result.elapsed_ns());
    printf("Instructions: %lu\n", result.instructions());
    printf("Cycles: %lu\n", result.cycles());
    printf("Branches: %lu\n", result.branches());
    printf("Branch misses: %lu\n", result.branch_misses());
    printf("Cycles per iteration: %f\n", cycles_per_iteration);

    return 0;
}
