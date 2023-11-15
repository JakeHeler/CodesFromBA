#include <ranges>
#include <vector>

// 임의 접근의 반복자를 가지는 클래스
class R
{
	int ar[10];
	public:
	// begin 반복자. 포인터 타입으로 반복자가 사용됨.
	int* begin();
};

struct A
{
	int begin();
};

int main()
{ 
	std::vector<int> v;

	// 정상동작. ranges::begin 에서는 타입을 확인 후 해당 반복자를 호출.
	// 컨테이너 STL은 해당 반복자를 지원함.
	static_assert(std::same_as<decltype(std::ranges::begin(v)), decltype(v.begin())>);
	
	int ar[10];
	// 정상동작. 배열 타입을 확인 후 해당 첫 번째 포인터를 넘겨줌.
	static_assert(std::same_as<decltype(std::ranges::begin(ar)), decltype(ar+0)>);

	R r;
	// 정상동작. 해당 클래스에서 begin 반복자가 제공됨. 반복자는 포인터 또는 클래스타입
	auto be1= std::ranges::begin(r);

	A a;

	// 에러 발생. 해당 클래스는 반복자 타입의 조건을 만족하지 못함.
	auto be2= std::ranges::begin(a);

	return 0;
}
