#include <stdio.h>
#ifdef __x86_64__
#define ARCH "x86_64"
#elif defined(__aarch64__)
#define ARCH "aarch64"
#else
#define ARCH "unknown"
#endif

int main() {
    printf("Running on %s architecture\n", ARCH);
    return 0;
}
#include <stdio.h>
#ifdef __x86_64__
#define ARCH "x86_64"
#elif defined(__aarch64__)
#define ARCH "aarch64"
#else
#define ARCH "unknown"
#endif

int main() {
    printf("Running on %s architecture\n", ARCH);
    return 0;
}
