#include <iostream>
#include <ranges>
#include <vector>

using namespace std::views;
using namespace std::ranges;

int main()
{
    std::vector<int> v =  { 1, 2, 3, 4, 5 };
	auto check_size = [] (int i) { return i < 5; };
	
    auto tv = take_while_view(v, check_size);
    
	for (int i : tv)
    	{
        		std::cout << i << " "; 
    	}
	std::cout << "\n";

	std::string str = "Live Today as if it was the last day ...";
	auto search_dot = [] (char c) { return c != '.'; };

	
	auto tv1 = take_while_view(str, search_dot);
	for (char i : tv1)
    {
       		std::cout << i ; 
    }

	return 0;
} 
