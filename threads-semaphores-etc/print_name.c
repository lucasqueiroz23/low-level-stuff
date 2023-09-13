/**
 * Get first and last name and print it with different threads.
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_name(void* args) {
    char* name = (char*) args;
    printf("%s\n", name);

    return NULL;
}

int main(int argc, char** argv) {
    if(argc != 3) {
        printf("Input error!\n");
        printf("Use it like this:\n");
        printf("./print_name <first_name> <second_name>\n");
        exit(1);
    }

    pthread_t threads[2];

    char* first_name = argv[1];
    char* second_name = argv[2];

    pthread_create(&threads[0], NULL, &print_name, first_name);
    pthread_create(&threads[1], NULL, &print_name, second_name);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    exit(0);
}
