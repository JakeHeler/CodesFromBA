#include <iostream>
#include <string>

const int SIZE_MYSTRING = 100;

int main()
{
	std::string str;

	// 문자열 메모리 설정 크기를 변경
	if( str.capacity() < SIZE_MYSTRING)
		str.reserve(SIZE_MYSTRING);

	str="Functions of strings class";

	std::cout << str.size() << "\n";	


	std::cout << "Before fit = "<< str.capacity()<<"\n";	
	

	str.shrink_to_fit();


	std::cout <<"After fit = "<<  str.capacity()<<"\n";	


	return 0;
}
