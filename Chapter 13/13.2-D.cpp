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
	{
		B b;
	}
		std::cout<<"\n!!! new B \n";

	// 출력 : 아래와 동일함
	B* my = new B;
	delete my;

	return 0;
}
