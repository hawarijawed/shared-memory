#include<stdio.h>
#include<unistd.h>
void main()
{
  int pid;
  int n,fact=1,p;
  printf("Enter the number here: ");
  scanf("%d",&n);
  pid = fork();
  if(pid > 0)
  {
    for(int i = 1; i<=n;i++)
    {
       fact = fact*i;
    }
    printf("\nFactorial of %d = %d\n",n,fact);
  }
  
  else if(pid == 0)
  {
     execlp("~/Documents/new_child.c","new_child.c",NULL);
  }
  else
    printf("\n error\n");
}
  
