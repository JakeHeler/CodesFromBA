template <typename T>
struct A{
	// 파라미터 타입 T 를 별도로 이름을 정의함.
	using value_type        = T;
	using pointer_type      = T*;

};
template<typename T> class B{};

// 해당 타입이 정의되어 있는지 확인하는 requires 수식
template<typename T>
concept TypeCheck = requires
{
    	// 해당 이름의 타입이 있는지 확인함
	typename T::value_type;
	typename T::pointer_type;

	// 해당 타입 T로 클래스 템플릿이 가능여부를 확인함 
	typename B<T>;
};

template<TypeCheck T> 
void f() 
{
	// 함수 구현 시, 해당 타입 T 가 가지는 타입으로 변수를 선언함.
	typename T::value_type var = 0;

}

int main()
{
	// 정상동작. 클래스 템플릿 A 는 requires 수식을 만족함
	f<A<int>>();
	
	return 0;
}
