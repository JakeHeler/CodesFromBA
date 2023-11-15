#include <concepts>

struct A { 
	int operator()(int) const; 	// #1
	int operator()(); 		// #2
};

int f();
int g(int);

int main()
{
	// 에러 발생. 단순히 int 타입만 전달됨
	static_assert(  std::invocable<int> );

	// OK : 함수 형태의 타입이 전달됨
	static_assert( std::invocable<int()> );

	// OK : 함수 사용 가능 . decltype 사용해 함수를 전달한다.
	static_assert( std::invocable<decltype(f)>); 

	// OK : 함수 파라미터 타입 전달
	static_assert( std::invocable<decltype(g),int> ); 

	// 클래스 타입. 함수 호출 연산자 오버로딩 제공함.
	static_assert( std::invocable<A, int> ); 
	static_assert( std::invocable<A> ); 

	// 에러발생. const 파라미터 대해  # 2번 함수는 const 가 아님. 
	static_assert( std::invocable<const A> ); 
}
