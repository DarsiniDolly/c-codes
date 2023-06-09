#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	printf("the value : %d \n",n);
    for(int i=0;i<n;i++)
      {
          for(int j=1;j<i+1;j++)
          printf("%d ",n-j+1);
          for(int k=1;k<=2*(n-i)-1;k++)
          printf("%d ",n-i);
          for(int j=0;j<i;j++)
          printf("%d ",n-i+1+j);
          printf("\n");
      }
   for(int i=0;i<n-1;i++)
      {
          for(int j=0;j<n-2-i;j++)
          printf("%d ",n-j);
          for(int k=1;k<=2*(i+1)+1;k++)
          printf("%d ",2+i);
          for(int j=3+i;j<=n;j++)
          printf("%d ",j);
          printf("\n");
      }
   
   
    return 0;
}


