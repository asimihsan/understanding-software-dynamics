// SPDX-License-Identifier: MPL-2.0
//
// Copyright © 2024 Asim Ihsan
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef INSTRUMENTATION_H
#define INSTRUMENTATION_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    double elapsed_ns;
    uint64_t instructions;
    uint64_t cycles;
    uint64_t branches;
    uint64_t branch_misses;
    double ipc;
    double branch_miss_rate;
    double branch_hit_rate;
    double instructions_per_branch_miss;
    double instructions_per_branch_hit;
} instrumentation_result;

int start_instrumentation();

void stop_instrumentation();

instrumentation_result get_instrumentation_result();

void print_instrumentation_report();

#ifdef __cplusplus
}
#endif

#endif // INSTRUMENTATION_H
