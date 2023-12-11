#include <iostream>
#include <list>

int main()
{ 
	std::list<int> li;
	for(int i =0; i <5; i++)
		li.push_back(i+1);
	
	for (const auto x: li)
		std::cout << x<< " ";	// 출력 1 2 3 4 5

	auto ir = li.begin();
	ir++;
	li.erase(++li.begin());

	auto ir1 = std::next(li.begin(), 3);
	li.erase(ir1);

	for (const auto x: li)
		std::cout << x<< " ";	// 출력 1 3 4

}
