#include "performancecounters/instrumentation.h"
#include "performancecounters/event_counter.h"

#include <iostream>
#include <chrono>

event_collector collector;
event_count result;

extern "C" int start_instrumentation() {
    if (!collector.has_events()) {
        std::cerr
                << "I cannot access the performance counters. Make sure you run the program in privileged mode (e.g., sudo) under Linux or macOS/ARM."
                << std::endl;
        return EXIT_FAILURE;
    }

    collector.start();

    return EXIT_SUCCESS;
}

extern "C" void stop_instrumentation() {
    result = collector.end();
}

extern "C" void print_instrumentation_report() {
    printf("Elapsed time (ns): %f\n", result.elapsed_ns());
    printf("Instructions: %lu\n", result.instructions());
    printf("Cycles: %lu\n", result.cycles());
    printf("Branches: %lu\n", result.branches());
    printf("Branch misses: %lu\n", result.branch_misses());
//    printf("Cycles per loop: %f\n", cycles_per_iteration);
//    printf("Cycles per add: %f\n", cycles_per_iteration / 4.0);
    printf("IPC: %f\n", result.instructions() / (double) result.cycles());
    printf("Branch prediction miss rate: %f\n",
           result.branch_misses() / (double) result.branches());
    printf("Branch prediction hit rate: %f\n",
           1.0 - result.branch_misses() / (double) result.branches());
    printf("Instructions per branch miss: %f\n",
           result.instructions() / (double) result.branch_misses());
    printf("Instructions per branch hit: %f\n",
           result.instructions() / (double) (result.branches() - result.branch_misses()));
}
