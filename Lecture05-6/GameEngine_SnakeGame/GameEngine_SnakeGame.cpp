#include <iostream>
#include <conio.h>
#include <Windows.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define PAUSE 112
#define ESC 27

//game state == 0
void print_game_screen(char** map, int stage_width, int stage_height);

int x[100], y[100]; //x,y 좌표값을 저장 총 100개 
int food_x, food_y; //food의 좌표값을 저장 
int length; //몸길이를 기억 
int speed; //게임 속도 
int score; //점수 저장  --reset함수에 의해 초기화됨
int best_score=0; //최고 점수 저장 --reset함수에 의해 초기화 되지 않음 
int last_score=0; //마지막 점수 저장  --reset함수에 의해 초기화 되지 않음
int dir; //이동방향 저장 
int key; //입력받은 키 저장 


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

	std::cout << "■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■          게임 설명화면입니다.      ■" << std::endl;
	std::cout << "■ Snake bite란... 인터넷에...        ■" << std::endl;
	std::cout << "■■■■■■■■■■■■■■■■■■■■" << std::endl;
	std::cout << "■   타이틀화면으로 돌아갈까요? (Y/N) ■" << std::endl;

	return 0;
}

void move(int dir){
    int i;
 
    if(x[0]==food_x&&y[0]==food_y){ //food와 충돌했을 경우 
        score+=10; //점수 증가 
        food(); //새로운 food 추가 
        length++; //길이증가 
        x[length-1]=x[length-2]; //새로만든 몸통에 값 입력 
        y[length-1]=y[length-2];
    }
    if(x[0]==0||x[0]==MAP_WIDTH-1||y[0]==0||y[0]==MAP_HEIGHT-1){ //벽과 충돌했을 경우 
        game_over();
        return; //game_over에서 게임을 다시 시작하게 되면 여기서부터 반복되므로 
                //return을 사용하여 move의 나머지 부분이 실행되지 않도록 합니다. 
    }
    for(i=1;i<length;i++){ //자기몸과 충돌했는지 검사 
        if(x[0]==x[i]&&y[0]==y[i]){
            game_over();
            return;
        }
    }
    
    gotoxy(MAP_X+x[length-1],MAP_Y+y[length-1],"  "); //몸통 마지막을 지움 
    for(i=length-1;i>0;i--){ //몸통좌표를 한칸씩 옮김 
        x[i]=x[i-1];
        y[i]=y[i-1];
    }
    gotoxy(MAP_X+x[0],MAP_Y+y[0],"ㅇ"); //머리가 있던곳을 몸통으로 고침 
    if(dir==LEFT) --x[0]; //방향에 따라 새로운 머리좌표(x[0],y[0])값을 변경 
    if(dir==RIGHT) ++x[0];
    if(dir==UP) --y[0]; 
    if(dir==DOWN) ++y[0];     
    gotoxy(MAP_X+x[i],MAP_Y+y[i],"ㅎ"); //새로운 머리좌표값에 머리를 그림 
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
					switch(key)
					{ //입력받은 키를 파악하고 실행  
                        case LEFT:
                        case RIGHT:
                        case UP:
                        case DOWN:
                            if((dir==LEFT&&key!=RIGHT)||(dir==RIGHT&&key!=LEFT)||(dir==UP&&key!=DOWN)||
                            (dir==DOWN&&key!=UP))//180회전이동을 방지하기 위해 필요. 
                            dir=key;
                            key=0; // 키값을 저장하는 함수를 reset 
                            break;
                        case PAUSE: // P키를 누르면 일시정지 
                            pause();
                            break;
                        case 115: //S키를 누르면 개발자용 status를 활성화 시킴  
                            if(status_on==0) status_on=1;
                            else status_on=0;
                            key=0;
                            break;
                        case ESC: //ESC키를 누르면 프로그램 종료 
                            exit(0);
                    }
                    move(dir); 
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
