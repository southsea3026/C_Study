#include <stdio.h>

void sub(int *p, int *p2);
void min(int *p, int *p2);
void mul(int *p, int *p2);
void div(int *p, int *p2);

int main(void){
    int i = 10, a = 5;
    int *p, *p2;

    p = &i;
    p2 = &a;
//1번 문제: 포인터 2개를 사용하여, 사칙 연산하는 프로그램을 작성하시오.
    printf("*p = %d, *p2 = %d\n", *p, *p2);
    printf("*p + *p2 = %d\n", *p + *p2);
    printf("*p - *p2 = %d\n", *p - *p2);
    printf("*p * *p2 = %d\n", *p * *p2);
    printf("*p - *p2 = %d\n", *p / *p2);

//2번 문제: 사칙 연산하는 부분을 함수를 사용하여 프로그램으로 작성하시오. 
    printf("\nsum = ");
    sub(&i, &a);

    printf("\nminus = ");
    min(&i, &a);

    printf("\nmultiple = ");
    mul(&i, &a);

    printf("\ndivide = ");
    div(&i, &a);
    
    printf("\n");
    return 0;
}

void sub(int *p, int *p2){
    printf("%d", *p + *p2);
}

void min(int *p, int *p2){
    printf("%d", *p - *p2);
}

void mul(int *p, int *p2){
    printf("%d", *p * *p2);
}

void div(int *p, int *p2){
    printf("%d", *p / *p2);
}
