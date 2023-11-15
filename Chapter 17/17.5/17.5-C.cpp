#include <ranges>
#include <vector>

// 반복자 템플릿 클래스
template <typename T>
class InputIterator{
public:
    	using iterator_category = std::input_iterator_tag;
    	using value_type        = T;
   	using difference_type   = int;

	T&  operator*() const noexcept;
	InputIterator& operator++()  noexcept;
	InputIterator operator++(int)  noexcept;

	bool operator==(const InputIterator& _Right) const noexcept;

};

// 신규로 만든 반복자를 이용한 클래스
struct X {
	using iterator = InputIterator<int>;
	iterator begin() ;
	iterator end() ;
};

int main()
{
	// OK. vector 의 반복자는 규정을 만족
	static_assert( std::ranges::range<std::vector<int>>);

	// OK. X 클래스는 반복자의 규정을 만족
	static_assert( std::ranges::range<X>);
	return 0;
}
