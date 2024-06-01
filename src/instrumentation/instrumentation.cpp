// SPDX-License-Identifier: MPL-2.0
//
// Copyright © 2024 Asim Ihsan
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "instrumentation/instrumentation.h"
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

extern "C" instrumentation_result get_instrumentation_result() {
    instrumentation_result res;
    res.elapsed_ns = result.elapsed_ns();
    res.instructions = result.instructions();
    res.cycles = result.cycles();
    res.branches = result.branches();
    res.branch_misses = result.branch_misses();
    res.ipc = result.instructions() / (double) result.cycles();
    res.branch_miss_rate = result.branch_misses() / (double) result.branches();
    res.branch_hit_rate = 1.0 - result.branch_misses() / (double) result.branches();
    res.instructions_per_branch_miss = result.instructions() / (double) result.branch_misses();
    res.instructions_per_branch_hit = result.instructions() / (double) (result.branches() -
                                                                        result.branch_misses());
    return res;
}

extern "C" void print_instrumentation_report() {
    printf("Elapsed time (ns): %f\n", result.elapsed_ns());
    printf("Instructions: %lld\n", result.instructions());
    printf("Cycles: %lld\n", result.cycles());
    printf("Branches: %lld\n", result.branches());
    printf("Branch misses: %lld\n", result.branch_misses());
    printf("IPC: %.2f\n", result.instructions() / (double) result.cycles());
    printf("Branch prediction miss rate: %.2f\n",
           result.branch_misses() / (double) result.branches());
    printf("Branch prediction hit rate: %.2f\n",
           1.0 - result.branch_misses() / (double) result.branches());
    printf("Instructions per branch miss: %.2f\n",
           result.instructions() / (double) result.branch_misses());
    printf("Instructions per branch hit: %.2f\n",
           result.instructions() / (double) (result.branches() - result.branch_misses()));
}
