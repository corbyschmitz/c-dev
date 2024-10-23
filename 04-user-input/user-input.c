#include <stdio.h>

printStmt(char arg[]){
	arg[strlen(arg)-1]='\0';
	printf("Hello %s\n", arg);
}
main(){
	int MAX_SIZE = 15;
	char inputString[MAX_SIZE];
	char more[20];
	printf("Enter your name\n");
	fgets(inputString, MAX_SIZE, stdin);
	printf("Please enter your name again\n");
	fgets(more, 20, stdin);
	printStmt(inputString);
	printf("%s\n", more);
}

