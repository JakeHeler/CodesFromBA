#include <iostream>
#include <vector>

struct A
{
	A() {}
};

int main()
{
      	A a;
	std::vector<A> my;
	
	// 메모리를 일정 크기만큼 미리 할당함
	my.reserve(20);

	for (int Index = 0; Index < 10; Index++)
	{
		std::cout<<"Index= "<<Index<<" capacity= "<<my.capacity()<<"\n";
		my.push_back(a);
	}

	std::vector<int> v1 = { 1,2,3,4,5 };
	
	// 반복자를 가져와 기존 데이터의 맨 앞에 100 추가
	auto ir = v1.begin();
	v1.insert(ir, 100);

	// 반복자를 반드시 다시 가지고 와야 함 
	ir = v1.begin();
	v1.insert(ir, 200);

	// 값을 설정한 숫자만큼 앞에 추가함
	ir = v1.begin();
	v1.insert(ir, 3, 300);

	for (int i : v1)
	{
		std::cout<<i <<" ";	// 출력 300 300 300 200 100 1 2 3 4 5

	}
		
	return 0;
}

