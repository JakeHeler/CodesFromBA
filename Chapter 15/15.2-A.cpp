template <typename T>
T maximum(T a , T b) { return a > b ? a : b ; }

template <typename T, typename T1 ,typename T2>
void Func(T a) { /* 내용 생략*/ }

// 클래스 템플릿
template <typename T> class A { /* ... */ };
template <typename T, typename P = int> class B { /* ... */};
template <typename T = int > class C { /* ... */ };

int main()
{
	// 함수 템플릿 사용
	maximum<int>(10, 0);

	// 꺽쇠에 넣는 int 타입이 명시되어있어, 함수 인자값을 double에서 int 로 변환됨.
	maximum<int>(1.0, 2.0);

	int a=10;
	Func<int, int, float>(a);
	
	// 에러 발생. 파라미터 개수가 맞지 않음
	Func<int, int>(a);

	// 클래스 템플릿 사용 
	A<int> aa;

	// 포인터 타입을 인자로 넘겨줌. 참조형 타입도 가능
	A<int*> aa1;
	
	// 동적으로 클래스 템플릿 생성. 
	// 사용방식은 기존 되로 꺽쇠 <>에 사용타입을 지정. 
	A<int>* a1 = new A<int>();
	
	// 클래스 템플릿 사용. 기본값이 있으면 파라미터 생략
	B<char, int> b;
	B<char> b1;

	// 하나의 파라미터로 기본값이 있는 경우에 빈 <> 가능함 
	C<> c1;
	//C* c2;	// 에러 발생. <> 생략하면 안 됨.

	return 0;
}
