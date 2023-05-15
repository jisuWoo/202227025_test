#include <iostream>

namespace MuSoeun
{
	//뱀게임이랑 연동 esc 누를 시 게임 화면 꺼지고,그 화면 바뀌기는 걸는 걸 이 아래 객체 구조화 시켜서 진행! 
	//내가 원하는 뱀게임을 위한 게임엔진구조를 짜주기 참고 자료 - 게임엔진 아키텍처
	class Scene // 벡터에 오브젝트가 들어감 오브켁드에 컴포넌트에 실행할 게 있으면 실행
	{
		//뷰포트의 width, height를 저장함
	public:
		int width;
		int height;
		//std::vector<Object> objList;

		//screenBuf[width + (width * height)];

		char* screenBuf;

		void InitScreenBuf() 
		{
			screenBuf = new char[(width + 1) * height + 5];

			for (int i; i < height; i++) {
				screenBuf[(width + 1) + (width + 1) * i - 1] = '\n';
			}
		}

		
		
	};

	class Object //render 구현
	{

		//SetActive가 있음
	};

	class Component // monobehavior 있으면 실행
	{

		void Start(); //SetActive가 나왔을 때 한번만
		void Update(); //SetActive가 비활성화시 실행 x 

	};


}


int main()
{
    
    

}
