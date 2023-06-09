#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void calculate_the_maximum();

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}


  void calculate_the_maximum(int n, int k) {

    int and = 0, or = 0, xor = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if((and < (i&j)) && ((i&j) < k)){
                and = i&j;
            }
            if((or < (i|j)) && ((i|j) < k)){
                or = i|j;
            }
            if((xor < (i^j)) && ((i^j) < k)){
                xor = i^j;
            }
        }
    }
    printf("%d\n%d\n%d", and, or, xor);
}
  



