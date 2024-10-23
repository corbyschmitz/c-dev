#include <stdio.h>
#include <stdlib.h>

#define CHUNK 100

/*    Copyright (C) 2007 Corby Schmitz
* 
*    License removed for readablity
*/

FILE * source;
FILE * destination;



readFromFile(char *charArray){
	fgets(charArray, CHUNK, source);
}

 

writeToFile(char *charArray){
	fprintf(destination, "%s", charArray);
}

main(){
	char charArray[CHUNK];
	//test source file (die otherwise)
	if ((source = fopen("source.txt", "r")) == NULL){
		exit(1);
	}
	//test destination file (die otherwise)
	if ((destination = fopen("destination.txt", "w")) == NULL){
		fclose(source);
		exit(1);
	}
	readFromFile(&charArray);
	while ( !feof(source) ){
		writeToFile(&charArray);
		readFromFile(&charArray);
	}
	//close files gracefully
	fclose(source);
	fclose(destination);
}
