#include<stdio.h>
#include<string.h>
void main()
{
    char str[10],rev[10],j = 0,i;
    printf("Enter your string for process 2: ");
    scanf("%s",str);
    int k = strlen(str);
    for(int i = k-1;i>=0;i--)
    {
        rev[j] = str[i];
        j++;
    }
    printf("Reverse of the string : %s\n",rev);
}
