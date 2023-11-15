#include <ranges>

template<class T>
class MySafeRange {
public:
	using pointer = T*;
    	T* begin() const noexcept;
	T*  end() const noexcept ;

private:
	pointer _Pointer = nullptr;
	int _Size;
};

// 하기처럼 range의 namespace 맞게  특수화된 변수 템플릿을 설정해야 함.
// 원본 변수 템플릿은 레인지의 namespace 이미 선언되어 있음. 
template<typename T>
constexpr bool std::ranges::enable_borrowed_range<MySafeRange<T>> = true;

int main()
{
	// OK.
	static_assert( std::ranges::borrowed_range<MySafeRange<int>> );
}
