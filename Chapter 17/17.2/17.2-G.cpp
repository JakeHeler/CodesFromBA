#include <iostream>
#include <string>

int main()
{
	std::string str1("String") , str2="Class";
	
	// str1 += str2 와 동일함.
	str1.append(str2);
	std::cout << str1 <<"\n";	 

	// 문자열 일부만 추가함.
	str1.append("12345", 3);
	std::cout << str1 <<"\n";	
	str1 = "String";
	unsigned int size = str1.size();

	// str1.append(str2) 와 동일
	str1.insert(size, str2);
	std::cout << str1 <<"\n";	

	// 추가할 문자열의 위치를 설정함.
	str1.insert(0, "STL_");
	std::cout << str1 <<"\n";	 

	
	return 0;
}
