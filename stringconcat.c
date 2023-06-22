#include <stdio.h>
#include <string.h>

int main()
{
    int i=0,j=0;
    char str1[50],str2[50];
    printf("enter the value of str1: ");
    scanf("%s",str1);
    printf("enter the value of str2: ");
    scanf("%s",str2);
    char buffer[100];
     while(str1[i]!='\0')
     {
        buffer[j] = str1[i];
        i++;
        j++;
     }
    i=0;
     while(str2[i]!='\0')
     {
        buffer[j] = str2[i];
        i++;
        j++;
     }
     buffer[j] = '\0';

    printf("the concatenate value of string : %s\n", buffer);
    return 0;

}