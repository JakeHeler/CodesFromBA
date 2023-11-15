#include <concepts>
#include <type_traits>

// 콘셉트 : 포인터 타입 및 정수 타입을 체크함
template<typename L, typename R>
concept CheckPointAndType = std::is_pointer_v<L> && std::is_integral_v<R>;

// 클래스 템플릿
template<typename T>
class DataPoint{

public:

    	using value_type      = T;
    	using pointer          = T*;

	// 생성자 템플릿 : 생성자의 인자의 타입이 해당 콘셉트의 첫 번째 인자가 됨.
	// CheckPointAndType = std::is_pointer_v<L> &&
	// 			std::is_integral_v<value_type>;

	template<CheckPointAndType <value_type> L>
	constexpr explicit DataPoint(L var) { }

public:
	pointer _Pointer = nullptr;
};

int main()
{ 
	int ar[5];

	// OK. 템플릿 인자가 int 타입 그리고 생성자의 인자가 포인터 타입.
	DataPoint<int> dp1 (ar);

	int b=0;
	// 에러발생. 인수 타입이 포인터 타입이 아님.
	DataPoint<int> dp2 (b);

	return 0;
}
