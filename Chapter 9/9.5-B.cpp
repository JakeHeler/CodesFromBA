#include <iostream>

void func(int my)
{ 
    	{ 
			int nested=0;
		}

		int a = 1, b = 1;

		// = 값 캡처: 모든 로컬변수 읽기 접근 가능. 다른 블록에 있는 nested 변수는 안 됨. 
    	[=] {   int lm = my + a; }();	

		// & 참조 캡처: 모든 로컬변수 읽기 쓰기 가능. 수식 이후에 변경된 값이 유지됨.
    	[&]() {  a=10, b=10; int lm = my + b; }();	


    	[a]() mutable {  a = 200; int var = a; }();	

		// a: 읽기 허용 b: 읽기, 쓰기 가능
    	[a,&b]() { int i= a ; b=100; }();

		// 여기에서 a 값은 10으로 유지됨. 각각의 변수 캡처 리스트를 하게 됨. 변경 가능하고
		// 람다 함수 실행 이후 변경된 값이 유지됨. &변수 이것이 우선. mutable 기능은 사라짐.
    	[&a, &b, &my]() mutable {  a = 100, b = 100; my = 100; }();

    	std::cout << a << b << my;	
}

int main()
{
	func(0);
}
