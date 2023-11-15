#include <concepts>

struct Parent { };
struct Child : Parent{ };

int main()
{
	// 에러 발생. 타입이 틀림.
	static_assert( std::same_as< int,  char> );

	// 에러 발생. const 키워드가 사용되면 타입이 다르게 인식됨.
	static_assert( std::same_as< int,  const int> );

	// 에러 발생. 포인터 타입은 별도의 타입
	static_assert( std::same_as< int,  int*> );

	// 에러 발생. 상속과 관련 없음. 서로 다른 타입.
	static_assert( std::same_as< Child ,  Parent> );
}
