#include <iostream>
#include <ranges>
#include <vector>

// 일반 함수
auto odd(int i)
{ 
    return i%2==1; 
}

// 람다 함수
auto even = [] (int i) { return i%2==0;  };

int main()
{  
   	int ar[]={ 1, 2, 3, 4 };
   	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

   	std::ranges::filter_view fv(ar, odd);  

	std::cout << *fv.begin()<<"\n";	 

	int ar1[]={ 10, 20, 30, 40}; 	
	std::ranges::filter_view fv1(ar1, odd);  

    if( !fv1.empty())
	    std::cout << *fv1.begin()<<"\n";

     	
	std::ranges::filter_view fv2(v, even);  
   	for (auto n : fv2)
       		std::cout << n << " "; 
	return 0;
}
