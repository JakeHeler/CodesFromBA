#include <iostream>
#include <vector>

int main()
{
	std::vector<int> my;

	for (int Index = 0; Index < 10; Index++)
	{
                 		std::cout<<"Index= "<<Index<<" capacity= "<<my.capacity()<<"\n";
                 		my.push_back(1);
	}
	return 0; 
}
