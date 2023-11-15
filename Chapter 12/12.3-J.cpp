#include <iostream>
#include <cstring>

class ArrayInt
{
public:
	// 배열 크기와 초기값 설정하는 생성자
	ArrayInt(int n, int val) 
	{ 
		size = n;
		ptr = new int [n]; 
		for (int i = 0; i < n; i++)
			ptr[i] = val;
	}
	// 복사 생성자
	ArrayInt(ArrayInt& src)
	{
		int n = src.size;
		size = n;
		ptr = new int[n];
		
		std::memcpy(ptr, src.ptr, n * sizeof(int));

	}

	void SetValue(int pos, int val) { ptr[pos] = val; }
	int GetValue(int pos) { return ptr[pos]; }

private:
	int size;
	int* ptr;
};

int main()
{
	ArrayInt a(5,1);
	std::cout << " a : " << a.GetValue(0)<<"\n";	
	ArrayInt b = a;
	std::cout  <<" b : "<< b.GetValue(0)<<"\n";	
	
	a.SetValue(0, 10);

	std::cout  <<" b : "<< b.GetValue(0)<<"\n";	
}
