#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// This program is to get a string and counting the characters in it.
int main(){
    int count=0,i;
    char arr[50];
    printf("Enter the word to count the characters in it:");
    fgets(arr, 50, stdin);
    for(i=0;arr[i]!='\0';i++)// terminate the loop when encountering a null character.
    {
       if(arr[i]!=' ')// for not to count the spaces
       {
         count++;//number of characters
       }
    }
    printf("total count of characters :%d\n",count);
    return 0;
}