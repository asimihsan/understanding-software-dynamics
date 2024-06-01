#ifndef INSTRUMENTATION_H
#define INSTRUMENTATION_H

#ifdef __cplusplus
extern "C" {
#endif

int start_instrumentation();
void stop_instrumentation();
void print_instrumentation_report();

#ifdef __cplusplus
}
#endif

#endif // INSTRUMENTATION_H
