#include <iostream>
#include <ranges>
#include <vector>
#include <chrono>

using namespace std::views;
using namespace std::ranges;

inline constexpr bool even( int i) 
{ 
           return true; 
}
inline constexpr auto square( int i) 
{ 
           return i * i ;
}

int main()
{ 
	    std::vector<int> v;
	    for (int i = 0; i < 100000; i++)
   		    v.push_back(i);
      	
        std::vector<int> result;
	
	    auto start = std::chrono::steady_clock::now();
    
	    auto ir_start = v.begin();
       	auto ir_end = v.end();
    
        for ( auto it = ir_start; it != ir_end; it++)
       	{
          	for (;;)
           	{
               		if (even(*it))
                   		 break;
               		it++;
               		if (it >= ir_end)
                   		goto finish;
           	}

        		result.push_back(square(*it));
       	}
 
finish:
	    auto end = std::chrono::steady_clock::now();
	    std::chrono::duration<double> elapsed_seconds = end-start;
    	std::cout <<"General Elapsed time: "<<elapsed_seconds.count() << "s\n";
	
	    // 어댑터 설정
    	auto p = v | filter(even) | std::views::transform(square);
    	std::vector<int> view_result;

    	start = std::chrono::steady_clock::now();
        	for(auto i : p)
       	{
		    view_result.push_back(i);
       	}
    	end = std::chrono::steady_clock::now();
	    elapsed_seconds = end-start;
    	std::cout<<"Adaptors Elapsed time: "<<elapsed_seconds.count() << "s\n";

	return 0;
}
