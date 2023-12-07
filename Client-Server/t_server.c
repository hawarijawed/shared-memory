#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#define size 32
void main()
{
     char c;
     int shmid;
     key_t key;
     char *shm, *s;
     int *digit,*alpha;
     key=5678;
     if((shmid=shmget(key,size,IPC_CREAT|0666))<0)
       {
         printf("error1");
         exit(1);
       }
     if((shm =shmat(shmid,NULL,0))==(char *)(-1))
       {
         printf("error 2 \n");
         exit(1);
       }
   int d=0,a = 0;
   for(s=shm;*s!=NULL;s++)
    {
        if((*s>='a' && *s<='z') || *s>='A' && *s<='Z')
        {
           a++;
        }

        if(*s>=48 && *s<=57)
        {
          d++;
        }
    }
    *digit = d;
    *alpha = a;
    *shm='*';

   exit(0);

}

