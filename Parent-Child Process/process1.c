#include<stdio.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/wait.h>
void primenumber(int n)
{
    int i,count = 0;
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            count++;
        }
    }
    if(count == 2)
    {
        printf("%d is a primenumber\n",n);
    }
}

void main()
{
    int n;
    printf("ENter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for(int i = 0; i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int pid;
    pid = fork();
    
    if(pid == 0) //child process
     {
        for(int i=0;i<n;i++)
        {
            primenumber(arr[i]);
        }
     }
    if(pid > 0) //parent process
    {
        wait(NULL);
        int i,j;
        for (i = 0; i < n- 1; ++i)
        {
      
    // loop to compare array elements
    	for (int j = 0; j < n - i- 1; ++j)
    	 {
      
      // compare two adjacent elements
      // change > to < to sort in descending order
      		if (arr[j] > arr[j + 1]) 
      		{
        
        // swapping occurs if elements
        // are not in the intended order
        	int temp = arr[j];
        	arr[j] = arr[j + 1];
        	arr[j + 1] = temp;
      		}
    	}
       }
        printf("Sorted array\n");
        for(i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}
