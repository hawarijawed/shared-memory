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
     key=5678;
     if((shmid=shmget(key,size,IPC_CREAT|0666))<0)
       {
         printf("error 1");
         exit(1);
       }
     if((shm=shmat(shmid,NULL,0))==(char *)(-1))
       {
         printf("error 2");
         exit(1);
       }

    s= shm;
    int i;
    char str[20];
    printf("Enter the string here: ");
    gets(str);
    for(i=0;str[i];i++)
    {
        *s++ = str[i];
    }
    *s = NULL;
  
   while(*shm!='*')
    { 
        sleep(1);
    }
    printf("No. of digits: %d\n",*s++);
   printf("No. of alphabets: %d\n",*s++);
   exit(0);

}


