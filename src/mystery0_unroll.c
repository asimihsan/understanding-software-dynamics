// SPDX-License-Identifier: MPL-2.0
//
// Copyright © 2024 Asim Ihsan
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "instrumentation/instrumentation.h"

#include <stdint.h>
#include <printf.h>

static const int kIterations = 1000 * 2000000;

int main(int argc, const char **argv) {
    uint64_t sum = 0;

    int rc = start_instrumentation();
    if (rc != 0) {
        return rc;
    }

    for (int i = 0; i < kIterations; i += 4) {   // loop kIterations times
        sum += 1;                               // the add we want to measure
        sum += 1;                               // the add we want to measure
        sum += 1;                               // the add we want to measure
        sum += 1;                               // the add we want to measure
    }

    stop_instrumentation();
    instrumentation_result res = get_instrumentation_result();
    printf("Cycles per iteration: %f\n\n", res.cycles / ((double) kIterations * 4));
    print_instrumentation_report();

    return 0;
}
