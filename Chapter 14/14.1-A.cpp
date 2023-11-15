#include <iostream>

class Point
{
public:
    	int _x;
    	int _y;

		Point(float x, float y) { _x = x; _y = y; }
	
	// 마이너스 연산자 오버로딩 구현
	Point operator- () 
	{
		_x = -_x;
		_y = -_y; 

		return Point(_x,_y); 
	};

};

int main()
{
	Point a(1, 1), b(1,1);
	
	// Point 클래스의 연산자 오버로딩된 멤버함수가 호출됨
	// 변수 a 는 클래스 타입이기 때문에 클래스의 연산자 함수를 찾아 맞는 함수가 호출됨
	b = -a;
	std::cout <<"b._x = " << b._x << " b._y = " << b._y;
	return 0;
}
