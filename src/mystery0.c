#include <stdint.h>
#include <stdio.h>
#include <time.h>

#if defined(__x86_64__) || defined(_M_X64)
#include <x86intrin.h>
#elif defined(__aarch64__)

#include <sys/time.h>

#endif

static const int kIterations = 1000 * 1000000;

int main(int argc, const char **argv) {
    uint64_t startcy = 0, stopcy = 0;
    uint64_t sum = 0;

#if defined(__x86_64__) || defined(_M_X64)
    startcy = __rdtsc();                       // starting cycle count
#elif defined(__aarch64__)
    struct timeval tv;
    gettimeofday(&tv, NULL);
    startcy = tv.tv_sec * 1000000 + tv.tv_usec;
#endif

    for (int i = 0; i < kIterations; ++i) {   // loop kIterations times
        sum += 1;                               // the add we want to measure
    }

#if defined(__x86_64__) || defined(_M_X64)
    stopcy = __rdtsc();                       // ending cycle count
#elif defined(__aarch64__)
    gettimeofday(&tv, NULL);
    stopcy = tv.tv_sec * 1000000 + tv.tv_usec;
#endif

    int64_t elapsed = stopcy - startcy;
    double felapsed = elapsed;
    fprintf(stdout, "%d iterations, %lu cycles, %4.2f cycles/iteration\n",
            kIterations, elapsed, felapsed / kIterations);
    return 0;
}
