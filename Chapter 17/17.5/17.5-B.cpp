#include <ranges>

// 클래스타입에서 해당 멤버 함수를 가지고 있는지 확인하는 콘셉트
template< typename T>
concept Has_member = requires(T t) 
{
	{ t.begin() } -> std::input_or_output_iterator;
};

namespace ranges{

    	// 레인지의 begin 클래스 구현
	class _Begin {

	public:
		// 함수 호출 오버로딩 구현. 배열 타입을 함수 인자로 받음
		template<typename T>
        		constexpr T * operator()(T array[]) const noexcept
        		{
			return array;
        		}

		// 클래스 타입이면 해당 함수 여부를 체크하여 함수를 호출함.
		template<typename T>
		requires Has_member<T>
		constexpr auto operator()(T&& t) const noexcept 
		{
			return t.begin();
		}
	};
	
	// begin 클래스 변수 선언.
    	inline constexpr _Begin begin;
}

int main()
{ 

	int ar[10];
	// 정상 동작. 선언된 클래스 변수에 함수 파라미터를 넘기면 타입에 맞는 함수를
	// 찾게 되어 정상적으로 호출됨.
	static_assert(std::same_as<decltype(ranges::begin(ar)),	 decltype(ar+0)>);

	int i=0;
	// 에러 발생. 해당 인자에 맞는 함수 호출 오버로딩 함수가 없기 때문.
	auto be1= ranges::begin(i);

	return 0;
}
