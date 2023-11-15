

template < typename T , int size, T value=T()>
class MakeArray{
public:

	using type = T;
	using reference = T&;

	MakeArray();

	constexpr T operator[]( int pos)  noexcept;

	template < typename S , int other_size, S other_value>
	MakeArray<T, size, value>& operator=(const MakeArray<S, other_size, 		other_value>& rhs) ;

	T _array[size];

};

template < typename T , int size, T value>
MakeArray<T, size, value>::MakeArray()
{
	for (int i = 0; i < size; i++)
	_array[i] = value;
}

template < typename T , int size, T value>
constexpr T MakeArray<T, size, value>::operator[](int pos)  noexcept
{
        return _array[pos];
}

template < typename T , int size, T value>		  // 클래스 템플릿 헤드
template < typename S , int other_size, S other_value> // 멤버 함수 템플릿 헤드
MakeArray<T, size, value>& MakeArray<T, size, value>::operator=(const MakeArray<S, other_size, other_value>& rhs)
{
	for (int i = 0; i < size; i++)
	{
		if( i < other_size)
			this->_array[i] = rhs._array[i];
		else
			this->_array[i] = T();
	}
	return *this;
}

int main()
{
	MakeArray<int, 5> a;
	MakeArray<int, 5,-1> b;

	a = b;
}
