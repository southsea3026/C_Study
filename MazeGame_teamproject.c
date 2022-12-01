#include <stdio.h>
#include <conio.h>
#include <windows.h>

// 코드 주제: 방향키를 이용해 점수를 먹고 최종적으로 미로를 탈출하는 게임 

// score, a //??????????????????????????
int score = 0, a = 3;

// 'pan'은 미로의 지도를 나타낸다.
// 미로는 2차원 배열을 사용하여 10x10으로 설정하였다.
int map[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 1, 2, 1},
	{1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 1, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 2, 0, 0, 1},
	{1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
	{1, 2, 1, 0, 0, 1, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// 미로 출력 함수
void print_maze() {
	// 미로를 출력하기 전에 화면을 clean한다. 
	system("cls");
	
	// 중첩 for문을 사용하여 미로를 출력한다. 
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	
	// 점수 출력
	printf("점수 : %d", score);
}

// 성공 화면 출력 
void game_end() {
	// 화면을 clean하고 게임이 끝남을 알린다.
	system("cls");
	printf("%s", "축하합니다! 게임을 깼습니다!");
	
	// a = 4 //?????????????????
	a = 4;
}

// process, a, *a  //?????????????????????
void process(int* a) {
	
	// 2를 먹으면 점수가 올라간다. 
	if (*a == 2) {
		score++;
	}
	*a = 9;
}

int main()
{	
	int x = 1, y = 1, z;
	int key;
	
	// a가 4보다 작아야 하는 이유가 무엇이지?????????????????????? 
	while(a < 4) {
		printf("%s", "주어진 지도로 게임을 시작하시려면 1번, 지도를 직접 입력하시려면 2번을 입력해주세요. : \n");
		scanf("%d", &z);
		if (z == 1) {
			break;
		}
		
		// **********지도 직접 입력 삭제하기 *************** //
		else if (z == 2) {
			printf("%s", "10*10 지도를 입력하세요 : \n");
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					scanf("%d", &map[i][j]);
				}
			}
			break;
		}
		
		else {
			printf("%s", "유효하지 않은 입력값입니다.\n");
		}
	}
	
	// 게임 시작 위치: map[1][1]에 9를 통해 플레이어의 위치를 나타낸다.  
	map[x][y] = 9;
	print_maze();
	
	while (a < 4) {
		
		// kbhit(), getch() 참고 블로그 
		// https://m.blog.naver.com/sharonichoya/220875372940
		// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=tipsware&logNo=221242072724
		
		// kbhit() 함수는 키 입력 관련 함수이다. 
		// kbhit() 함수는 현재 키보드가 입력된 상태인지 조사한다.
		// getch() 함수는 키보드의 입력을 받는 함수이다.
		// scanf()와 다른 점은 입력한 키보드의 내용이 화면에 보이지 않는다.
		// 또 엔터키를 눌러 값을 입력하지 않는다. 키를 눌렀을 때 getch() 함수가 바로 키 값을 입력한다.
		 
		// 방향키의 아스키 코드값은 다음과 같다. 
		// 위 = 72, 왼쪽 = 75, 오른쪽 = 77, 아래 = 80 
		if (_kbhit()) {
			key = _getch();
			if (key == 224 || key == 0) {
				key = _getch();
				switch (key) {
				// 게임 탈출 조건이 무엇인지 잘 이해되지 않는다.	
				
				case 72: // 위
					// x-1이 0과 같거나 크면 맵의 바깥에 위치한 것임으로 실행하지 않는다.??????????????????????????
					// [x-1][y] 가 1이면 미로의 벽에 막힌 것임으로 실행하지 않는다.
					if (x-1 >= 0 && map[x - 1][y] == 1) break;
					
					// 맵은 10x10이므로 x와 y는 0부터 9까지 값을 가진다.
					// 현재 xy가 {1,1}에 위치하면 위로 움직일 때 map[x][y]=0;과 process(&map[x-1[y] 처리를 통해 현재 위치에 0을 입력하고 움직일 위치에 9를 입력한다.
					// 그 후 위로 움직였으니 {0,1}이 되어야 함으로 x--를 한다.
					// 다시 위로 움직이면 맵 바깥으로 나가는 것이니 게임을 끝내야한다.
					// 벽이 있는지 확인하고 없으면 탈출, 게임 클리어를 띄우고 탈출한다.
					if (x == 0) { game_end(); break; }
					map[x][y] = 0;
					process(&map[x - 1][y]);
					x--;
					print_maze();
					break;
				case 75: // 왼쪽
					if (y-1 >= 0 && map[x][y - 1] == 1) break;
					if (y == 0) { game_end(); break; }
					map[x][y] = 0;
					process(&map[x][y - 1]);
					y--;
					print_maze();
					break;
				case 77: // 오른쪽
					if (y+1 <= 9 && map[x][y + 1] == 1) break;
					if (y == 9) { game_end(); break; }
					map[x][y] = 0;
					process(&map[x][y + 1]);
					y++;
					print_maze();
					break;
				case 80: // 아래
					if (x+1 <= 9 && map[x+1][y] == 1) break;
					if (x == 9) { game_end(); break; }
					map[x][y] = 0;
					process(&map[x + 1][y]);
					x++;
					print_maze();
					break;
				}
			}

		}

	}
}
