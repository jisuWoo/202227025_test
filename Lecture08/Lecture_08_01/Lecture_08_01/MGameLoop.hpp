#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

#define KEY_ESC 27
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_ENTER 13

namespace MuSoeun
{
	void gotoxy(int x, int y) {
		//x, y ��ǥ ����
		COORD pos = { x,y };
		//Ŀ�� �̵�
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	void SetCursorState(bool visible)
	{
		CONSOLE_CURSOR_INFO consoleCursorInfo;
		consoleCursorInfo.bVisible = visible;
		consoleCursorInfo.dwSize = 1;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
	}

	class MGameLoop
	{
	public:
		MGameLoop() {}
		~MGameLoop() {}

		bool isGameRunning = false;
		bool isPause = false;

		void Initialize()
		{
			SetCursorState(false);

			gotoxy(3, 15);
			std::cout << ANSI_COLOR_RESET"���� �ʱ�ȭ��" << std::endl;
			isGameRunning = true;
		}
		void Release()
		{
			gotoxy(3, 18);
			std::cout << ANSI_COLOR_RESET"���� ������" << std::endl;
		}
		void Update()
		{
			gotoxy(3, 16);
			std::cout << ANSI_COLOR_RESET"���� Ű�Է� ���" << std::endl;
			if (_kbhit())
			{
				KeyEvent(_getch());
			}
		}
		void Render()
		{
			gotoxy(3, 17);
			std::cout << ANSI_COLOR_RESET"���� ȭ�� �׸���" << std::endl;
		}
		void RenderRest()
		{
			gotoxy(3, 20);
			std::cout << "                      " << std::endl;
			gotoxy(3, 22);
			std::cout << "          " << std::endl;
			gotoxy(7, 22);
			std::cout << "          " << std::endl;
		}

		void isGameover() {
			bool isSelectedL = false;
			bool isSelectedR = false;
			gotoxy(3, 20);
			std::cout << "���� �Ͻðڽ��ϱ�?  " << std::endl;
			gotoxy(3, 22);
			std::cout << "��  " << std::endl;
			gotoxy(7, 22);
			std::cout << "�ƴϿ�  " << std::endl;
			//isGameRunning = false;

			while (isPause) {
				if (_kbhit())
				{
					char kinput = _getch();
					switch (kinput)
					{
					case KEY_LEFT:

						if (isSelectedR) {
							gotoxy(7, 22);
							std::cout << ANSI_COLOR_RESET"�ƴϿ�  " << std::endl;
						}
						if (isSelectedL == false) {
							gotoxy(3, 22);
							std::cout << ANSI_COLOR_YELLOW"��  " << std::endl;

						}
						isSelectedL = true;
						isSelectedR = false;
						break;
					case KEY_RIGHT:
						if (isSelectedL) {
							gotoxy(3, 22);
							std::cout << ANSI_COLOR_RESET"��  " << std::endl;
						}
						if (isSelectedR == false) {
							gotoxy(7, 22);
							std::cout << ANSI_COLOR_YELLOW"�ƴϿ� " << std::endl;
						}
						isSelectedR = true;
						isSelectedL = false;
						break;
					case KEY_ENTER:
						if (isSelectedL) {
							RenderRest();
							isPause = false;
							isGameRunning = false;
						}
						if (isSelectedR) {
							RenderRest();
							isPause = false;
							isGameRunning = true;
						}
						break;
					default:
						//isGameRunning = true;
						break;
					}
				}
			}
		}

		void Run()
		{
			Initialize();
			while (isGameRunning)
			{
				if (isPause == false) {
					Update();
					Render();
				}
			}
			Release();
		}

		void KeyEvent(char KeyInput)
		{
			switch (KeyInput)
			{

			case KEY_ESC:
				isPause = true;
				isGameover();
				break;
			case KEY_LEFT:
				if (isPause == false) {
					gotoxy(5, 5);
					std::cout << ANSI_COLOR_RED"���� ����  " << std::endl;
				}
				break;
			case KEY_RIGHT:
				if (isPause == false) {
					gotoxy(5, 5);
					std::cout << ANSI_COLOR_GREEN"������ ����" << std::endl;
				}
				break;
			case KEY_ENTER:
				if (isPause == false) {
					gotoxy(5, 5);
					std::cout << ANSI_COLOR_BLUE"���� ����  " << std::endl;
				}
				break;
			default:
				isGameRunning = true;
				break;
			}

		}
	};

}