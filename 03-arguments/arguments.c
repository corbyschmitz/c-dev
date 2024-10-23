#include <stdio.h>

/*    Copyright (C) 2013 Corby Schmitz
* 
*    License removed for readablity
*/

// Function call which takes argument and uses it
printStmt(char arg[]){
	int blah = 5;
	printf("%d %s\n", blah, arg); //non-static content print statement, numberic and string
}

//Main function call which calls subroutines
main(){
	printStmt("Hello to the World");
}

