#include <concepts>

struct Parent { };
struct Child : Parent{ };
struct C : private Parent { };

int main()
{
	// 에러 발생. 상속관계가 아님.
	static_assert( std::derived_from<int, int> );

	// OK. 상속관계. 클래스 B의 위치가 중요함
	static_assert( std::derived_from<Child, Parent> );
	static_assert( std::derived_from<Child, const Parent> );

	// 에러 발생. 여기서 위치가 중요함. B 가 자식 클래스 임.
	static_assert( std::derived_from<Parent, Child> );

	// 에러 발생 . public 으로 상속 받아야 됨
	static_assert( std::derived_from<C, Parent> );
}
