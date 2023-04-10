#include <iostream>
#include <conio.h>
#include <Windows.h>

char** map = NULL;
int stage_width = 15;
int stage_height = 15;

//맵을 이중 포인터 배열로 만들고, 뱀을 배열안에 생성


int InitMap() {
	if (map == nullptr) {

		map = (char**)malloc(sizeof(char*) * stage_width);
		
		for (int i = 0; i < stage_height; i++) {
			map[i] = new char[stage_width];
		}
	}
	return 0;
}

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

void gotoxy(int x, int y) {
	//x, y 좌표 설정
	COORD pos = { x*2,y }; // 세로랑 가로와 격차가 있어 곱하기추가
	//커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int print_game_screen(int stage_width, int stage_height)
{

	for (int i = 0; i < stage_width+2; i++) {
		gotoxy(i, 0);	//첫번째 가로
		std::cout << "■" << std::endl;
			
		gotoxy(i, stage_height+1);	//두번쨰 가로
		std::cout << "■" << std::endl;

	}
	for (int i = 0; i < stage_height+2; i++) {
	
		gotoxy(0, i);	//첫번쨰 세로
		std::cout << "■" << std::endl;

		gotoxy(stage_width+1, i);		//두번째 세로
		std::cout << "■" << std::endl;
	}
	//양쪽의 세로와 가로줄을 칸에 포함해서, 계산하지 않아 임의로 칸을 추가함
	return 0;
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
	//int is_game_runing = 1;

	//while (game_state) {

	//	switch (game_state) 
	//	{
	//		case 0:
	//			game_state = 0;
	//			break;
	//		case 1:
	//			print_title_screen();
	//			int sub_title_state = 1;
	//			while (sub_title_state) {
	//				char key_input = _getch();
	//				switch (key_input)
	//				{
	//					case '0':
	//						game_state = 0;
	//						break;
	//					case '1':
	//						game_state = 1;
	//						//mod_refresh = 1;
	//						break;
	//					case '2':
	//						game_state = 2;
	//						//mod_refresh = 1;
	//						break;
	//					case '3':
	//						game_state = 3;
	//						break;
	//					case '4':
	//						break;
	//					case 27:
	//						break;
	//					default:
	//						break;
	//				}
	//			}
	//			break;
	//		case 2:
	//			break;
	//		case 3:
	//			break;
	//		default:
	//			break;
	//	}



	//}



	//while (is_game_runing)
	//{



	//	char key_input = 0;
	//	switch (game_state)
	//	{
	//		case 0:
	//			if (mod_refresh) {
	//				print_title_screen();
	//			};
	//			key_input = _getch();
	//			
	//			mod_refresh = 0;
	//			
	//			switch (key_input)
	//			{
	//				case '1':
	//					game_state = 1;
	//					mod_refresh = 1;
	//					break;
	//				case '2':
	//					game_state = 2;
	//					mod_refresh = 1;
	//					break;
	//				case '3':
	//					break;
	//				case '4':
	//					is_game_runing = 0;
	//					break;
	//				case 27:
	//					is_game_runing = 0;
	//				default:
	//					break;
	//			}
	//			break;
	//		case 1:
	//			//system("cls");
	//			if (mod_refresh) {
	//				int x=0;
	//				int y=0;
	//				std::cout << "■맵을 만들기 위해 x,y값을 입력해주세요!■" << std::endl;
	//				std::cout << "■■■■■■■■■■■■■■■■■■■■■" << std::endl;
	//				scanf_s("%d", &x);
	//				scanf_s("%d", &y);
	//				system("cls");
	//				print_game_screen(x, y);
	//			};
	//			mod_refresh = 0;
	//			break;
	//		case 2:

	//			if(mod_refresh){
	//				print_introduction_screen();
	//			}

	//			key_input = 0;
	//			key_input = _getch();
	//			
	//			mod_refresh = 0;

	//			if (key_input == 'y') {
	//				game_state = 0;
	//				mod_refresh = 1;
	//			}
	//			else if (key_input == 'n') {
	//				
	//			}
	//			
	//		default:
	//			break;
	//	}
	//	
	//}
	return 0;
}