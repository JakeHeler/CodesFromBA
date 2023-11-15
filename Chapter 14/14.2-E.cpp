#include <iostream>

struct Comp {
	int x;
	int y;
	// 파라미터 : const 참조형 타입이어야 하고 함수 뒤에 const을 지정해야함 
	auto operator<=>(const Comp& x) const = default;


	bool operator<(const Comp& x) const = default;
};

int main()
{
	Comp c1{ 0,1 }, c2{ 1,1 };

	if (c1 < c2)
		std::cout << " C2 greater";	
	else if (c1 > c2)  {}
	else if (c1 == c2) {}
	else if (c1 >= c2) {}
	else if (c1 <= c2) {}
	else if (c1 != c2) {}

	return 0;
}
