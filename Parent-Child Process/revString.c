#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<string.h>

void main()
{
    char str[10];
    int pid1,pid2;
    pid1 = fork();
    

    // Child1 process....
    if(pid1 == 0)
    {
        printf("\nChild process 1 is running...\n");
        execlp("/home/jawedhawari/Documents/vowels","vowels",NULL);
        
        
    }
    else if(pid1 > 0)
    {
        
        wait(NULL);
        //exit(0);

        printf("Parent process is running...\n");
        
        printf("Statements executed successfully\n");
    }
    else
    printf("\nError\n");

    // child2 process.......................
    pid2 = fork();
    if(pid2 == 0)
    {
        //wait(NULL);
        printf("\nChild process 2 is running...\n");
        execlp("/home/jawedhawari/Documents/reverse","reverse",NULL);
        
    }
    else if( pid2 > 0)
    {
        wait(NULL);
        printf("Parent process is running...\n");
        
        printf("Statements executed successfully\n");
    }
    else
    printf("\nError\n");

}
