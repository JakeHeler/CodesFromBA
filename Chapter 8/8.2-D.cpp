#include <iostream>

struct Member{
	int age;
	bool man;
	
	// C++11 까지 
	// 어떤 데이터 멤버라도 초기화를 하게 되면 아래의 중괄호 초기화 방식에 에러가 발생 
     
	// C++14 이후
	// 멤버 초기화를 하여도 아래의 중괄호 초기화 방식이 가능함.
	int phone=0;
	
	// 일반 함수
	void f();
};
int main()
{
	// 중괄호 초기화 방식
	// 클래스 초기화 m.age= 30 , m.man = true , m.phone = 123456
	Member m = {30, true, 123456};
	
	// 멤버 age = 30 설정, 나머지는 0 의 값을 가짐
	Member m1 = {30};

	// since C++20 
	// 멤버 지정화를 통한 초기화. 이때 선언된 멤버 순서 되로 진행해야 함.
	// 대입을 통해서도 가능하고 중괄호도 가능. [ex] . age {30}
	Member m2 = {.age= 30, .man= true, .phone=123456};

	// 순서대로 초기화가 되어야 함.
	// Member m2 = {.man= true, .age= 30, .phone=123456};

	// 지정 초기화와 일반 중괄호 초기화가 혼합 되서는 안 됨
	// Member m2= {.age= 30, .man= true, 123456};
	return 0;
}
