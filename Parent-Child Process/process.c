#include<stdio.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<unistd.h>
void main()
{
  int pid;
  pid = fork();
  if(pid == 0)
  {
  	printf("PID = %d\n",pid);
  	printf("GETPID = %d\n",getpid());
  	printf("GETPPID = %d\n",getppid());
  }
  else if(pid > 0)
  {     
        
        wait(NULL);
        printf("Parent process running...\n");
        printf("PID = %d\n",pid);
  	printf("GETID = %d\n",getpid());
  	printf("GETPPID = %d\n",getppid());
   }
   else
      printf("\nError\n");
}
