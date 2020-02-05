#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct go_thread_data {
    int tid;
    double stuff;
} go_data;

void *go_process_func(void *arg) {
    go_data *data = (go_data *)arg;
    printf("hello from go_process_func, thread id: %d\n", data->tid);
    pthread_exit(NULL);
}

int go_goroutine(pthread_t *thread, pthread_attr_t *attr, void *arg) {
    return pthread_create(thread, attr, go_process_func, arg);
}


/*
if we do not define like this and instead do
typedef struct{
    char *returnValue;
    int exitCode;
    pthread_mutex_t mutex;
}  go_goroutine_future;

we will get an incomplete type error
*/
typedef struct go_goroutine_future{
    char *returnValue;
    int exitCode;
    pthread_mutex_t mutex;
}  go_goroutine_future;


struct go_goroutine_future *new_go_goroutine_future() {
    char *returnValue;
    int exitCode;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    exitCode = 1;
    struct go_goroutine_future *fut = malloc(sizeof(go_goroutine_future));
    (*fut).returnValue = *returnValue;
    (*fut).exitCode = exitCode;
    (*fut).mutex = mutex;
    return fut;
}


int main(int argCount, char *args[]) {
    new_go_goroutine_future();
    pthread_t threads[2];
    int i, rc;
    go_data threads_data[2];

    // create our threads
    for (i = 0; i < 2; ++i) {
        threads_data[i].tid = i;
        if (
            (rc = go_goroutine(
                &threads[i], // thread to execute
                NULL, // no attributes
                &threads_data[i] // data for the thread
            ))
        ) {
            fprintf(stderr, "error: pthread, rc: %d\n", rc);
            return EXIT_FAILURE;
        }
    }
    // wait for completion
    for (i = 0; i < 2; ++i) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}