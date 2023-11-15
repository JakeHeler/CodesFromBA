#include <iostream>

// 데이터 요소를 가져오는 템플릿 클래스
template <typename T, int size>
class ArrayIterator{
public:
	ArrayIterator() noexcept {}
    	ArrayIterator(T* ptr, int Size) : _pointer(ptr),_size(Size) {}

	// 간접 참조 연산자 오버로딩
        	T& operator*() const noexcept 
	{
		return *(_pointer + _size);
    	}

	// 전위 증가 연산자 오버로딩
	ArrayIterator& operator++() noexcept {
        		++_size;
        		return *this;
    	}
	// 후위 증가 연산자 오버로딩
	ArrayIterator operator++(int) noexcept {
        		++_size;
		return *this;
    	}
    	bool operator==(const ArrayIterator& _Right) const noexcept {
        		return _size == _Right._size;
    	}
	
	// != 연산자 오버로딩
	bool operator!=(const ArrayIterator& _Right) const noexcept {
         	return !(*this == _Right);
    	}	

private:
    	T* _pointer;
    	int _size;
};

// 
template < typename T , int size, T value=T()>
class MakeArray {
public:
	using iterator = ArrayIterator<T, size>;
	MakeArray()
	{
		for (int i = 0; i < size; i++)
			_array[i] = value;
	}
	
	// 데이터 요소를 가져올 때 클래스 템플릿을 반환. 여기서는 ArrayIterator 클래스 타입에 
	// 괄호 ()를 사용한 명시적 타입변환 형태로 반환함 
	iterator GetFirst()
	{
		return ArrayIterator<T, size>(_array, 0);
	}
	iterator  GetLast()
	{
		return ArrayIterator<T, size>(_array, size); 
	}

private:
	T _array[size];
};

int main()
{
	MakeArray<int, 5> m;
	
	// 증가 연산 가능함. 연산자 오버로딩 함수가 제공됨
	std::cout << *m.GetFirst()++ << "\n";
	
	auto pt = m.GetFirst();


	int index = 0;
	for (pt; pt != m.GetLast(); pt++)
	{
		*pt = index++;
		std::cout << *pt <<",";	
	}

	return 0;
}
