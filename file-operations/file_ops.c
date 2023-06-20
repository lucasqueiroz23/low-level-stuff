#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void menu();
void read_file();

void main() {

	printf("Welcome! This program is for simple file handling.\n");
	while(true) 
		menu();

	exit(0);
}

void menu() {
	printf("1 - Read from a file (print its contents)\n");
	printf("2 - Write to a file (overwrite it)\n");
	printf("3 - Append to a file (write something in the end of the file)\n");
	printf("4 - Delete a file\n");
	printf("5 - Exit program\n");
	printf("What do you want to do? ");

	unsigned user_option = 0;
	scanf("%u", &user_option);
	switch(user_option) {
		case 1:
			read_file();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("Enter a valid option!\n\n");
			break;
	}

}

void read_file() {
	char* file_name = malloc(80 * sizeof(char));

	printf("Which file do you want to open? ");
	scanf("%s", file_name);

	FILE* f = fopen(file_name, "r"); 

	if(f == NULL) {
		printf("error: file not found\n");
		return;
	}


	
	printf("\nFILE DATA: \n");
	printf("SIZE: %d\n", 0);
	char c = 0;
	while((c = fgetc(f)) != EOF){
		printf("%c", c);
	}
	printf("\n\n");

	free(file_name);
	fclose(f);

}

