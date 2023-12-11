#include <iostream>

// 원본 클래스 템플릿
template <typename... Rest>
struct VarClass {};

// 각각의 원소를 저장하는 클래스 템플릿
template <typename T>
struct Each_Data 
{
    	constexpr Each_Data() : val() {}

    	template <typename T1>
    	Each_Data(T1&& arg) : val(std::forward<T1>(arg)) {}

    	T val;
};

template <typename This, typename... Rest>
struct VarClass<This, Rest...> : VarClass<Rest...>
{
public:
    	using Mybase    = VarClass<Rest...>;

    	VarClass() {}

	// 생성자 초기화 리스트에서 부모 클래스 초기화 및 원소 저장
    	VarClass(const This& arg1, const Rest&... args)
        	: Mybase(args...), data(arg1) {}

private:
    	Each_Data<This> data; 
};

struct A { 
	A() {std::cout << "A constructor\n";}
};

int main()
{
    	A obj;
    	VarClass<int, char, double, A> vc(1,'a',0.1, obj);
}
