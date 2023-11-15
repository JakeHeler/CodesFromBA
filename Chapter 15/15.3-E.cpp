
template < typename T , int size, T value=T()>
class MakeArray {
public:

	// 사용편리를 위해 파라미터에 대한 using 선언.
	using type = T;
	using reference = T&;
	
	// 생성자에서는 배열값 초기화를 진행함
	MakeArray();
	
	// 첨자 연산자 오버로딩 함수
	constexpr T operator[](int pos)  noexcept;
    int GetSize();
	// 배열 데이터 멤버 . 타입과 크기를 파라미터로 받아서 처리함.
private:
	int _size;
	T _array[size];

};


template < typename T , int size, T value>
MakeArray<T, size, value>::MakeArray() : _size(size)
{
	for (int i = 0; i < size; i++)
	_array[i] = value;
}

template < typename T , int size, T value>
constexpr T MakeArray<T, size, value>::operator[](int pos)  noexcept
{
        return _array[pos];
}

// 클래스 템플릿에서 선언된 파라미터와 이름이 다르게 설정할 수가 있음.
// 그러나 선언된 순서는 반드시 지켜야 됨.
template < typename T, int S, T V>
int MakeArray<T, S, V>::GetSize(){ return _size; } 

int main()
{
	MakeArray<int, 5> m;
	MakeArray<double, 5, 1.0> m1;

	return 0;
}
