#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

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

   int time = (int) end - start;
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

int main()
{   
   while(finish == 0) {
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

      while(a < 4) {
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
               if (x-1 >= 0 && pan[x - 1][y] == 1) break;
               if (x == 0) { clear(); break; }
               pan[x][y] = 0;
               process(&pan[x - 1][y]);
               x--;
               print_maze(pan);
               break;
            case 75: // 왼쪽
               if (y-1 >= 0 && pan[x][y - 1] == 1) break;
               if (y == 0) { clear(); break; }
               pan[x][y] = 0;
               process(&pan[x][y - 1]);
               y--;
               print_maze(pan);
               break;
            case 77: // 오른쪽
               if (y+1 <= 9 && pan[x][y + 1] == 1) break;
               if (y == 9) { clear(); break; }
               pan[x][y] = 0;
               process(&pan[x][y + 1]);
               y++;
               print_maze(pan);
               break;
            case 80: // 아래
               if (x+1 <= 9 && pan[x+1][y] == 1) break;
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
}
