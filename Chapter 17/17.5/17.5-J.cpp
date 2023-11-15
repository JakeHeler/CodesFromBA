#include <iostream>
#include <ranges>
#include <vector>

using namespace std::views;
using namespace std::ranges;

int main()
{
    std::vector<int> v =  { 1, 2, 3, 4, 5 };
	
	auto multiply_five = [] (int i) { return i * 5; };
	transform_view tv(v, multiply_five);
	

	std::cout << tv[2] << "\n";  	
    	
	
	for (int i : tv)
       		std::cout << i << " "; 	
	std::cout << "\n";

	
    transform(v, multiply_five);

    auto square = [] (int i) { return i * i; };
	for (int i : v |  transform(multiply_five) | transform(square))
         	std::cout << i << " "; 		

	return 0;

}
