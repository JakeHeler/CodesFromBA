#include <iostream>
#include <compare>

int main()
{
	int a = 1;
	int b = 1;
	auto mm = a <=> b;

	if(mm == 0)
		std::cout << "a equal b\n";	// 출력 a equal b
	else if(mm < 0)
		std::cout << "a less than b\n";
	else if(mm > 0)
		std::cout << "a greater than b\n";
	return 0;
}
