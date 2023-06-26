#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// this program is to count the number of words in the given string
int main()
{
    int i,count=0;
    char arr[50];
    printf("Enter the string to count the words:");
    fgets(arr, 50, stdin);
    for(i=0;arr[i]!='\0';i++)// terminate the loop when it encounters the null character
    {
       if(arr[i]==' '||arr[i]=='\0'||arr[i]=='\n')// count the spaces
       {
         count++;
       }
    }
    printf("total no of words in the given string:%d\n",count);
    return 0;
}
