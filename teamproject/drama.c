
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARINGS
#include <stdlib.h>
#include <math.h>
#define SIZE 100
/*드라마 프로그램 만들기(드라마 제목 감독 시청률 방송사) title viewer_ratings coach broadcastiong_company*/

typedef struct drama {
   char title[SIZE];
   char viewer_ratings[SIZE];
   char broadcastiong_company[SIZE];
   char coach[SIZE];

}DRAMA;

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
   if ((fp = fopen("dramas.dat", "a+")) == NULL) {
      fprintf(stderr, "입력을 위한 파일을 열 수 없습니다.");
      exit(1);
   }
   while (1) {
      menu();
      printf("정수값을 입력하세요: ");
      scanf("%d", &select);
      switch (select)
      {
         case 1: add_record(fp); break;
         case 2: list_record(fp); break;
         case 3: search_record(fp); break;
         case 4: return 0;
      
      }
   }
   fclose(fp);

   return 0;
}
DRAMA get_record()
{
   DRAMA data;
   getchar();
   printf("제목: "); gets(data.title);
   printf("시청률: "); gets(data.viewer_ratings);
   printf("방송사: "); gets(data.broadcastiong_company);
   printf("감독: "); gets(data.coach);
   return data;
}

void print_record(DRAMA data)
{
   printf("제목: %s\n", data.title);
   printf("시청률: %s\n", data.viewer_ratings);
   printf("방송사: %s\n", data.broadcastiong_company);
   printf("감독: %s\n", data.coach);
}
void menu()
{
   printf("==================\n");

   printf("****** Menu ******\n");
   printf(" 1.추가\n 2.보기\n 3.검색\n 4.종료\n");
   printf("==================\n");

}

void add_record(FILE* fp)
{
   DRAMA data;
   data = get_record();
   fseek(fp, 0, SEEK_END);
   fwrite(&data, sizeof(data), 1, fp);
}

void search_record(FILE* fp)
{
   char title[SIZE];
   DRAMA data;
   fseek(fp, 0, SEEK_SET);
   getchar();
   printf("탐색하고자 하는 드라마 제목: ");
   gets(title);
   while (!feof(fp))
   {
      fread(&data, sizeof(data), 1, fp);
      if (strcmp(data.title, title) == 0) {
         print_record(data);
         break;
      }
   }
}
void list_record(FILE* fp)
{
   DRAMA data;
   fread(&data, sizeof(data), 1, fp);
   printf("\n");
   printf("==============================\n");
   printf("제목 \t 시청률  방송사  감독 \n");
   printf("==============================\n");
   printf("%s \t %s \t %s \t %s\n", data.title, data.viewer_ratings, data.broadcastiong_company, data.coach);
   
}
