#include <iostream>

struct A {
	A() { std::cout << "A ctor!\n"; }
	A(int) {}
};

struct S {
	S() { std::cout << "S ctor!\n"; }
};

// 부모 클래스 A 상속
struct B : A {
	S s;	// 데이터 멤버
	B() { std::cout << "B ctor!\n"; }
	B(int v) : A(v) {}	// 부모 클래스 초기화 리스트에서 생성

	// 부모 클래스 초기화가 된 후 B 클래스가 생성됨. 함수 f()의 반환값은 정의되지 않음. 
	B(char v) : A(f()) {}	
	char f() { return -1; }
};

int main()
{
	B b;
}
