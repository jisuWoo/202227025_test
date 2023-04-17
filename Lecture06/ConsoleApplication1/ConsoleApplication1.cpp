#include <iostream>

using namespace std; // std를 네임스페이스로 지정

class Cat 
{
public:
    Cat() 
    {
        cout << "Cat : meoooooowong(Birth)" << endl;
    }
    ~Cat() 
    {
        cout << "Cat : Kaaawhaong(Death)" << endl;
    }
    //생성자

    void Meow()
    {
        cout << "Cat : MeowMeowMeowMeowMeowMeowMeow" << endl;
    }

};



int main()
{
    cout << "냐옹앱 시작" << endl;
    cout << endl;
    Cat c;
    c.Meow();
    //객체 생성
    //실행
    //그 후 소멸...
}
