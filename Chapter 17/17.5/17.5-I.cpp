#include <iostream>
#include <ranges>
#include <vector>

// 람다 함수
auto even = [] (int i) { return i%2==0;  };

int main()
{  
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };


    std::ranges::filter_view fv(v, even);  
	std::views::filter(v, even);


   	std::views::filter(even)(v);	


	for (auto n : v | std::views::filter(even) )
       		std::cout << n << " "; 
	std::cout << "\n";
  	
	auto check_no = [] (int i) { return i >= 1; };
	int x[] = {0,1,2,3,4,5};
	

	auto v1 = std::views::filter(check_no);
  	auto v2 = std::views::filter(even);
  	auto v12 = x | v1 | v2 ;
    
	for (auto i : v12)
    		std::cout << i << " "; 
	return 0;
}
