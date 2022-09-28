#include <stdio.h>

int main(){
    int arr[7] = { 11, 22, 33, 44, 55, 66, 77};

    for (int i = 0; i<7; i++){
        printf("[index %d] Address: %u, Value : %d\n", i, (arr+i), *(arr + i));
    }
    return 0;
}
