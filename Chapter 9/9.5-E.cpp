#include <iostream>
#include <functional>

void GetDataFromNetwork( std::function<void (char *data)> pf)
{
        auto p = new char[10];
        pf(p);
}
void MyCallback(char *data)
{
    	std::cout << "MyCallback function\n";
}
void (*pfn)(char*);
int main()
{
    	// 일반 함수를 콜백 함수로 사용 
		GetDataFromNetwork( MyCallback);	

	// 람다 함수를 콜백 함수로 사용
    	auto lm_cap = [&](char* data) {  std::cout << "Lambda Capture Callback \n";};
        GetDataFromNetwork(lm_cap);	

	// 함수 포인터를 이용하여 콜백 함수로 사용
		pfn = MyCallback;
		GetDataFromNetwork(pfn);

	return 0;
}
