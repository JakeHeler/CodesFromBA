#include <iostream>
struct Point
{
	int x;
	int y;
};

struct A
{
	int x;
};

int main()
{
	int a{};	
	std::cout << "a = " << a << "\n";	

	A x{};	


	std::cout << " Class A member x= "<< x.x <<"\n";	

	// 하기는 초기화가 아니라 함수 선언으로 인식됨. 괄호안에 반드시 수식이 있어야함
	int b();
	Point p();

	b = 10;	// 에러 발생. 


	int c = int();
	

	Point p1 = Point();
	std::cout << "p1.x = "<<p1.x << "\n" ;	
	return 0;
}
