#include <vector>
#include <iostream>
#include <list>
#include <iterator>

int main()
{
    	std::vector<int> ve = { 1,2,3,4,5};
	auto ir_ve = ve.begin();

	std::advance(ir_ve, 3);
	std::cout << *ir_ve<<"\n" ;	// 출력 4

	// 함수 인자에 being()의 반환값을 바로 인자로 사용하지 않음
	// std::advance(ve.begin(),3);
	
	std::list<int> li = { 10,20,30,40,50};
	auto ir_li = li.begin();
	
	std::advance(ir_li, 3);
  	std::cout << *ir_li <<"\n";	// 출력 40

	auto ir_end = ve.end();
	std::advance(ir_end, -3);
	std::cout << *ir_end ;	// 출력 3	
}
