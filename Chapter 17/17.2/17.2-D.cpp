#include <iostream>
#include <string>

int main()
{
	std::string str ="Functions of strings class";

	std::cout << str.size()<<"\n";			

	// 문자열을 일정 크기로 변경. 기본 문자열 마지막에 \0 문자 삽입
	str.resize(64, '\0');
	std::cout <<"After Size = "<<  str.size() <<"\n";	

	str.clear();
	std::cout <<"Clear() = "<<  str.size() <<"\n";	
	
	return 0;
}
