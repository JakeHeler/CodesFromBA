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

	// 첫 번째 요소의 포인터를 가져와서 값을 출력함
	auto pt = m.GetFirstPointer();
	std::cout << *pt <<"\n";		

	int index = 0;
	for (pt; pt < m.GetLastPointer(); pt++)
	{
		*pt = index++;
		std::cout << *pt <<",";	
	}
	
	return 0;
}
