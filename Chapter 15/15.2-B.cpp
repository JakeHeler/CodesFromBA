template <typename  T, int size , const T value = T() >
class MakeArray { 
	/* ... */ 
	void Check()
	{
		// Non 타입 파라미터의 인자로 받은 파라미터를 변경해서는 안 됨
		// int var = size++; 
	}
};

template <typename  T, int radius=1>
void MakeCircle() { /* ... */ }

// C++17 이후부터 auto 타입 가능
template <auto x>
void f() { /* ... */ }

// C++20 이후부터 소수점 타입 및 구조체 형태의 클래스 타입 가능
struct X {};
template <typename T, X x , double D>
void g() { /* ... */ }

int main()
{
    
	MakeArray<int , 5> ar;

	// 상수식을 넣어 함수 템플릿 사용. 일반 변수가 인자로 사용되면 에러가 발생함.
	const int r = 10;
	MakeCircle<int , r>();


   	MakeCircle<int>();
	
	// int 타입으로 유추
    	f<10>();


    constexpr X x;
	g<int , x , 0.1>();
	
	return 0;
}
