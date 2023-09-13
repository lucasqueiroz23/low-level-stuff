/**
 * For an array(data) of 1200 integers, result[i] = data[i] * 4 + 20.
 * We should make the calculations using 3 threads, then print it on 
 * the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

#define SIZE 1200
#define MAXVALUE 20000

int* data;
int* result;

// tip: pass arguments as a struct
struct args {
    int lower;
    int upper;
};

void* calculate(void* args) {
    struct args* params = (struct args*) args;
    for(int i = params->lower; i < params->upper; i++) {
        result[i] = data[i] * 4 + 20;
    }
    return NULL;
}

void check_values() {
    for(int i = 0; i < SIZE; i++) {
        printf("data[i] = %d\nresult[i] = %d\n\n", data[i], result[i]);
    }
}

int main() {
    result = malloc(SIZE * sizeof(int));
    data = malloc(SIZE * sizeof(int));

    for(int i = 0; i < SIZE; i++) {
        data[i] = random() % MAXVALUE;
        result[i] = 0;
    }

    // set threads and arguments
    pthread_t threads[2];
    struct args arguments[2];

    arguments[0].lower = 0;
    arguments[0].upper = 400;

    arguments[1].lower = 400;
    arguments[1].upper = 800;

    pthread_create(&threads[0], NULL, &calculate, &arguments[0]);
    pthread_create(&threads[1], NULL, &calculate, &arguments[1]);

    struct args main_args;
    main_args.lower = 800;
    main_args.upper = SIZE;

    calculate(&main_args);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    check_values();

    free(result);
    free(data);
    exit(0);
}
