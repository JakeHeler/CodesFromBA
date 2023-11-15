#include <iostream>
#include <string>

int main()
{
	std::string str ="Strings Class";
	str[7] = '@';


	std::cout << str<<"\n";	 

	std::cout << "str.at(0) = " <<str.at(0) << "\n";

	unsigned int size = str.size();
	// 예외 발생. 문자열 크기 size() 와 같거나 크기 때문에 발생
	//str.at( size );


	return 0;
}
