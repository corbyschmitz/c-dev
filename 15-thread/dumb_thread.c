#include <pthread.h>  //for posix threads
#include <stdio.h>    //for perror()
#include <unistd.h>    //for sleep()

/*    Copyright (C) 2007 Corby Schmitz
*    
*    License removed for readablity
*/

int foo=0;

void* thread_routine1(int* f){
        while (foo<30){
                foo++;
                printf("thread %d %d\n", pthread_self(), foo);
		sleep(1);
        }
}

main(){
        pthread_t tid1;
        pthread_t tid2;
	pthread_t tid3;
        if (pthread_create(&tid1,NULL,thread_routine1, &foo)<0)
                perror("Thread 1 cannot be created");
        if (pthread_create(&tid2,NULL,thread_routine1, &foo)<0)
                perror("Thread 2 cannot be created");
	if (pthread_create(&tid3,NULL,thread_routine1, &foo)<0)
                perror("Thread 3 cannot be created");
        printf("Main thread is done and waiting\n");
        pthread_join(tid1, NULL);
        printf("thread 1 is complete\n");
        pthread_join(tid2, NULL);
        printf("thread2 is complete\n");
 	pthread_join(tid3, NULL);
	printf("thread3 is complete\n");
        printf("main thread is exiting\n");
}

