#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#define size 32

void main()
{

    char str[20];
    
    int shmid 
    key_t key;
    char *shm, *s;
    key = 5678;
    
    if((shmid = shmget(key,size,IPC_CREAT|0666))<0)
    {
        printf("Error\n");
        exit(1);
    }
    if((shm = shmat(shmid,NULL,0)) == (char*)(-1))
    {
        printf("Error\n");
        exit(1);
    }

    s = shm;
    int i;
    printf("Enter string here: ");
    gets(str);
    for(i=0;str[i];i++)
    {
        *s++ = s[i];
        *s = NULL;
    }
    int count;
}