#include <iostream>
struct A{
	A() {};
};
int main()
{  
     	// new 와 delete 는 항상 쌍으로 움직여야 함.
	auto pi = new int;
     	delete pi;

	// 배열로 할당하면 항상 배열관련 delete [] 사용
     	auto pa = new int [10];
     	delete[] pa;
	// 클래스를 생성하고 클래스 해제 시 소멸자가 호출됨
     	auto pr = new A;
     	delete pr;	

	return 0;
}
