#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int x = 10;
	int *ptr = &x;
	printf("ptr originally has %p\n", ptr);
	printf("ptr original value is %d\n", *ptr);
	printf("Its memory address is %p\n\n", &ptr);
	pid_t pid = fork();
	if(pid == 0) { 
		*ptr++;
		printf("In the child process, ptr has %p\n", ptr);
		printf("Its memory address is %p\n", &ptr);
		printf("Its value is %d\n\n", *ptr);
	}
	else {  
		*ptr++;
		printf("In the parent process, ptr has %p\n", ptr);
		printf("Its memory address is %p\n", &ptr);
		printf("Its value is %d\n\n", *ptr);
	}
	exit(0);
}
