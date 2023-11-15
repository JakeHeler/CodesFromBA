#include <iostream>
#include <iterator>

// 테스트용 입력 반복자 클래스 템플릿
template <typename T>
class InputIterator{
public:
	// 필수적인 반복자 특성을 규정
    	using iterator_category = std::input_iterator_tag;
    	using value_type        = T;
    	using difference_type   = int;

	// 간접참조 연산자 오버로딩
    	T& operator*() const noexcept ;
	
	// 증가 연산자 오버로딩
	InputIterator& operator++()  noexcept;
	InputIterator operator++(int)  noexcept;

	bool operator==(const InputIterator& _Right) const noexcept;
	bool operator!=(const InputIterator& _Right) const noexcept;

};
template <typename T>
struct IteratorSample { };

int main()
{
	// 필수 사항들이 충족되어 하기는 정상 동작
	if( std::input_iterator< InputIterator< int >>)
 		std::cout<< "Normal Input Iterator"<<"\n";

	// 샘플 클래스는 비워 있어서 충족되는 사항이 없음. 출력 : Error Iterator
	if( ! std::input_iterator< IteratorSample<int>> )
		std::cout<< "Error Iterator";

	return 0;
}
