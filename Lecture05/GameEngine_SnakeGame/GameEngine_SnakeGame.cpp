#include <iostream>
#include <conio.h>
#include <Windows.h>

//game state == 0
void print_game_screen(char** map, int stage_width, int stage_height);

int print_title_screen() {


	std::cout << "■■■■■■■■■■■■■■■■■■■■■" << std::endl;
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
	std::cout << "■■■■■■■■■■■■■■■■■■■■■" << std::endl;

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

	std::cout << "■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■          게임 설명화면입니다.      ■" << std::endl;
	std::cout << "■ Snake bite란... 인터넷에...        ■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■   타이틀화면으로 돌아갈까요? (Y/N) ■" << std::endl;

	return 0;
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
					int stage_width, stage_height;
					std::cout << "■맵을 만들기 위해 x,y값을 입력해주세요!■" << std::endl;
					std::cout << "■■■■■■■■■■■■■■■■■■■■■" << std::endl;
					scanf_s("%d", &stage_width);
					scanf_s("%d", &stage_height);
					system("cls");
					InitMap(stage_width, stage_height);
				}
				mod_refresh = 0;
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
