#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    	int var = 0;
    	int ar[]={ 1, 2, 3, 4 };
       	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    	std::ranges::iota_view io(var,10);
	

    	for (auto i : io)
        		std::cout << io[i]<<" ";	
	    std::cout<<"\n";


    	std::ranges::iota_view io_ar(ar, ar+4);

        	for (int i=0 ; i < io_ar.size();i++)
            	std::cout << *io_ar[i]<<" "; 
	    std::cout<<"\n";

    	std::ranges::iota_view io_vec(v.begin(), v.begin()+3);

        for (int i=0 ; i < io_vec.size();i++)
            	std::cout << *io_vec[i]<<" "; 
	    std::cout<<"\n";


	    auto iota=  std::views::iota(var,10);
	    for (auto i : iota)
        		std::cout << iota[i]<<" ";	

	return 0;
} 
