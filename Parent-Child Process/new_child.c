#include<stdio.h>
void main()
{
  int pid;
  int n,i;
  printf("Enter the number: ");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  { 
    if(n%i == 0)
    {
      printf("\n%d is a factor of %d\n",i,n);
    }
   }
  
}
