#include <iostream>

void GetDataFromNetwork(void (*pf)(char *data))
{
        auto p = new char[10];
        pf(p);
}

void MyCallback(char *data)
{
    	std::cout << "MyCallback function\n";
}

int main()
{
    	// 일반 함수를 콜백 함수로 사용 
	    GetDataFromNetwork( MyCallback);		

	    // 람다 함수 사용. 주의사항 : 반드시 람다지정자가 비워 있어야 됨.
    	auto lm = [](char* data) {  std::cout << "Lambda Callback \n";  };
       	GetDataFromNetwork( lm );	// 출력 Lambda Callback

    	auto lm_cap = [&](char* data) {  std::cout << "Lambda Capture Callback \n";};
	    
        // 에러 발생 : 람다 함수가 캡처를 가지고 있음
        GetDataFromNetwork(lm_cap);

	return 0;
}
