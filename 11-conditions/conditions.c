#include <stdio.h>

/*    Copyright (C) 2007 Corby Schmitz
* 
*    License removed for readablity
*/

main(int argc, char* argv[]){
	int input = atoi(argv[1]);
	if (input == 1){
		printf("Chose 1\n");
	}else if(input == 2){
		printf("Chose 2\n");
	}else if(input == 3){
		printf("Chose 3\n");
	}else{
		printf("Invalid Choice\n");
	}
	switch(input){
		case 0:
			printf("None\n");
			break;
		case 1:
			printf("One\n");
			break;
		case 2:
			printf("Two\n");
			break;
		case 3:
		case 4:
		case 5:
			printf("Several\n");
			break;
		default:
			printf("Many\n");
			break;
	}
}
