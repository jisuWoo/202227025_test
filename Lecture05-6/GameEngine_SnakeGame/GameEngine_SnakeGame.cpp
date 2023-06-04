#include <iostream>
#include <conio.h>
#include <Windows.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define PAUSE 112
#define ESC 27


int length;
int item_x;
int item_y;
int score;
int x[40];
int y[40];
int dir;

//game state == 0
void print_game_screen(char** map, int stage_width, int stage_height);
void item(int stage_width, int stage_height);

int print_title_screen() {


	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■                                      ■" << std::endl;
	std::cout << "■                                      ■" << std::endl;
	std::cout << "■             지렁이 게임              ■" << std::endl;
	std::cout << "■            (Snake  Bite)             ■" << std::endl;
	std::cout << "■                                      ■" << std::endl;
	std::cout << "■  1. 게임 시작                        ■" << std::endl;
	std::cout << "■  2. 게임 설명                        ■" << std::endl;
	std::cout << "■  3. 게임 랭킹 보기                   ■" << std::endl;
	std::cout << "■  4. 게임 종료 (esc)                  ■" << std::endl;
	std::cout << "■                                      ■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;

	return 0;

}

void gotoxy(int x, int y) {
	//x, y 좌표 설정
	COORD pos = { x * 2 , y }; // 세로랑 가로와 격차가 있어 곱하기추가
	//커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//game_state == 1
int InitMap(int stage_width, int stage_height) {

	char** map = (char**)malloc(sizeof(char*) * (stage_height + 2));
	for (int i = 0; i < stage_height + 2; i++) {
		map[i] = (char*)malloc(sizeof(char) * (stage_width + 2));
		for (int j = 0; j < stage_width + 2; j++) {
			if (i == 0 || i == stage_height + 1 || j == 0 || j == stage_width + 1) {
				map[i][j] = '*';
			}
			else {
				map[i][j] = ' ';
			}
		}
	}
	print_game_screen(map, stage_width, stage_height);

	for (int i = 0; i < stage_height; i++) {
		free(map[i]);
	}
	free(map);

	return 0;
}

void print_game_screen(char** map, int stage_width, int stage_height)
{
	for (int i = 0; i < stage_height + 2; i++) {
		for (int j = 0; j < stage_width + 2; j++) {
			gotoxy(j, i);
			printf("%c", map[i][j]);
		}
	}
}

//game state == 2
int print_introduction_screen() {

	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■          게임 설명화면입니다.      ■" << std::endl;
	std::cout << "■ Snake bite란... 인터넷에...        ■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■   타이틀화면으로 돌아갈까요? (Y/N) ■" << std::endl;

	return 0;
}

int GameOver() {

	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■        게임 오버                  ■" << std::endl;
	std::cout << "■ Snake bite란... 인터넷에...        ■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■   타이틀화면으로 돌아갈까요? (Y/N) ■" << std::endl;

	return 0;
}

void move(int dir,int stage_width, int stage_height) {
	int i;

	if (x[0] == item_x && y[0] == item_y) { //item과 충돌했을 경우
		score += 10;
		item(stage_width, stage_height); //새로운 food 추가
		length++;
		x[length] = x[length - 1]; //움직일수록 좌표값이 변해야하기 때문에
		//전에 있던 몸통좌표값을 새로 움직인 좌표값에 넣어줌 
		y[length] = y[length - 1];
	}
	if (x[0] == 3 || x[0] == stage_width - 1 || y[0] == 3 || y[0] == stage_height - 1) {
		//gameOver();
		return; //gameOver에서 게임을 다시 시작하게 되면 여기서부터 반복되므로 초기화
	}

	gotoxy(x[length - 1], y[length - 1]);
	printf(" ");
	//뱀의 좌표가 움직일때마다 맨뒤의 값을 지워줘야함 -> 공백처리
	for (i = length - 1; i > 0; i--) {
		x[i] = x[i - 1];
		y[i] = y[i - 1];
	}

	gotoxy(x[0], y[0]);
	printf("o");
	if (dir == LEFT)
		--x[0];
	if (dir == RIGHT)
		++x[0];
	if (dir == UP)
		--y[0];
	if (dir == DOWN)
		++y[0];

	gotoxy(x[i], y[i]);
	printf("◎");
};

void reset() {
	system("cls");
}

void item(int stage_width, int stage_height) {
	int r = 0;
	int item_crush = 0;
	//43, 28
	while (1) {
		srand((unsigned)time(NULL) + r); //계속값이 바뀔수있도록 +r을해줌
		item_x = (rand() % stage_width - 2) + 1; //1~42까지
		item_y = (rand() % stage_height - 2) + 1; //1~28까지

		for (int i = 0; i < length; i++) {
			if (item_x == x[i] && item_y == y[i]) {
				item_crush = 1;
				r++;
				break;
			}
		}

		if (item_crush == 1)
			continue;
		gotoxy(item_x, item_y);
		printf("@");
		break;
	}
}


int main() {
	/*
	GameState
	0 : 게임 종료
	1 : 시작화면
	2 : 게임 설명
	3 : 게임 랭킹
	*/

	int game_state = 1;
	int mod_refresh = 1;
	int sub_title_state = 1;
	char key_input = 0;

	while (game_state) {

		switch (game_state)
		{
		case 0:
			game_state = 0;
			break;
		case 1:
			while (sub_title_state)
			{
				if (mod_refresh)
				{
					print_title_screen();
					mod_refresh = 0;
				}
				key_input = _getch();
				switch (key_input)
				{
				case '0':
					sub_title_state = 0;
					game_state = 0;
					break;
				case '1':
					sub_title_state = 0;
					game_state = 1;
					mod_refresh = 1;
					break;
				case '2':
					sub_title_state = 0;
					mod_refresh = 1;
					game_state = 2;
					break;
				case '3':
					//game_state = 3;
					break;
				case '4':
					sub_title_state = 0;
					game_state = 0;
					break;
				case 27:
					sub_title_state = 0;
					game_state = 0;
					break;
				default:
					break;
				}
			}
			if (sub_title_state == 0 && game_state == 1) {
				if (mod_refresh)
				{
					int mapbuild = 0;
					if (mapbuild) {
						int stage_width, stage_height;
						std::cout << "■맵을 만들기 위해 x,y값을 입력해주세요!■" << std::endl;
						std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
						scanf_s("%d", &stage_width);
						scanf_s("%d", &stage_height);
						system("cls");
						InitMap(stage_width, stage_height);
					}
					char key = _getch();
					switch (key) {
					case LEFT:
					case RIGHT:
					case UP:
					case DOWN:
						if ((dir == LEFT && key != RIGHT) || (dir == RIGHT && key != LEFT) || (dir == UP && key != DOWN) || (dir == DOWN && key != UP))
							dir = key;
						key = 0;
						break;
					case ESC:
						exit(0);
					}
					move(dir,stage_width, stage_height);

				}
				//mod_refresh = 0;
			};
			break;
		case 2:
			if (mod_refresh)
			{
				print_introduction_screen();
			}
			key_input = _getch();

			mod_refresh = 0;

			if (key_input == 'y') {
				game_state = 1;
				sub_title_state = 1;
				mod_refresh = 1;
			}
			else if (key_input == 'n') {
			}
			break;
		case 3:
			break;
		default:
			break;
		}

	}

	return 0;
}
