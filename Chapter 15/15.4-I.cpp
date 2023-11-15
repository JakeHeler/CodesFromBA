template <typename T> void f(const T) {};
template <typename T> void g(T&) {};
template <typename T> void h(T[]) {};
template <typename T> void my(T(*)[5]) {};
template <typename T> void func(T(*)()) {};

int foo() { return 0; }

int main()
{
	int a = 0;
	int ar[5] = { 1,12,23,40,99 };

	f(0);		
	f<>(10);
	g(a);		
	h(ar);		

	int ar2[4][5];
	my(ar2);	
	
	func(foo);	
	
	return 0;
}
