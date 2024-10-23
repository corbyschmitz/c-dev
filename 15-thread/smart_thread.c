#include <pthread.h>  //for posix threads
#include <stdio.h>    //for perror()
#include <unistd.h>    //for sleep()
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

/*    Copyright (C) 2007 Corby Schmitz
*    
*    License removed for readablity
*/

int foo=0;
const int SEM_MODE = 0600;      // only processes of same user have access to semaphores

void update_foo();

//declare semaphore
int mutexid;

/*
 * do a "P" or "down" operation on the given semaphore
 */

void down(int semid){
    // initialize values

    struct sembuf op;
    op.sem_num =  0;         // member number (we only have number 0)
    op.sem_op  = -1;         // dec by one
    op.sem_flg =  0;         // no flags

    if( semop(semid, &op, 1) == -1)
        printf("semop error");
}

void up(int semid){
    // initialize values

    struct sembuf op;
    op.sem_num = 0;         // member number (we only have number 0)
    op.sem_op  = 1;         // inc by one
    op.sem_flg = 0;         // no flags

    if( semop(semid, &op, 1) == -1)
        printf("semop error");
}
union semunion {
        int val;
        struct semid_ds *buf;
        ushort *array;
} initial_value;
void* thread_routine1(int* f){
        while (foo<100){
                update_foo();
        }
}
void update_foo(){
        down(mutexid);
        printf("thread %d %d\n", pthread_self(), foo);
        foo++;
        up(mutexid);
	sleep(1);
}

main(){
        //declare variables;
        int nop=0;
        //declare threads
        pthread_t tid1;
        pthread_t tid2;

        //allocate semaphore
        mutexid = semget(IPC_PRIVATE, 1, SEM_MODE);
        if( (mutexid == -1))
                printf("segment error");

        //initialize semaphore
        initial_value.val = 1;
        if( semctl(mutexid, 0, SETVAL, initial_value) == -1)
                printf("semctl error");

        //initialize threads
        if (pthread_create(&tid1,NULL,thread_routine1, &foo)<0){
                perror("Thread 1 cannot be created");
		//sleep(1);
	}
        if (pthread_create(&tid2,NULL,thread_routine1, &foo)<0)
                perror("Thread 2 cannot be created");

        // start threads
        printf("Main thread is done and waiting\n");
        pthread_join(tid1, NULL);
        printf("thread 1 is complete\n");
        pthread_join(tid2, NULL);
        printf("thread2 is complete\n");
        printf("main thread is exiting\n");

        //destroy semaphore
        // destroy
        if(semctl(mutexid, 0, IPC_RMID, nop) == -1)
                printf("semctl error");
}
