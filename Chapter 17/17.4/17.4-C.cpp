#include <concepts>

struct Parent { };
struct Child : Parent{ };

int main()
{
	// OK . 참조타입을 int 타입 변환이 가능함
	static_assert( std::convertible_to< int&,  int> );

	// 에러 발생 . int 타입을 참조타입으로 변환이 안됨
	static_assert( std::convertible_to<int, int&> );

	// OK . const 키워드가 사용되면 형변환 가능
	static_assert( std::convertible_to<int, const int&> );

	// OK . 자식 클래스는 부모 클래스로 형변환 가능
	static_assert( std::convertible_to<Child,  Parent> );

	// 에러 발생 . 부모 클래스는 자식 클래스로 형변환 안됨.
	static_assert( std::convertible_to<Parent,  Child> );
}
