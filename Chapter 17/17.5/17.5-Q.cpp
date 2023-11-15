#include <iostream>
#include <ranges>
#include <vector>

using namespace std::views;
using namespace std::ranges;

// vector 데이터 요소의 처리를 직접 구현함
void view_test(std::vector<int> v )
{
	// filter 기능
	for(int i=0 ; i < v.size() ; i++)
    {
            
		for(;;)
       	{
           		if (v[i] % 2 == 0)
                   		break;
               		i++;

           		if (i >= v.size())
                   		return;
    
       	}

       	// transform 기능
       	auto tr = v[i] * v[i];
       	std::cout << tr<<" ";
      
    }  

}

int main()
{
       	std::vector<int> v =  { 1, 2, 3, 4, 5 };


	    view_test(v);
	
       	auto even = [](int i) { return i % 2 == 0; };
        auto square = [](int i) { return i * i; };

       	for (auto i : v | filter(even) | transform(square))
           	std::cout << i << " "; 

	    return 0;
}
