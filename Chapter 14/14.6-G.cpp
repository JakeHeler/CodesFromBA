#include <iostream>

constexpr int N = 10;
struct Array{
	Array()
	{ 
		for (int i = 0; i < N; i++)
			arr[i] = i;
	}

	const int* operator->() const  { return arr; }
	int operator*()  { return *arr; }	

private:
	int arr[N];
};

int main()
{
	Array ar;

	auto ptr = ar.operator->();	
	for (int i=0; i < N; i++)
		std::cout<<*(ptr+i)<<" ";
}
