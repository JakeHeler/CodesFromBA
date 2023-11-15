#include <iostream>

struct Allot {

	void* operator new(std::size_t s) {  return std::malloc(s); }
	void* operator new(std::size_t s,int id) { return std::malloc(s); }

	void operator delete(void* ptr) noexcept { std::free(ptr); };
};

int main()
{
	new  Allot;	
	new Allot[5];	

	int id = 1;
	auto p = new (id) Allot;	
	//auto p = new (id) Allot [5];	// 에러 발생. 해당 연산자 함수가 정의되어 있지 않음 
	delete (p);	
}
