#include <iostream>
#include <cstring>

// std::string 을 가지는 헤더파일
#include <string>

// MSVC에서 문자열 함수 사용 시 경고가 발생하여 해당 경고를 막음
#pragma warning(disable: 4996)

char* GeTFileName() { return (char*) "picture.bmp"; }
char* GeTDate() { return (char*) "12_25"; }

int main()
{
	char *FilenName = GeTFileName();
	char *Date = GeTDate();

	char NewFileName[50];

	// C 언어에서 제공하는 함수를 통해 문자열을 복사하고 삽입하는 과정
	strcpy(NewFileName, Date);
	strcat(NewFileName, "_");
	strcat(NewFileName, FilenName);

	std::cout << NewFileName<<"\n"; 


	// string 문자열 클래스를 이용
	std::string filename = GeTFileName();
	std::string date = GeTDate();

	std::string newfilename = date + "_" + filename;
	
	std::cout << newfilename; 	 

	return 0;
}
