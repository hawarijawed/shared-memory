#include<stdio.h>
#include<string.h>
// ASCII value for A to Z ranges from 65 to 90
// ASCII value for a to z ranges from 97 to 122
/// ASCII value for 0 to 9 ranges from 48 to 57
void main()
{
    int i,alpha = 0, digit = 0;
    char str[30];
    printf("Enter string here: ");
    gets(str);

    for(i=0;str[i];i++)
    {
        if((str[i]>=65 && str[i]<= 90) || (str[i]>=97 && str[i]<= 122))
        {
            alpha++;
        }

        if(str[i]>= 48 && str[i]<=57)
        {
            digit++;
        }
    }

    printf("No. of alphabets:  %d\n",alpha);
    printf("NO. of digits   :  %d\n",digit);


}