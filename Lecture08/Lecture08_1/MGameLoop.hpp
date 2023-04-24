#define _IS_THIS_HEADER_INCLUDED
#include <iostream>
#include <conio.h>

namespace MuSoeun {

    class MGameLoop {
    public:
        MGameLoop() {}
        ~MGameLoop() {}
        
        bool isGameRunning = false;
        
        void Run() 
        {
            
            isGameRunning = true;
            while (isGameRunning)
            {
                std::cout << "게임 실행중" << std::endl;
                if (_kbhit())
                {
                    if (_getch() == 27) {
                        isGameRunning = false;
                    }  
                }
            }
        }
    };
}
