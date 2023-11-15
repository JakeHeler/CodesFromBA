#include <iostream>
#include <ranges>
#include <vector>

using namespace std::views;
using namespace std::ranges;

int main()
{
    int two_array[3][2]={{1,2},{3,4},{5,6}};
 	std::vector<std::string> ss{"This", " ", "is ", "join view", ":","test !"};
   
    auto jv = join_view(two_array);
    for (auto i : jv)
         std::cout << i << " ";	// 출력 1 2 3 4 5 6
  	std::cout << "\n";

    auto jv1 = join_view(ss);
    for (auto i : jv1)
	    std::cout << i; // 출력 This is join view : test !
  	std::cout << "\n";

  	int three_array[2][3][2] = { 
		{{1,2},{3,4},{5,6}},{{7,8},{9,10},{11,12}} };

	
   	auto jv2 = three_array | views::join |views::join;
   	for (auto i : jv2)
   		std::cout << i<<" "; // 출력 1 2 3 4 5 6 7 8 9 10 11 12
    
 	return 0;
} 
