// 2개의 정수 배열 a, b를 받아서 대응되는 배열 요소가 같은지를 검사하는 함수 array_equal(int a[], intb[], int size)를 작성하고 테스트하라. 이 함수는 a[0]와 b[0], a[1]과 b[1], ... , a[size-1]와 b[size-1]가 같은지를 검사한다. 만약 전체 요소가 같다면 1을 반환하고 그렇지 않으면 0을 반환한다.
// a와 b의 배열은 각 10으로 제한하였다.

#include <stdio.h>

int array_equal(int a[], int b[], int size);

int main(void){
    int res;
    int a[10] = {0};
    int b[10] = {0};

    printf("a 입력: ");
    for(int i = 0; i<10; i++){
        scanf("%d", &a[i]);
        if(a[i] == 0)
            break;
    }
    printf("b 입력: ");
    for(int i = 0; i<10; i++){
        scanf("%d", &b[i]);
        if(b[i] == 0)
            break;
    }
    printf("출력");
    for (int i = 0; i < 10; i++){
        printf("%d", a[i]);
    }
    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("%d", b[i]);
    }
    printf("\n");

    res = array_equal(a, b, 10);
    if (res == 1) printf("2개의 배열은 같다.\n");
    else printf("2개의 배열은 다르다.\n");

    printf("%d", array_equal(a, b, 10));
}

int array_equal(int a[], int b[], int size){
    int flag = 1;
    for (int i = 0; i < size; i++){
        if(a[i] != b[i]){
            flag = 0;
        break;
        }
    }
    return flag;
}
