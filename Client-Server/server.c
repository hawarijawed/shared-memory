#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<sys/types.h>
#define size 32

void main()
{ 
  char c;
  int shmid;
  key_t key;
  char *shm,*s;
  key = 5678;
  if((shmid = shmget(key,size,IPC_CREAT|0666))<0)
  {
    printf("\n ----error\n");
    exit(1);
  }
  
  if(shm = shmat(shmid,NULL,0) == (char*)(-1))
  {
    printf("\n+++Error\n");
    exit(1);
  }
  
  s = shm;
  for(s=shm;*s != NULL;s++)
  {
    putchar(*s);
    printf("\n");
  }
  *shm = '*';
  exit(0);
  
 }
