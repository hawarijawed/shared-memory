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

    s = shm;
    //
    int n;
    printf("Enter the number here: ");
    scanf("%d",&n);
    int fact=1;
    for(int i=0;i<n;i++){
        fact = fact*i;
    }
    *s++ = fact;
    while(*shm!='*'){
        sleep(1);
    }
    exit(0);
    

