#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdlib.h>
#define size 32
// Factorial of a number
void main()
{
    key_t key = 3456;
    int *s, *shm;
    int shmid;

    shmid = shmget(key,size,IPC_CREAT|0666);
    if(shmid<0)
    {
        printf("Failed to create id \n");
        exit(1);
    }

    shm = shmat(shmid,NULL,0);
    if(shm == (char*)(-1))
    {
        printf("Failed to create shared memory segment\n");
    }

    for(s=shm;*s!=NULL;s++){
        printf("%d",*s);
    }
    *shm='*';
    exit(0);

}