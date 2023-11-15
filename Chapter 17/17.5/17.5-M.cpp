#include <iostream>
#include <ranges>
#include <vector>

using namespace std::views;
using namespace std::ranges;
int main()
{
	std::vector<int> v =  { 1, 2, 3, 4, 5 };
	for (int i : drop_view(v,3))
    	{
        		std::cout << i << " ";	
    	}

    auto special_ch = [](char c) { 	return c == ' ' || c == '\t' || c == '\n'; };


    std::string str = "\t   \n  Test Drop While";
    for (auto i : drop_while_view(str,special_ch))
    {
        		std::cout << i ; 
    }
	
    return 0;
} 
