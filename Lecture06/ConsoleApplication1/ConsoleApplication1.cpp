#include <iostream>

using namespace std; // std를 네임스페이스로 지정

class Animal {
public:
    Animal() {
        cout << "Animal : animal !!!" << endl;
    }
    virtual  ~Animal() {
        cout << "Animal : dying" << endl;
    }
    virtual void Talk()
    {
        cout << "Animal : talktalk" << endl;
    }

};


class Hamster :public Animal
{
public:
    Hamster() {
        cout << "햄스터: 찍/탄생" << endl;
    }
    ~Hamster() {
        cout << "햄스터: 히이익/죽음" << endl;
    }
     void Talk()
    {
        cout << "햄스터: 찍찍짝" << endl;
    }
};

class Cat: public Animal
{
public:
    Cat() 
    {
        cout << "Cat : 야옹(Birth)" << endl;
    }
    ~Cat() 
    {
        cout << "Cat : 끄아옹(Death)" << endl;
    }
    //생성자

    void Talk()
    {
        cout << "Cat : 냥냥냥냥냥" << endl;
    }



};

class Tiger :public Animal
{
public:
    Tiger() {
        cout << "Tiger : 크아앙(탄생)" << endl;
    }
    ~Tiger() {
        cout << "Tiger : 끄아악(죽음)" << endl;
    }

    void Talk()
    {
        cout << "Tiger : 암튼 호랑이 울음소리" << endl;
    }

};



    //메모리는 스택 구조
    //그래서 스택으로 짜는 게 안전
    //마지막 부터 소멸.. 그래서 소멸자가 실행되고 그이후로 쭉...
    //정적할당

    //동적할당
    //내가 원하는 대로 메모리 할당
    //하지만... 지우는 것도 내가 선택과 집중
    //이걸 힙이라 함--
    //제대로 못하면 메모리누수남 
    //메모리 침범도 있음!!!

    //클래스 -> 주소값의 개념과 일맥 상통
    //객체는 참조로 !!

    


int main()
{
    cout << "냐옹앱 시작" << endl;
    cout << endl;
    //Cat c;
    //c.Meow();

    //Tiger *c = new Tiger();
    //Cat *c = new Tiger();
    //Tiger* t = (Tiger*)c;
    //t->Meow();
    //c->~Cat();
    //t->Roar();
    //delete(t);

    int AnimalNum = 3;
    Animal** ani = new Animal * [AnimalNum];

    ani[0] = new Tiger();
    ani[1] = new Cat();
    ani[2] = new Hamster();

    for (size_t i = 0; i < AnimalNum; i++) {
        ani[i] -> Talk();
        delete(ani[i]);
    }


    //객체 생성
    //실행
    //그 후 소멸...
}
