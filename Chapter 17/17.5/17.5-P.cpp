#include <iostream>
#include <ranges>
#include <vector>
#include <map>

using namespace std::views;
using namespace std::ranges;

int main()
{
  	std::pair<int, int> pr[] = {{1,2},{3,4},{5,6}}; 
	
	// view 타입으로 변경함   
	using R = decltype(pr | all);

   	elements_view< R,0 > ev(pr);

   	for (auto i : ev)
       		std::cout << i << " "; // 출력 1 3 5
    std::cout <<"\n";

   	std::map<std::string, int> info = { { "1Lee",20 },{ "2Kim",30 },{ "3Hong",40 } };
	

    auto ev0 =  info | elements<0>;
    for (auto i : ev0)
       		std::cout << i << " "; // 출력 1Lee 2Kim 3Hong
    std::cout <<"\n";

    auto ev1 = info | values;
    for (auto i : ev1)
    	std::cout << i << " "; // 출력 20 30 40

	return 0;
}
