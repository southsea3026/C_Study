// 질문은 왜 srand()를 사용할 때 unsigned int를 권장하는 것인지에 대해서 입니다.
// int는 음수, 0, 양수를 포함하여 최소 -2,147,483,648에서 최대 2,147,483,647까지 표현한다고 합니다.
// unsigned int는 int의 범위를 양의 정수 범위로만 사용한 자료형이고, 최소 0부터 최대 4,294,967,295까지 표현한다고 합니다.
// rand 함수는 0~RAND_MAX까지 즉 0~32767까지 사이의 값을 반환합니다.
// 이에 seed를 사용하는 srand 함수를 이용하여 srand(time)을 적용합니다.
// rand 함수는 0부터 주어진 최대값까지 랜덤하게 반환함으로 srand((int)time(NULL));을 사용한다면 0 ~ 2,147,483,647까지 표현하게 되어 랜덤한 값의 범위가 unsigned int보다 2배 적습니다.
// 따라서 srand(time)을 사용할 때는 int가 아닌 unsigned int가 권장됩니다.
// 처음에는 질문사항으로 남기려고 했는데 적다보니 왜 unsigned int를 사용하는지 이해가 되네요.

// 아래 코드는 쉽게 풀어쓴 C언어 Express 개정 3판의 460페이지 chapter 10 배열. 프로그래밍 2번 문제에 대한 해결입니다. 아직 코드를 간략히 줄이지는 못했습니다.
// rand() 함수만 쓰면 난수 값이 변하지 않기 때문에 srand(time)을 통해 지속적으로 변하는 난수로 설정하였습니다.

// 문제: 크기가 10인 1차원 배열에 난수를 저장한 후에, 최대값과 최소값을 출력하는 프로그램을 작성하라. 난수는 rand()함수를 호출하여 생성하라.
// 예시 출력: 최대값은 29358
//          최소값은 41

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand((unsigned int)time(NULL));
    int arr[10] = {0};
    for(int i=0; i<10; i++){
        arr[i] = rand();
        printf("%d = %d\n", i, arr[i]);
    }
    int hig = arr[0], low = arr[0];

    for(int i=0; i<10; i++){
        if(arr[i]>hig)    hig = arr[i];
        if(arr[i]<low)    low = arr[i];
    }
    printf("\n%d\n", hig);
    printf("\n%d\n", low);
}
