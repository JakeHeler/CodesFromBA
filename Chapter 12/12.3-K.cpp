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

	ArrayInt(ArrayInt&& src)
	{ 
		size = src.size;	
		ptr = src.ptr;		// 복사 대상의 포인터를 대입

		src.ptr = nullptr;	// 복사 원본의 포인터를 nullptr로 처리함
	}	
	~ArrayInt()
	{ 
		if(ptr != nullptr) 
			delete ptr; 
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
	ArrayInt b = a;		

 	ArrayInt c = std::move(ArrayInt(5,1));
}
