#include <iostream>
#include <string>

int main()
{
	
	std::string str1("String") , str2="Class";

	// 하기는 문자열 삽입 및 대입
	str1 += str2;
	std::cout << str1<< "\n";	

	str1 += "Operation";
	std::cout << str1<< "\n";	

	// 문자열 할당. assign() 함수와 동일
	str1 = "Strings STL";
	std::cout << str1<< "\n";	

	str1.assign("string assign");	
	std::cout << str1<< "\n";	

	// 문자열 중에서 할당할 위치와 개수를 설정 
	str1.assign("acdefghi",2,4);
	std::cout << str1<< "\n";	

	str1.assign(5,'#');
	std::cout << str1<< "\n";	

	return 0;
}
