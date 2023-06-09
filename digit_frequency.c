#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int frequency[10] = {0};
    char str[1000];
    scanf("%s", str);
    for(int i=0; str[i]; i++){
        if (str[i] >= '0'  && str[i] <= '9')
         frequency[str[i] - 48 ] ++;
    }
    for (int i = 0; i < 10; i++)
        printf("%d ", frequency[i]);
    return 0; 
}