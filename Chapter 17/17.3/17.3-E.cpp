#include <iostream>
#include <list>

int main()
{ 
	std::list<int> li;
	for(int i =0; i <5; i++)
		li.push_back(i);
	
	for (const auto x: li)
		std::cout << x<< " ";	// 출력 1 2 3 4 5

	auto ir = li.begin();
	ir++;
	li.insert(ir , 10);

	// 반복자 STL의 함수를 이용해 위치를 설정
	auto ir1 = std::next(li.begin(), 3);
	li.insert(ir1 , 50);

	for (const auto x: li)
		std::cout << x<< " ";	// 출력 1 10 2 50 3 4 5
}
