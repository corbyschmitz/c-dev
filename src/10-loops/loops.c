#include <stdio.h>

/*    Copyright (C) 2007 Corby Schmitz
* 
*    License removed for readablity
*/

main(int argc, char * argv[]){
	if (argc == 0){
		printf("Give me two integer values please");
		exit(0);
	}
	int start = atoi(argv[1]);
	int end = atoi(argv[2]);
	int i = start;
	printf("While Loop\n");
	while (i<=end){
		printf("%d\n", i);
		i++;
	}
	printf("Do-While Loop\n");
	i = start;
	do{
		printf("%d\n", i);
		i++;
	}while (i<=end);
	printf("For Loop\n");
	for (i=start; i<=end; i++){
		printf("%d\n", i);
	}
}
