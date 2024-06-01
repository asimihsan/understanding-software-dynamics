#ifndef INSTRUMENTATION_H
#define INSTRUMENTATION_H

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
