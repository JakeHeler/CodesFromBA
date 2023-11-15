#include <iostream>

// 원본 클래스 템플릿
template <typename... Rest>
struct Tuple {};

// 각각의 원소를 저장하는 클래스 템플릿
template <typename _Ty>
struct Tuple_val 
{
    constexpr Tuple_val() : _Val() {}

    template <typename _Other>
    constexpr Tuple_val(_Other&& _Arg) : _Val(std::forward<_Other>(_Arg)) {}

    _Ty _Val;
};

template <class This, class... Rest>
class Tuple<This, Rest...> : Tuple<Rest...> 
{
public:
    	using Mybase    = Tuple<Rest...>;

    	Tuple() {}

	// 생성자 초기화 리스트에서 베이스 클래스 초기화 및 원소 저장.
    	Tuple(const This& arg1, const Rest&... args)
        	: Mybase(args...), Myfirst(arg1) {}

private:
    	Tuple_val<This> Myfirst; 
};

int main()
{
    	int m = 10;
    	Tuple<int, char, double,int> vc(1,'a',0.1,m);
}
