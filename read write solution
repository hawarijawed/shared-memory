#include<stdio.h>
#include<stdlib.h>
struct semaphore mutex,wrt;
int readercount;
struct semaphore{
    int val;
};

void wait (struct semaphore *s)
{
     while(s-> val <=0)
     {
         
     }
    s->val--;
}

void signal(struct semaphore *s)
{
    s->val++;
}

void *reader()
{
    wait(&mutex);
    readercount++;
    if(readercount==1)
    wait(&wrt);
    signal(&mutex);
    printf("\n%d reader is inside",readercount);
    wait(&mutex);
    readercount--;
    if(readercount==0)
    {
        signal(&wrt);
    }
    signal(&mutex);
    printf("\n%d Reader is leaving",readercount+1);
}

void *writer()
{
    printf("\nWriter is trying to enter");
    wait(&wrt);
    printf("\nWriter has entered");
    signal(&wrt);
    printf("\nWriter is leaving");
}

int main()
{
    int n2,i;
    printf("Enter the number of readers:");
    scanf("%d",&n2);
    int pid[n2];
    mutex.val = 1;
    wrt.val = 1;;
    for(i=0;i<n2;i++)
    { 
       pid[i] = fork();

       if(pid[i]==0)
       {
            reader();
       }
       else
            writer();
          
    }
    printf("\n");

}
