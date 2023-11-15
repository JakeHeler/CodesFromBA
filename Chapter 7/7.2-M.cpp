#include <iostream>
const char* kor[] =
{
    	/* index */ /*string*/
    	/* 0 */ "안녕",
    	/* 1 */ "좋은 아침",
    	/* 2 */ "잘 가",
};

const char* eng[] =
{
    	/* index */ /*string*/
    	/* 0 */ "Hi",
    	/* 1 */ "Good Morning",
    	/* 2 */ "Good Bye",
};

// 선택된 언어의 포인터를 저장하는 이중 포인터
const char** language;

void DefaultLangauge()
{
    	language = kor;
}

int main()
{
    	DefaultLangauge();

        std::cout << language[0]<<"\n";
        std::cout << language[1];	
	return 0; 
}
