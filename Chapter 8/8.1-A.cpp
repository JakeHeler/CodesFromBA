#include <iostream>
struct Point
{
	int x;
	int y;
};

int a;	// 전역변수 0 으로 초기화됨.

int main()
{
	int b;	// 임의의 값을 가짐.

	std::cout << "a = "<<a ;

	
	Point p;	// 기본 생성자가 호출됨.
	
	return 0;
}
