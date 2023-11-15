struct A{
	int m;
};

template <typename T> struct B{};
template <typename... T> struct C{};

// T usertype::* 형태의 클래스 멤버에 대한 포인터를 인자로 가짐
template <typename T> void f(T A::*) {};

// type[i] 형태의 인자를 가짐. 하기는 1차원 배열의 크기를 가져오는 템플릿 함수
template <int N> int g(int(&)[N]) { return N; }

// TT<T> 형태의 인자 가짐
template <typename T, template <typename D> typename TT> void h(TT<T>) {};

// TT<> 형태의 인자 가짐
template <template <class ...> typename TT> void j(TT<>) {};

// 클래스템플릿이름<T> 형태의 인자 가짐
template <typename T> void k(B<T>) {};

int main()
{
	int A::* pm = &A::m;
	f(pm);		// T = int
	
	int ar[10];
	g(ar);		// N = 10

	B<int> b;
	h(b);		// T = int, TT = B

	C<> c;		// 템플릿 파라미터 팩에서 어떤 인자도 같지 않는 경우
    	j(c);		// TT = C 
		
		k(b);		// T = int

	return 0;
}
