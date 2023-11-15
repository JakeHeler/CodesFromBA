#include <iostream>

template < typename T , int size, T value=T()>
class MakeArray {
public:
	MakeArray()
	{
		for (int i = 0; i < size; i++)
		_array[i] = value;
	}
	
	// 해당 배열의 시작 주소와 마지막 바로 다음 주소를 가져오는 함수
	T* GetFirstPointer() {	return _array; }
	T* GetLastPointer() {	return ( _array + size ); }

private:
	T _array[size];
};

int main()
{
	MakeArray<int, 5> m;

	std::cout << *m.GetFirstPointer() << "\n";
	
	// 에러발생. 첫 번째 요소를 포인터로 가져와 바로 증가 연산을 하면 오류 발생.
	// 함수 반환은 rvalue 이기 때문
	std::cout << *m.GetFirstPointer()++ <<"\n";	

	return 0;
}
