#include <iostream>

struct My {};

template<typename T = int> struct A {};
template<> struct A<double> {}; 	// 특수화 T = double
template<> struct A<> {};	// 특수화 T = int. 기본값 인자가 있으면 빈 꺽쇠 가능

// 원본 클래스 템플릿(primary class template)
template<typename T> struct Member {
	void CheckID() { std::cout << "Primary Class\n"; }
	void Load() { /*...*/}
};

// 특수화 클래스 템플릿 선언. template<> 사용해야 함
template<> struct Member<My>
{
	void CheckID();
};

// 특수화 템플릿에서 멤버 함수 구현 시 template <> 사용하지 않음. 만약에 선언하면 에러가 발생함.
void  Member<My>::CheckID() { std::cout << "Specialization Class\n";}

int main()
{
	Member<int> m1;
	m1.CheckID();	

	Member<My> m2;
	m2.CheckID(); 
	
	// 에러 발생. 해당 함수를 특수화 클래스 템플릿에서 정의해야 함.
	//m2.Load(); 
	return 0;
}
