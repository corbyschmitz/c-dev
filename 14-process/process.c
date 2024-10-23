#include <sys/types.h> //define pid_t
#include <unistd.h>    //define fork()
#include <stdio.h>

/*    Copyright (C) 2007 Corby Schmitz
*    
*    License removed for readablity
*/

main(){
        pid_t process_id;
        process_id=fork();
        if(process_id==0){
		sleep(8);
                printf("I am the child\n");
	}
        else{
		sleep(10);
                printf("I am the parent\n");
		printf("child at ID#%i", process_id);
	}
        printf("I am done\n");

}
