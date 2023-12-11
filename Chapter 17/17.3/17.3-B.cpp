
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1;

	// 데이터가 없기 때문에 이렇게 접근하면 프로그램 강제 종료됨
	//v1[0] = 0;
	
	// 데이터가 비워 있는지 확인
	// 출력 No data !!!
	if (v1.empty())
	{
		std::cout <<"No data !!!\n";
	}
	
	std::vector<int> v2 = { 1,2,3,4,5 };
	for(int i=0 ; i < v2.size() ; i++)
	{
		std::cout << v2.at(i) <<" "; // 출력 1 2 3 4 5
	}

	// 데이터를 삭제함
	v2.clear();
	std::cout <<"size = "<< v2.size();

	// 데이터가 없기 때문에 접근하면 안됨
	//v2[0] = 0;

}
