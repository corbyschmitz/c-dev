#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

/*    Copyright (C) 2007 Corby Schmitz
* 
*    License removed for readablity
*/

getInput(char prompt[], int bytes, char* inputString){
	printf("%s (maximum of %d characters): ",prompt,bytes);
	fgets(inputString, bytes, stdin);
	inputString[strlen(inputString)-1] = '\0';
}


//Command Line Input
void main(){
	//int SIZE = 50;
	char* userName[SIZE];
	getInput("Enter your full Name", SIZE, userName);
	printf("Hello %s\n", userName);
}
