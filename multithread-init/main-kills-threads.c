#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdlib.h>

void *trash(void *args){
	while(1) printf("hello world\n");
}
void *foo(void *args) {
	while(1) printf("I'm another thread...\n");
}
int main(){
	pthread_t thread_id, tid2;
	sleep(1);
	printf("I'm the main thread");
	sleep(1);
	pthread_create(&thread_id, NULL, &trash, NULL);
	pthread_create(&tid2, NULL, &foo, NULL);
	sleep(1);
	exit(0);
}
