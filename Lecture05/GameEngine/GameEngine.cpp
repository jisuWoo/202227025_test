#include <iostream>
#include <conio.h>
#include <Windows.h>

//game state == 0
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

//game state == 2
int print_introduction_screen() {

	std::cout << "■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■          게임 설명화면입니다.        ■" << std::endl;
	std::cout << "■ Snake bite란... 인터넷에...          ■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■   타이틀화면으로 돌아갈까요? (Y/N)   ■" << std::endl;

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
						//game_state = 1;
						break;
					case '2':
						mod_refresh = 1;
						game_state = 2;
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