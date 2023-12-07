#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<strings.h>
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
         printf("error 1");
         exit(1);
       }
     if((shm=shmat(shmid,NULL,0))==(char *)(-1))
       {
         printf("error 2");
         exit(1);
       }

    s= shm;
    digit = shm;
    alpha = shm;
    char str[20];
    printf("Enter the string here: ");
    gets(str);
    int i;
   for(i = 0;str[i];i++)
    {
        *s++=str[i];
    }
    *s=NULL;
   while(*shm!='*')
    { 
        sleep(1);
    }
  printf("No. of alphabets: %d\n",*alpha);
  printf("No. of digits   : %d\n",*digit);
   exit(0);

}

