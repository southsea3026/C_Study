#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#define _CRT_SECURE_NO_WARINGS
#include <stdlib.h>
#include <math.h>
#define SIZE 100
/*드라마 프로그램 만들기(드라마 제목 감독 시청률 방송사) title viewer_ratings coach broadcastiong_company*/

int id = 1, score, a, finish = 0; //
int rank[5][3];
time_t start, end;

void print_maze(int pan[10][10]) {
   system("cls");
   for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
         printf("%d ", pan[i][j]);
      }
      printf("\n");
   }
   printf("점수 : %d", score);
}

void clear() {
   system("cls");
   printf("%s", "축하합니다! 게임을 깼습니다!\n");
   a = 4;

   end = time(NULL);

   int time = (int)end - start;
   int myRank = 0;

   for (int i = 0; i < 5; i++) {
      if (rank[i][0] == 0 || time < rank[i][1] || (time == rank[i][1] && score > rank[i][2])) {
         break;
      }
      myRank++;
   }

   for (int i = 4; i >= myRank; i--) {
      rank[i][0] = rank[i - 1][0];
      rank[i][1] = rank[i - 1][1];
      rank[i][2] = rank[i - 1][2];
   }

   rank[myRank][0] = id;
   rank[myRank][1] = time;
   rank[myRank][2] = score;

   printf("내 아이디 : %d\n", id);
   printf("시간 : %d초\n", time);
   printf("점수 : %d\n", score);
   printf("--------------------\n");
   printf("아이디\t시간\t점수\n");
   for (int i = 0; i < 5; i++) {
      printf("%d\t%d\t%d\n", rank[i][0], rank[i][1], rank[i][2]);
   }
   printf("--------------------\n");

   id++;
   int input;

   printf("%s", "다시 시작하시려면 1번, 종료하시려면 2번을 입력해주세요. : \n");
   scanf_s("%d", &input);

   if (input != 1) {
      finish = 1;
   }
}

void process(int* a) {
   if (*a == 2) {
      score++;
   }
   *a = 9;
}

typedef struct drama {
   char title[SIZE];               //드라마 제목
   char viewer_ratings[SIZE];         //시청률
   char broadcastiong_company[SIZE];   //방송국
   char coach[SIZE];               //감독

}DRAMA;   //드라마 구조체 선언

void menu();
DRAMA get_record();
void print_record(DRAMA data);
void add_record(FILE *fp);
void search_record(FILE *fp);
void list_record(FILE *fp);


