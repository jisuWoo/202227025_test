#include <iostream>
#include<conio.h>

int main(){


	while(true){
	

		if(_kbhit())
		{

			int ch = _getch();
			if(ch == 27){
				break; 
			}
			
		}
		std::cout<<"\n*";
	
	}
	
	return 0;

}

