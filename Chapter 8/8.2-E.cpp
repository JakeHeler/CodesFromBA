#include <iostream>

struct Member{
	int age;
	bool man;
	int phone;
	
	// 일반 함수. 생성자 함수를 만들게 되면 중괄호 초기화가 되지 않음.
	void f();
};
int main()
{
	// since C++20 
	// 배열 및 구조체 형태의 클래스 :　괄호 방식의 초기화
	int a[5] ( 1,2,3,4,5 );	
	int b[5] ( 1,2 );

	for (int i=0; i < 5; i++) 
	{
      	 	std::cout << b[i] << " ";		
    	}
	
	Member m (30,true,123456);

	Member m1 (30);

	return 0;
}
