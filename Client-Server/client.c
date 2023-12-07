#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<stdlib.h>
#define size 32

void main()
{ 
  char c;
  int shmid;
  key_t key;
  char *shm,*s;
  key = 5678;
  if(shmid = shmget(key,size,IPC_CREAT|0666)<0)
  {
    printf("\n error----\n");
    exit(1);
  }
  
  if(shm = shmat(shmid,NULL,0) == (char*)(-1))
  {
    printf("\nError+++++\n");
    exit(1);
  }
  
  s = shm;
  for(c='a';c<='z';c++)
  { 
     *s++ = c;
     *s = NULL;
  }
  while(*shm != '*')
  {
       sleep(1);
  }
  exit(0);
  }
     
