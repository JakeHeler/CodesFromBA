#include <iostream>

struct A{
	A() {};
};

int main()
{
	// 기본 타입 int 의 메모리 할당 및 초기화식 사용 
	auto ptr1 = new int;		// new int () : 괄호를 비우게 되면 0 으로 초기화
	auto ptr2 = new int (10);	// new int {10} :중괄호를 사용해도 결과는 같음

	// 배열로 int 타입 할당
	int* ptr3 = new int [10];

	// 클래스 타입에 대해 메모리 할당.
	A* ps = new A;

	return 0;
}
