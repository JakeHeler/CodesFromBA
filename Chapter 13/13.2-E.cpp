#include <iostream>

struct A {
	A() { std::cout << "A ctor!\n";}
	~A() { std::cout << "A destructor!\n";}
};

struct B : A{
	B() {std::cout << "B ctor!\n";}
	~B() {std::cout << "B destructor!\n";}
};

int main()
{
	A* my = new B;	// 오버라이딩을 위해 자식에서 부모로 변환
	delete my;


	return 0;
}
