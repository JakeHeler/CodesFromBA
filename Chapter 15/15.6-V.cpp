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

// 원본 클래스 템플릿
template <size_t Index, class _Tuple>
struct Tuple_element ;

template <size_t Index, class _Tuple>
using Tuple_element_t = typename Tuple_element<Index, _Tuple>::type;

template <class This, class... Rest>
struct Tuple_element<0, Tuple<This, Rest...>> { 
    	using type = This;	 // 지정된 타입
	// 지정된 타입으로 여기서는 This가 각 원소를 저장하는 Tuple_val<This> Myfirst 
	// 멤버에 템플릿 인자로 사용됨.
    	using _Ttype = Tuple<This, Rest...>; 
};

// 부분 특수화: 인덱스가 줄면서 파라미터 팩이 This, 파라미터 팩 Rest로 분리됨 
template <size_t Index, class This, class... Rest>
struct  Tuple_element<Index, Tuple<This, Rest...>>
   : Tuple_element<Index - 1, Tuple<Rest...>> { }; 

template <size_t Index, class... Types>
Tuple_element_t<Index, Tuple<Types...>>& GetValue(Tuple<Types...>& _Tuple)  
{
    	using _Ttype = typename Tuple_element<Index, Tuple<Types...>>::_Ttype;
    	return static_cast<_Ttype&>(_Tuple).Myfirst._Val;
}


template <class This, class... Rest>
class Tuple<This, Rest...> : Tuple<Rest...> 
{
public:
    	using Mybase    = Tuple<Rest...>;

    	Tuple() {}

	    template <size_t Index, class... Types>
    	friend Tuple_element_t<Index, Tuple<Types...>>& GetValue(Tuple<Types...>& Tuple); 

    	Tuple(const This& arg1, const Rest&... args)
        	: Mybase(args...), Myfirst(arg1) {}

private:
    	Tuple_val<This> Myfirst; 
};

int main()
{
    	int m = 10;
    	Tuple<int, char, double, int> vc(1,'a', 0.1, m);
	    std::cout<< GetValue<3>(vc);	

}
