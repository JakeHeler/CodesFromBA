#include <iostream>
#include <vector>

struct A { 
	A() {std::cout << "A constructor\n";}
};

int main()
{
	// int 타입으로 벡터 생성. 
	// 출력 size = 0
	std::vector<int> v1;
	std::cout <<"size = "<< v1.size()<<"\n";

	// 클래스 타입으로 데이터 크기를 설정하고 벡터 생성
	// A constructor : 5 번 출력됨
	// 출력 size = 5 
	std::vector<A> v2(5);
	std::cout <<"size = "<< v2.size()<<"\n";

	// 데이터 크기 및 초기값 설정
	// 출력 size = 10 
	std::vector<int> v3(10,0);
	std::cout <<"size = "<< v3.size()<<"\n";

	// 배열 형태의 초기화
	std::vector<int> v4 = { 1,2,3,4,5 };
	
	for(int i=0 ; i < v4.size() ; i++)
	{
		std::cout << v4.at(i) <<" "; // 출력 1 2 3 4 5
	}

	// 첨자 방식으로 값을 데이터에 대입
	v4[0] = 10;
	v4[1] = 20;

	// 첨자 방식으로 값을 가져옴
	for(int i=0 ; i < v4.size() ; i++)
	{
		std::cout << v4[i] <<" "; // 출력 10 20 3 4 5
	}
}
