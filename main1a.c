// preso da qui: https://dev.to/quantumsheep/basics-of-multithreading-in-c-4pam
// cosi ha compilato e funziona


#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void * wait(void *vargp)
{
      // Store the value argument passed to this thread 
    int *myid = (int *)vargp; 
  
    sleep(2);

    printf("Done.\n");
}

int
main(void)
{
    pthread_t thread;
    int err;

    err = pthread_create(&thread, NULL, wait, (void *)&thread);

    if (err)
    {
        printf("An error occured: %d", err);
        return 1;
    }

    printf("Waiting for the thread to end...\n");

    pthread_join(thread, NULL);

    printf("Thread ended.\n");    

    return 0;
}
