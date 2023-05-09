#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	if(argc != 2){ 
		printf("Enter valid numbers!\n");
		exit(0);
	}
	int res = atoi(argv[0]) + atoi(argv[1]);
	printf("%s + %s = %d\n", argv[0], argv[1], res);
	exit(0);
}
