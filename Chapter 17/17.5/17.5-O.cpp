#include <iostream>
#include <ranges>
#include <vector>

using namespace std::views;
using namespace std::ranges;

int main()
{
    std::string member_info = "Jake;1234;Seoul";
    split_view sv(member_info, ';');

    std::vector<std::string> splited_str;

	for (auto member : sv) 
    {
           	std::string str = "";
           	for (auto ch : member)
           	{
               		str.push_back(ch);
           	}
           	splited_str.push_back(str);
    }
         

	std::cout << "Name :" << splited_str[0]<<"\n";
    std::cout << "No :" << splited_str[1]<<"\n";
    std::cout << "Local :" << splited_str[2]<<"\n";
 	
	return 0;
} 
