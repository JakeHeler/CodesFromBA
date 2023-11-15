#include <iostream>
#include <ranges>
#include <vector>

using namespace std::views;
using namespace std::ranges;

int main()
{
    std::vector<int> v =  { 1, 2, 3, 4, 5 };
	auto multiply_five = [] (int i) { return i * 5; };

	for (int i : v |  transform(multiply_five) | take(3))
         	std::cout << i << " "; 
	return 0;

}
