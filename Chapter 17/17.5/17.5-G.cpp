#include <ranges>
#include <vector>

int main()
{  
    	int ar[]={ 1, 2, 3, 4 };
  	    std::string str = "Hello";
    	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    	std::ranges::ref_view ref1(ar);
    	std::ranges::ref_view ref2(str);
    	std::ranges::ref_view ref3(v);

	// 아래는 ref3 와 같음.
    	std::views::all(v);

	return 0;
}
