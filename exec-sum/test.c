#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
	pid_t pid = fork();
	if(pid < 0){
		printf("error\n");
		exit(0);
	}
	if(pid == 0){
	    execlp("./sum", argv[1], argv[2], NULL);	
	}
	if(pid > 0){
		wait(NULL);
	}
	exit(0);
}
