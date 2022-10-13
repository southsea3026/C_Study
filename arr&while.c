#include <stdio.h>

int main(){
    int days[] = {31, 29, 31, 30, 31, 30, 31, 31 ,30 ,31, 30, 31};
    int i=1;

    while(i != 0){
        printf("\n0을 입력하면 반복이 중단됩니다.\n");
        printf("월별 최대 일 수\n");
        printf("1 ~ 12 사이 정수 입력: ");
        scanf("%d", &i);
        if(i >12){
            printf("다시 입력하세요.\n");
        }
        else if(i <= 12){
        printf("%d월은 %d일까지 있습니다.\n", i, days[i]);
        }
        printf("\n");
    }
    return 0;
}
