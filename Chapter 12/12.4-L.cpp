#include <iostream>

class A{
public :
	A() { std::cout << "class A\n"; }
};

class B{
public :
	B() { std::cout << "class B\n"; }
};

class C : public A, public B
{
public :

	int m1 = 0;
	int m2 = 0;

	C() : m2(m1), m1(10), B(), A() {}


};

int main()
{
	C c;	
	std::cout << "m1 value =" << c.m1; 
}
