#include <stdint.h>
#include <stdio.h>
#include <time.h>

#ifdef __x86_64__
#include <x86intrin.h>
#elif defined(__aarch64__)

#include <sys/time.h>

#include <sys/time.h>
#else
#error "Unsupported architecture"
#endif

static const int kIterations = 1000 * 1000000;

static inline uint64_t read_tsc(void) {
#ifdef __x86_64__
    return __rdtsc();
#elif defined(__aarch64__)
    uint64_t ticks;
    asm volatile("mrs %0, PMCCNTR_EL0" : "=r" (ticks));
    return ticks;
#endif
}

int main(int argc, const char **argv) {
    uint64_t startcy, stopcy;
    uint64_t sum = 0;

    startcy = read_tsc();                       // starting cycle count

    for (int i = 0; i < kIterations; ++i) {   // loop kIterations times
        sum += 1;                               // the add we want to measure
    }

    stopcy = read_tsc();                       // ending cycle count

    int64_t elapsed = stopcy - startcy;
    double felapsed = elapsed;
    fprintf(stdout, "%d iterations, %lu cycles, %4.2f cycles/iteration\n",
            kIterations, elapsed, felapsed / kIterations);
    return 0;
}
