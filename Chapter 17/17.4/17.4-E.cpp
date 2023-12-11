#include <concepts>

struct A { };

struct B 
{ 
	B(const B&);
};

struct C 
{ 
	C(C&);
};

int main()
{
	// OK :　기본 타입
	static_assert( std::copyable<int>);
	static_assert( std::copyable<int*>);

	// OK : 복사생성자 내부적으로 생성됨. 
	static_assert( std::copyable<A> );

	// OK : 복사생성자 제공. 
	static_assert( std::copyable<B> );

	// 에러 발생 : 복사 생성자의 파라미터의 타입에 const 키워드를 사용해야 함
	static_assert( std::copyable<C> );
}
