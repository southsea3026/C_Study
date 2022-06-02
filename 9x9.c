#include <stdio.h>
int x;
int main(){
    for (int i = 1; i <= 9; i++){
        for (int a = 1; a <= 9; a++){
            x = i * a;
            printf("%d\n", x);
        }
        printf("\n");
    }
    return 0;
}
