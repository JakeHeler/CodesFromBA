#include <iostream>

void func(void)
{
    	int a = 1, b = 1;

	    // 로컬변수 a, b 를 캡처하어 람다 함수의 본체에서 사용함
    	[a , b]() {   int myid = a+b;  myid++; }();
	
	    // 람다 함수에서만 사용하도록 별도의 변수를 생성함.
	    // 캡처 내용 : int id = a+b; 와 같음. 변수 id 는 람다 함수에 사용됨.
    	[id = a + b]() {   int myid = id;  myid++; }();
    
    	// 로컬변수에 대해 별도의 참조형 타입으로 변수 생성함.

       	[&ref = a] {   int myid = ref;  ref = 123; }();

    	std::cout << a;	
}

int main()
{
	func();
}
