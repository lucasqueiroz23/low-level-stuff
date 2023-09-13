#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigusr1(int signal) {
    printf("Inside sigusr1 handler\n");
    sleep(1);
}

void handle_sigusr2(int signal) {
    printf("Inside sigusr2 handler\n");
    sleep(1);
}

int main(void) {
    pid_t pid = getpid();
    printf("pid = %d\n", pid);

    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);

    while(1) {
       // wait for signal
       printf("Inside main function\n");
       sleep(2);
    }

    exit(0);
}
