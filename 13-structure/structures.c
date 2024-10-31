#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LLIMIT 20
#define SLIMIT 5

/*    Copyright (C) 2007 Corby Schmitz
* 
*    License removed for readablity
*/

typedef struct{
	char salutation[SLIMIT];;
	char first[LLIMIT];
	char middle[LLIMIT];
	char last[LLIMIT];
	char suffix[SLIMIT];
} myName;

void getInput(char prompt[], int bytes, char* inputString){
	printf("%s (maximum of %d characters): ",prompt,bytes);
	fgets(inputString, bytes, stdin);
	inputString[strlen(inputString)-1] = '\0';
}


void main(){
	myName me;
	getInput("Enter your preferred salutation", SLIMIT, me.salutation);
	getInput("Enter your first name", LLIMIT, me.first);
	getInput("Enter your middle name", LLIMIT, me.middle);
	getInput("Enter your last name", LLIMIT, me.last);
	getInput("Enter your suffix (if any)", LLIMIT, me.suffix);
	printf("%s %s %s %s %s\n", me.salutation, me.first, me.middle, me.last, me.suffix);
}
