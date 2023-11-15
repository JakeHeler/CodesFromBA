#include <iostream>

struct A{
	A() {};
};

// 테스트용으로 new 연산자 함수를 구현함.
void*  operator new(size_t _Size,  int, int) noexcept
{
        return (void*)0;
}

int main()
{  
	size_t size = sizeof (A);

	// new 연산자 오버로딩 함수를 직접 호출. 이 함수는 한 개의 인자를 가짐.
	// 함수 원형 : void* operator new( size_t Size )
	// A 클래스 타입 크기를 인자로 넘김.
	auto ptr = ::operator new (size);

	// 메모리가 할당되어 해당 클래스 생성자가 호출되게 함
	// 아래의 new 수식은 void* operator new(size_t size, void* ptr) 이 함수가 
         // 호출되고 추가 인자가 해당 함수로 전달됨.
	// 이 함수는 별도로 메모리를 할당하지 않고 전달받은 포인터를 다시 반환하도록 구현됨
	new (ptr) A;

	// 추가 인자와 부합하는 위에서 만든 new 연산자 함수가 호출됨.
	new ( 1 , 2) A;

	return 0;
}
