#include<stdio.h>
#include<stdlib.h>
int readcount;

struct semaphore{
    int val;
}mutex,wrt;

void wait(struct semaphore *s)
{
    /* data */
    s->val--;
}

void signal(struct semaphore *s)
{
    s->val++;
}

void *writer()
{
    printf("Writer request to enter\n");
    wait(&wrt);

    printf("Writer is in critical section\n");

    signal(&wrt);
    printf("Writed exit the critical section");
}

void *reader()
{
    printf("Reader requesting to enter\n");

    wait(&mutex);

    readcount++;

    if(readcount==1)
    {
        //NO writers are allowed to execute
        wait(&wrt);
    }
    //writers can enter to read data
    signal(&mutex);
    printf("%d reader is reading\n",readcount);

    wait(&mutex);

    readcount--;

    if(readcount==0)
    {
        signal(&wrt);
    }
    signal(&mutex);

    printf("%d reader is leaving\n",readcount+1);

}

int main()
{
    int n,i;
    printf("Enter number of reader :");
    scanf("%d",&n);
    int pid[n];
    mutex.val = 1;
    wrt.val = 1;
    for(i=0;i<n;i++)
    {
        pid[i] = fork();

        if(pid[i] == 0)
        {
            reader();
        }
        else if(pid[i] > 0)
        {
            //sleep(1);
            writer();
        }
        else
        {
            printf("Error\n");
            exit(1);
        }
    }
    printf("\n");
}