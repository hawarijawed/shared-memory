#include<stdio.h>
#include<unistd.h>

void main()
{
  int pid;
  pid = fork();
  if(pid == 0)
  {
    printf("\nChild prints pid = %d\n",pid);
    printf("My process id      = %d\n",getpid());
    printf("My parent process id      = %d\n",getppid());
  }
  else if(pid>0)
  {
    printf("\nParent prints pid = %d\n",pid);
    printf("My process id 	= %d\n",getpid());
    printf("My parent process id      = %d\n",getppid());
   }
  else
    printf("error\n");
 }
