// 자기가 생각하는 구조체를 한 개 만들고 설명하기
// 구조체를 사용한 코딩 예시 2개
// 구조체 포인터를 사용한 예시 1개
// 구조체 배열을 사용한 예시 2개

// 총 6개의 구조체 만들기
// 1. 문제제시, 2. 코드, 3. 실행결과 캡처한 화면, 4. 그 외의 것 자유롭게 추가 가능

// 1. 자기가 생각하는 구조체를 한 개 만들고 설명하기
// #include <stdio.h>

// struct report1{ // 구조체 이름
//     char member_variable1[30]; // 멤버 변수 char
//     int member_variable2; // 멤버 변수 int
// } new_report1; // 구조체 별칭

// int main(void){
//     struct report1 name = {"가나다", 10};
//     printf("%s, %d", name.member_variable1, name.member_variable2);
// }
// 구조체는 사용자가 C언어의 기본 타입을 가지고 새롭게 정의할 수 있는 사용자 정의 타입이다.
// 구조체는 기본 타입만으로는 나타낼 수 없는 복잡한 데이터를 표현할 수 있다.
// 배열이 같은 타입의 변수 집합이라면, 구조체는 다양한 타입의 변수 집합을 하나의 타입으로 나타낸 것이다.
// 이때 구조체를 구성하는 변수를 구조체의 멤버(member) 또는 멤버 변수(member variable)라고 한다.
// struct 구조체 이름{
//      멤버 변수 1의 타입 멤버 변수 1의 이름;
//      멤버 변수 2의 타입 멤버 변수 2의 이름;
// } 구조체 변수 이름;
// 위는 구조체를 선언한 것이고 구조체를 사용하기 위해서는 main(void){}안에서 구조체 변수를 선언하여야 한다.

// 2. 구조체를 사용한 코딩 예시 2개
// 2-1)
// #include <stdio.h>

// typedef struct library{
//     char title[30];
//     char author[30];
//     int price;
// } Textbook;

// int main(void){
//     Textbook my_book = {"HTML과 CSS", "홍길동", 28000};
//     Textbook java_book = {.title = "Java Language", .price = 30000};

//     printf(" 첫 번째 책의 제목은 %s이고, 저자는 %s이며, 가격은 %d원입니다.\n", my_book.title, my_book.author, my_book.price);
//     printf(" 두 번째 책의 제목은 %s이고, 저자는 %s이며, 가격은 %d원입니다.\n", java_book.title, java_book.author, java_book.price);
    
//     return 0;
// }


// 2-2)
// #include <stdio.h>
// #include <string.h>

// typedef struct{
//     char name[20];
//     int age;
//     char address[100];
// } Person;       // typedef를 사용하여 구조체 별칭을 Person으로 정의

// int main(){
//     Person p1; // 구조체 별칭 Person으로 변수 선언

//     // 구조체 멤버에 접근하여 값 할당
//     strcpy(p1.name, "김형원");
//     p1.age = 26;
//     strcpy(p1.address, "안양시 만안구 수리산로");

//     // 구조체 멤버에 접근하여 값 출력
//     printf("이름: %s\n", p1.name);
//     printf("나이: %d\n", p1.age);
//     printf("주소: %s\n", p1.address);

//     return 0;
// }


// 3.구조체 포인터를 사용한 예시 1개
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _book{
    char name[20];
    int page;
    char price[100];
} book;

int main(){
    book *p1 = malloc(sizeof(book)); // 구조체 별칭으로 포인터 선언, 메모리 할당
    
    // 화살표 연산자로 구조체 멤버에 접근하여 값 할당
    strcpy(p1->name, "C언어 정복");
    p1->page = 280;
    strcpy(p1->price, "30000원");

    // 화살표 연산자로 구조체 멤버에 접근하여 값 출력
    printf("이름: %s\n", p1->name);
    printf("쪽 수: %d\n", p1->page);
    printf("가격: %s\n", p1->price);

    free(p1);   // 동적 메모리 해제

    return 0;
}


// 4. 구조체 배열을 사용한 예시 2개
// 4-1)



// 4-2)

