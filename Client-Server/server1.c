#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#define size 32

void main()
{
    
    int shmid;
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
    s =shm;
    int digit = 0,alpha = 0;
    for(s = shm; *s!=NULL; s++)
    {
        if((*s>=65 && *s<=90)|| (*s>=97 && *s<=122))
        {
            alpha++;
        }
        if(*s>= 48 && *s<=57)
        {
            digit++;
        }
    }
    printf("No. of alphabets:  %d\n",alpha);
    printf("NO. of digits   :  %d\n",digit);
    *shm = '*';
    exit(0);
}