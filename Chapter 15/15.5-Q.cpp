#include <concepts>

// 정수를 체크하는 콘셉트 정의
template<typename T>
concept Integral = std::is_integral_v<T>;

template<typename T>
concept CompoundCheck = 
requires (T x)
{

	{x++} ->  Integral;
	
	{x++} -> std::same_as<int>; 
};

struct A{
	int operator++(int)  noexcept;
}; 

template< CompoundCheck T>
void g() {}

int main()
{
	// 클래스 A 는 증가 연산자 오버로딩이 있고 그 함수 반환 타입이 int. g() 정상 호출됨. 
	g<A>();		//OK
	return 0;
}
