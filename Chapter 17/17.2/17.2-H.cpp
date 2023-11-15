#include <iostream>
#include <string>

int main()
{
	std::string str ="01234567890123456789";	

    	std::cout<<" search = "<<str.find("9")<<"\n";		// 출력 9
   	std::cout<<" search = "<<str.rfind("9")<<"\n";		// 출력 19
	std::cout<<" search = "<<str.find_first_of("abc0")<<"\n";	// 출력 0
	std::cout<<" search = "<<str.find_last_of("abc0");		// 출력 10

	return 0;
}
