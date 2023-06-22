#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3][3],b[3][3],add[3][3],i,j;
    for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
        {
            printf("Enter a%d%d: ", i + 1, j + 1);
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
        {
            printf("Enter b%d%d: ", i + 1, j + 1);
            scanf("%d",&b[i][j]);
        }
    }
    
    for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
        {
            add[i][j]= a[i][j] + b[i][j];
        }
    }
    
     for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
        {
            printf("add %d%d :%d", i+1,j+1, add[i][j]);
            printf("\n");
        }
    }


    return 0;

}
