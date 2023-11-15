#include <iostream>

class Point
{
public:
	int _x;
	int _y;

	Point(float x, float y) { _x = x; _y = y; }

	// 덧셈 산술 연산자 오버로딩
	Point operator+ (Point a)
	{
		return Point(_x + a._x, _y + a._y);
	};

	// 일정 값을 더하는 산술 연산자 오버로딩
	Point operator+ (int v)
	{
		return Point(_x + v, _y + v);
	}
};


/* // 포인트　클래스에 일정　값을 더하는 전역 함수
Point operator+ (Point a, int b) 
{
	return Point(a._x+b , a._y +b); 
};
*/

int main()
{
	Point a(1, 1);
	Point b = a + 10;	

	std::cout <<"b._x = " << b._x << " b._y = " << b._y;

}

