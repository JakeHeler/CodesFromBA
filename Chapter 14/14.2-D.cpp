#include <iostream>
#include <cmath>

class Point
{
public:
    	int _x;
    	int _y;

	Point(float x, float y) { _x = x; _y = y; }
	
	// < 연산자 오버로딩
	bool operator< (Point p) 
	{
		double my = _x * _x + _y * _y;
		double other = p._x * p._x + p._y *p. _y;
		return std::sqrt(my) < std::sqrt(other); 
	};

	bool operator> (Point p) 
	{
		double my = _x * _x + _y * _y;
		double other = p._x * p._x + p._y *p. _y;
		return std::sqrt(my) > std::sqrt(other); 
	};
	// int 파라미터의 연산자 오버로딩
	bool operator> (int c) { return _x > c; }
};

int main()
{
	Point p(1, 1), p1(1, 2);
	bool r1 = p > p1;	
	bool r2 = p > 10;	
}


