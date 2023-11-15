#include <iostream>

template<class T> class A {
public:
	static T s_memeber;

};

// 템플릿 헤드가 먼저 선언되고 static 멤버 초기화
template<class T> T A<T>::s_memeber = 1;

int main()
{

	A<int> a;
	a.s_memeber = 10;

	A<double> d;
	d.s_memeber = 100;

	A<int> b;


	std::cout << b.s_memeber<<"\n";

	std::cout << A<double>::s_memeber ;

	return 0;
}
