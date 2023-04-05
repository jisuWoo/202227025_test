#include <iostream>
#include <conio.h>
#include <Windows.h>

//game state == 0
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
	COORD pos = { x,y };
	//커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int print_game_screen(int stage_width, int stage_height)
{

	for (int i = 0; i < stage_width; i++) {
		gotoxy(i, 0);
		std::cout << "■" << std::endl;
	}
	for (int i = 0; i < stage_height; i++) {
		gotoxy(0, i);
		std::cout << "■" << std::endl;
	}
	for (int i = 0; i < stage_height; i++) {
		gotoxy(stage_width, i);
		std::cout << "■" << std::endl;
	}
	for (int i = 0; i <= stage_width; i++) {
		gotoxy(i, stage_height);
		std::cout << "■" << std::endl;
	}

	return 0;
}


//game state == 2
int print_introduction_screen() {

	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■          게임 설명화면입니다.      ■" << std::endl;
	std::cout << "■ Snake bite란... 인터넷에...        ■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■   타이틀화면으로 돌아갈까요? (Y/N) ■" << std::endl;

	return 0;
}


int main() {
	
	int game_state = 0;
	int mod_refresh = 1;
	int is_game_runing = 1;

	while (is_game_runing)
	{
		char key_input = 0;
		switch (game_state)
		{
			case 0:
				if (mod_refresh) {
					print_title_screen();
				};
				key_input = _getch();
				
				mod_refresh = 0;
				
				switch (key_input)
				{
					case '1':
						game_state = 1;
						mod_refresh = 1;
						break;
					case '2':
						game_state = 2;
						mod_refresh = 1;
						break;
					case '3':
						break;
					case '4':
						is_game_runing = 0;
						break;
					case 27:
						is_game_runing = 0;
					default:
						break;
				}
				break;
			case 1:
				//system("cls");
				if (mod_refresh) {
					int x=0;
					int y=0;
					std::cout << "■맵을 만들기 위해 x,y값을 입력해주세요!■" << std::endl;
					std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
					scanf_s("%d", &x);
					scanf_s("%d", &y);
					system("cls");
					print_game_screen(x, y);
				};
				key_input = _getch();
				mod_refresh = 0;
				break;
			case 2:

				if(mod_refresh){
					print_introduction_screen();
				}

				key_input = 0;
				key_input = _getch();
				
				mod_refresh = 0;

				if (key_input == 'y') {
					game_state = 0;
					mod_refresh = 1;
				}
				else if (key_input == 'n') {
					
				}
				
			default:
				break;
		}
		
	}
	return 0;
}