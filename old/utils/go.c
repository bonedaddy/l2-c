#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct go_goroutine_future *go_goroutine_fut(
    pthread_t *thread, 
    pthread_attr_t *attr,
    void *arg, 
    struct go_goroutine_future *fut
);

typedef struct go_thread_data {
    int tid;
    double stuff;
} go_data;

void *go_process_func(void *arg) {
    go_data *data = (go_data *)arg;
    printf("hello from go_process_func, thread id: %d\n", data->tid);
    pthread_exit(NULL);
}

int go_goroutine(
    pthread_t *thread, 
    pthread_attr_t *attr,
    void *arg
) {
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
    bool ready, fired;
    pthread_mutex_t mutex;
}  go_goroutine_future;


struct go_goroutine_future *fire_go_goroutine_fut(
    pthread_t *thread, 
    pthread_attr_t *attr,
    void *arg, 
    void *(execute_func)(void *),
    struct go_goroutine_future *fut
) {
    int response = pthread_create(thread, attr, execute_func, arg);
    pthread_mutex_lock(&fut->mutex);
    fut->exitCode = response;
    fut->returnValue = (char*)&response;
    fut->fired = true;
    pthread_mutex_unlock(&fut->mutex);
    return fut;
}


struct go_goroutine_future *new_go_goroutine_future() {
    char *returnValue = malloc(sizeof(char));
    int exitCode;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    exitCode = 1;
    struct go_goroutine_future *fut = malloc(sizeof(go_goroutine_future));
    (*fut).returnValue = returnValue;
    (*fut).exitCode = exitCode;
    (*fut).mutex = mutex;
    (*fut).ready = true;
    return fut;
}

int main() {
    struct go_goroutine_future *gr1 = new_go_goroutine_future();
    struct go_goroutine_future *gr2 = new_go_goroutine_future();
    struct go_goroutine_future futures[2] = {gr1, gr2};
    pthread_t threads[2];
    go_data threads_data[2];
    for (int i = 0; i < 2; ++i) {
        threads_data[i].tid = i;
        fire_go_goroutine_fut(
            &threads[i],
            NULL,
            &threads_data[i],
            go_process_func,
            gr1
        );
    }
    for (int i = 0; i < 2; ++i) {
        pthread_join(threads[i], NULL);
    }
    printf("exit code: %d\n", (*gr1).exitCode);
    printf("fired: %d\n", (*gr1).fired);
    return 0;   
}


/*
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
}*/