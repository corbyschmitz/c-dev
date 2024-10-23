#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#define SHKEY (key_t) 11111L
#define PERMS 0666

/*    Copyright (C) 2007 Corby Schmitz
*    
*    License removed for readablity
*/

main () {
	int temp1,shareid;
	int *array, *parray, *carray;
	pid_t process_id;
	temp1 = shmget ( SHKEY , 100 * sizeof(int ), PERMS | IPC_CREAT);
	if (temp1 == -1) {
   		printf("did not do shared memory get %d",errno);
	}
	array = (int *) shmat (temp1, 0, PERMS);
	if (array == NULL) {
		printf("didn't get access to shared memory");
	}
	array[0]=0;
	process_id=fork();
	if (process_id != 0){
		parray = (int *) shmat (temp1, 0, PERMS);
		while(parray[0]<1000){
			printf("Parent: %i\n",parray[0]++);
			//sleep(1);
		}
		printf("parent complete\n");
		shmdt(parray);
	}else{
		carray = (int *) shmat (temp1, 0, PERMS);
		while(carray[0]<1000){
			printf("Child: %i\n", carray[0]++);
			//sleep(1);
		}
		printf("child complete\n");
		shmdt(carray);
	}
	shmdt (array);
}

