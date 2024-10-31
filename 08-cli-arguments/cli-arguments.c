#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

/*    Copyright (C) 2007 Corby Schmitz
* 
*    License removed for readablity
*/

//Command Line arguments
void main(int argc, char *argv[]){
	if (argc < 2) {
                printf("Provide arguments to print\n");
                exit(0);
        }
	int i = 0;
	while (i < argc){
		printf("Agument %i:\t%s\n", i, argv[i]);
		i++;
	}
}
