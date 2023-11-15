// 콘셉트 정의 : requires 수식 사용 , 해당 타입이 증가연산이 되는지 확인
template<typename T> concept IsIncrement =
	requires (T a) {
	a++;
};

template<IsIncrement T> 
void f() {}

// 비워 있는 일반 클래스 . 증가 연산자 오버로딩을 테스트를 위해 코멘트 처리함
struct A
{
	// A operator++(int)  noexcept;
};

int main()
{
	// 에러 발생. 해당 클래스는 증가 연산자 오버로딩을 제공하지 않음
	// 증가 연산자를 구현하면 정상동작 
	f<A>();

	// 정상동작. 기본 타입 int 는 당연히 증가 연산이 가능함
	f<int>();
	return 0;
}
