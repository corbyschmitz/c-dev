#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

/*    Copyright (C) 2007 Corby Schmitz
*    
*    License removed for readablity
*/

const int N = 10;               //empty buffer slots at the beginning

const int produceitems = 100;   //how much items to produce altogether

const int SEM_MODE = 0600;      //only processes of same user have access to semaphores


/*
 * do a "P" or "down" operation on the given semaphore
 */

void down(int semid){
    // initialize values

    struct sembuf op;
    op.sem_num =  0;         // member number (we only have number 0)
    op.sem_op  = -1;         // decrement by one
    op.sem_flg =  0;         // no flags for this case

    if( semop(semid, &op, 1) == -1)
        printf("semop error");
}


/*
 * do a "V" or "UP" operation on the given semaphore
 */

void up(int semid){
    // initialize values

    struct sembuf op;
    op.sem_num = 0;         // member number (we only have number 0)
    op.sem_op  = 1;         // increment by one
    op.sem_flg = 0;         // no flags for this case

    if( semop(semid, &op, 1) == -1)
        printf("semop error");
}


union semunion {
	int val;
	struct semid_ds *buf;
	ushort *array;
} initial_value;

int main(){
    // semaphore declaration
	int mutexid;    // controls access to critical region   
	int emptyid;    // counts empty buffer slots
	int fullid;     // counts full buffer slots

	//other declarations
	pid_t child;
	int i;
	int nop=0;

    // create semaphores

    	mutexid = semget(IPC_PRIVATE, 1, SEM_MODE);
    	emptyid = semget(IPC_PRIVATE, 1, SEM_MODE);
    	fullid  = semget(IPC_PRIVATE, 1, SEM_MODE);

    	if( (mutexid == -1) || (emptyid == -1) || (fullid == -1))
        	printf("semget error");

    // initialise semaphores:
    // mutex = 1
    // empty = N
    // full = 0

    // mutexid

    	initial_value.val = 1;
    	if( semctl(mutexid, 0, SETVAL, initial_value) == -1)
        	printf("semctl error");


    // emptyid

    	initial_value.val = N;
    	if( semctl(emptyid, 0, SETVAL, initial_value) == -1)
        	printf("semctl error");

    // fullid

    	initial_value.val = 0;
    	if( semctl(fullid, 0, SETVAL, initial_value) == -1)
        	printf("semctl error");


    // use two processes for producer and consumer

    //  pid_t child;

    	if( (child = fork() ) < 0)
        	printf("fork error");
    
    	if(child){
          // child acts as producer
    
        	for(i=1; i <= produceitems; i++){
            	  // object item

            	  // produce new item
            	  // produce(&item)       
            		printf("producer: item %d\n",i);
    
            	  // decrement empty count
            		down(emptyid);
            
            	  //  enter critical region
            		down(mutexid);

            	  // put item into buffer         
            	  // enter(item)
            		printf("producer: item %d put into buffer\n",i); 

            	  // leave critical region            
            		up(mutexid);

            	  // increment count of full slots
            		up(fullid);
        	}       
    	}
    	else{
          // parent acts as consumer

          // expect produceitems to be generated

        	for(i=1; i <= produceitems; i++){
            	  // decrement full count
            		down(fullid);
            
            	  //  enter critical region
            		down(mutexid);

            	  // remove item from buffer
            		printf("consumer: item %d removed from buffer\n",i); 

            	  // leave critical region            
            		up(mutexid);

            	  // increment count of empty slots
            		up(emptyid);

            	  // do something with the item
            	  // consume(item)
            		printf("consumer: item %d consumed\n",i);
        	}       

	  // destroy semaphores after last access to semaphores

        	if(semctl(mutexid, 0, IPC_RMID, nop) == -1)
            		printf("semctl error");

        	if(semctl(fullid, 0, IPC_RMID, nop) == -1)
            		printf("semctl error");

        	if(semctl(emptyid, 0, IPC_RMID, nop) == -1)
            		printf("semctl error");
    	}

    return(EXIT_SUCCESS);
}


