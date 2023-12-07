#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/wait.h>
void  main()
{
    int n;
    
    int pid = fork();
    if(pid == 0)
    {
   	printf("CHild process\n");
       printf("PID    = %d\n",pid);
       printf("getpID = %d\n",getpid());
       printf("PPID   = %d\n",getppid());
    }
    else if(pid > 0)
    {
    	wait(NULL);
        printf("Parent process\n");
       printf("PID    = %d\n",pid);
       printf("getpID = %d\n",getpid());
       printf("PPID   = %d\n",getppid());
        
    }
    else
    {
        printf("\nError\n");
    }
}