int main(void)
{
   FILE* fp;
   int select;
   //이진 파일을 추가 모드로 오픈한다.
   if ((fp = fopen("dramas.dat", "a+")) == NULL) {
      fprintf(stderr, "입력을 위한 파일을 열 수 없습니다.");
      exit(1);
   }
   while (1) {
      menu();                  //메뉴 표시
      printf("번호를 입력하세요: ");
      scanf("%d", &select);
      switch (select)
      {
         case 1: add_record(fp); break;      //데이터 추가
         case 2: list_record(fp); break;      //데이터 보기
         case 3: search_record(fp); break;   //데이터 탐색
         case 4: return 0;
         case 5:                  //게임 실행
            while (finish == 0) {
            int pan[10][10] = {
               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
               {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
               {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
               {1, 0, 0, 0, 1, 0, 0, 1, 2, 1},
               {1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
               {1, 0, 0, 1, 1, 1, 0, 1, 0, 1},
               {1, 0, 0, 0, 0, 1, 2, 0, 0, 1},
               {1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
               {1, 2, 1, 0, 0, 1, 0, 0, 0, 0},
               {1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
            };
            int x = 1, y = 1, z;
            int key;
            score = 0, a = 3;

            while (a < 4) {
               system("cls");
               printf("%s", "주어진 지도로 게임을 시작하시려면 1번, 지도를 직접 입력하시려면 2번을 입력해주세요. : \n");
               scanf_s("%d", &z);
               if (z == 1) {
                  break;
               }
               else if (z == 2) {
                  printf("%s", "10*10 지도를 입력하세요 : \n");
                  for (int i = 0; i < 10; i++) {
                     for (int j = 0; j < 10; j++) {
                        scanf_s("%d", &pan[i][j]);
                     }
                  }
                  break;
               }
               else {
                  printf("%s", "유효하지 않은 입력값입니다.\n");
               }
            }

            pan[x][y] = 9;
            print_maze(pan);

            start = time(NULL);

            while (a < 4) {
               if (_kbhit()) {
                  key = _getch();
                  if (key == 224 || key == 0) {
                     key = _getch();
                     switch (key) {
                     case 72: // 위
                        if (x - 1 >= 0 && pan[x - 1][y] == 1) break;
                        if (x == 0) { clear(); break; }
                        pan[x][y] = 0;
                        process(&pan[x - 1][y]);
                        x--;
                        print_maze(pan);
                        break;
                     case 75: // 왼쪽
                        if (y - 1 >= 0 && pan[x][y - 1] == 1) break;
                        if (y == 0) { clear(); break; }
                        pan[x][y] = 0;
                        process(&pan[x][y - 1]);
                        y--;
                        print_maze(pan);
                        break;
                     case 77: // 오른쪽
                        if (y + 1 <= 9 && pan[x][y + 1] == 1) break;
                        if (y == 9) { clear(); break; }
                        pan[x][y] = 0;
                        process(&pan[x][y + 1]);
                        y++;
                        print_maze(pan);
                        break;
                     case 80: // 아래
                        if (x + 1 <= 9 && pan[x + 1][y] == 1) break;
                        if (x == 9) { clear(); break; }
                        pan[x][y] = 0;
                        process(&pan[x + 1][y]);
                        x++;
                        print_maze(pan);
                        break;
                     }
                  }

               }

            }
         }
         default: printf("1~5사이에 숫자를 입력하세요\n"); break;


      }
      
      }
      fclose(fp);
      return 0;
   }

   

//사용자로부터 데이터를 받아서 구조체로 반환한다.
DRAMA get_record()
{
   DRAMA data;
   getchar();      //줄바꿈 문자 없애기
   printf("드라마 제목: "); gets(data.title);
   printf("시청률: "); gets(data.viewer_ratings);
   printf("방송사: "); gets(data.broadcastiong_company);
   printf("감독: "); gets(data.coach);
   return data;
}

// 구조체 데이터를 화면에 출력한다.
void print_record(DRAMA data)
{
   printf("드라마 제목: %s\n", data.title);
   printf("시청률: %s\n", data.viewer_ratings);
   printf("방송사: %s\n", data.broadcastiong_company);
   printf("감독: %s\n", data.coach);
}
//메뉴를 화면에 표시하는 함수
void menu()
{
   printf("==================\n");

   printf("****** Menu ******\n");
   printf("드라마 프로그램\n");
   printf(" 1.추가\n 2.보기\n 3.검색\n 4.종료\n 5.게임\n");
   printf("==================\n");

}
//데이터를 추가한다.
void add_record(FILE* fp)
{
   DRAMA data;
   data = get_record();               //사용자로부터 데이터를 받아서 구조체에 저장
   fseek(fp, 0, SEEK_END);   //파일의 끝으로 간다.
   fwrite(&data, sizeof(data), 1, fp);   //구조체 데이터를 파일에 쓴다.
}
//데이터를 탐색한다.
void search_record(FILE* fp)
{
   char title[SIZE];
   DRAMA data;
   fseek(fp, 0, SEEK_SET);   //파일의 처음으로 간다
   getchar();               //줄바꿈 문자 없애기
   printf("탐색하고자 하는 드라마 제목: ");
   gets(title);
   while (!feof(fp))         //파일의 끝까지 반복한다.
   {
      fread(&data, sizeof(data), 1, fp);
      if (strcmp(data.title, title) == 0) {         //이름 비교
         print_record(data);
         break;
      }
   }
}
//데이터를 본다.
void list_record(FILE* fp)
{
   DRAMA data;
   fread(&data, sizeof(data), 1, fp);
   printf("\n");
   printf("==============================\n");
   printf("드라마 제목 \t 시청률  방송사  감독 \n");
   printf("==============================\n");
   printf("%s \t %s \t %s \t %s\n", data.title, data.viewer_ratings, data.broadcastiong_company, data.coach);
   
}
