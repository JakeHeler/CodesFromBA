template<int* i> struct X { /* ... */ };

// non 타입 파라미터를 선언 시 참조형 타입의 파라미터를 가짐
template<int& i> struct Y { /* ... */ };

struct A { /* ... */ };
template<A& a> struct Z { /* ... */ };

int ar[5];
int ref = 0;

int var = 10;
int* pointer = &var;

int main()
{
	// OK : 가리키는 대상이 전역변수로 static 저장 기간 을 가짐
	X<ar> x1;
	X<&ref> x2;

	// 에러 발생. 포인터 변수 자체를 바로 Non 타입 파라미터의 인자로 넘겨줄 수 없음
	X<pointer> x3;

	// static 로컬 변수 가능 ( since C++17 )	
	static int ai[5];
	X<ai> x4;

	// 참조형 타입 클래스 템플릿 사용
	Y<ref> y;

	// 에러 발생. 상수를 참조 할 수 없음
	Y<0> y1;

    	static A a;
    	Z<a> z;

	return 0;
}
