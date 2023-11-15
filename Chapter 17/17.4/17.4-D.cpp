#include <concepts>

struct A { };
struct Con {
	Con();
	Con(int);
	Con(A);
};

int main()
{
	// OK . int 타입을 선언하거나 다른 타입으로 형변환되어 초기화가 가능함
	static_assert( std::constructible_from<int> );
	static_assert( std::constructible_from<int, double>);

	// 에러 발생. 참조자는 선언시 초기화를 해야됨
	static_assert( std::constructible_from<int&> );

	// 에러 발생. 참조자 타입과 int 타입의 변환이 되지 않음.
	// 아래의 내용은 하기의 코드 유사함. 형변환을 하게되면 에러가 발생함
	// int a=0;
	// int& b = (int) a; 	// 에러 발생.
	// 여기서 변수 앞에 const 키워드를 사용하면 가능해짐. 상수값이 중요 요소가 됨
	// const int& b = (int) a; 	// OK
	static_assert( std::constructible_from<int&, int> );

	// OK .
	static_assert( std::constructible_from<const int&, int> );
	static_assert( std::constructible_from<int, int&> );

	// OK . 관련 생성자가 지원됨.
	// 생성자를 템플릿으로 만들게 되면 아래의 타입에 대해 모두 true 로 처리됨 
	//	template <class T>
	//	Con(T);

	static_assert( std::constructible_from< Con> );
	static_assert( std::constructible_from< Con, int> );

	// int 로 형변환 됨.
	static_assert( std::constructible_from< Con, double> ); 
	static_assert( std::constructible_from< Con, A> );

}

