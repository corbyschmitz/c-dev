#include <stdio.h>
#define SIZE 50

/*    Copyright (C) 2007 Corby Schmitz
* 
*    License removed for readablity
*/

//Command Line arguments
main(int argc, char *argv[]){
	int i = 0;
	while (i < argc){
		printf("Agument %i:\t%d\n", i, argv[i]);
		i++;
	}
}
