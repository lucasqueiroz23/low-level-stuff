#include <stdlib.h>
#include <stdio.h>

void callback(int i){
	callback(i + 1);
}

int main(){
	callback(1);
	exit(0);
}
