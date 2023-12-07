#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#define size 32
void main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;
    key=5678;;
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
    int alpha = 0;
    int digit = 0;
   for(s=shm;*s!=NULL;s++)
   {
        if((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))
        {
            alpha++;
        }

        if(*s>=48 && *s<=57)
        {
            digit++;
        }

        

   }
    *s++ = digit;
    *s++ = alpha;
    *shm='*';
//    printf("No. of digits: %d\n",digit);
//    printf("No. of alphabets: %d\n",alpha);
   exit(0);

}

