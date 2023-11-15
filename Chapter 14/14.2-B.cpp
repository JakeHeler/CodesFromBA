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
		return Point(_x+a._x, _y +a._y); 
	};

};

int main()
{
	Point a(1, 1), b(2, 2);
	Point c = a + b ; 	// 여기서 a.operator+(b) 형태로 호출됨
	std::cout <<"c._x = " << c._x << " c._y = " << c._y;	

}

