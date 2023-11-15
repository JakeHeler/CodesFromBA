#include <iostream>
#include <string>
int main()
{
	std::string str;		 // 기본 생성자 : str1의 내용은 비어있음.
	std::string str1(str);		 // 복사 생성자 이용. 
	
	// 여러 괄호 또는 중괄호를 사용한 초기화 방식
	std::string str2 ("Strings Library");	 
	std::string str3 { "Strings Library" }; 
	
	// 변환 생성자가 사용됨. 대입형태의 초기화	
	std::string str4 = "Strings Library";	 

	// 문자열 중에서 설정 크기만큼의 값으로 초기화 
	std::string str5 ("Strings Library",8); 
	std::cout << str5;	 
	
	return 0;
}
