#include <stdio.h>

/*    Copyright (C) 2013 Corby Schmitz
* 
*    License removed for readablity
*/

// Function call which takes argument and uses it
void printStmt(char arg[]){
	int blah = 5;
	printf("%d %s\n", blah, arg); //non-static content print statement, numberic and string
}

//Main function call which calls subroutines
void main(){
	printStmt("Hello to the World");
}

