#include <ranges>
#include <vector>

int main()
{ 
    std::vector<int> v = {10, 4, 5, 6, 7, 8, 9};
    // vector 타입 데이터
    std::ranges::single_view sv1 (v);
	
	
    std::ranges::single_view sv2 (0);

	return 0;
}
