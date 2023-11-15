struct A{
	int m;
	int func(int) { return 0; }
	char fm(A) {return 0;}
};

// type(T) 형태의 인자
template <typename T> void f(double(T)) {}	

// T (usertype::*)(T) 형태의 인자
template <typename T> void g(T (A::*)(T)) {}	

// type (T::*)(T) 형태의 인자
template <typename T> void h(char (T::*)(T)) {}

double func(int) {return 0.0;}

int main()
{
	f(func);	// T = int

    	int (A::* pmf)(int) = &A::func;
    	g(pmf); 	// T = int

    	char (A::* fm)(A) = &A::fm;
    	h(fm);
	return 0;
}
