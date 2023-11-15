#include <iostream>

struct DoubleArray{
	const int data_size = 5;

	DoubleArray()
	{
		map = new int* ;
		map[0] = new int [data_size];

	}

	void insert_back(int val)
	{
		if (cur < data_size)
		{
			data_insert(val);
		}
		else
		{
			cur = 0;
			block++;

			int** ptr = new int* [block];
			// 이전 포인터를 저장
			for (int i = 0; i < block; i++)
				ptr[i] = map[i];
			delete [] map ;
			
			// 데이터가 늘어나서 전체 행의 포인터를 재할당
			map = new int* [block+1];
			map[block] = new int [data_size];
			// 이전 포인터를 재할당된 map에서 복사
			for (int i = 0; i < block; i++)
				map[i] = ptr[i];

			data_insert(val);
		}
	}

	int operator[](int pos) 
	{ return *( map[pos/data_size] + pos%data_size); }

private :
	int** map;
	int cur = 0;
	int block = 0;

	void data_insert(int val)
	{
		map[block][cur] = val;
		cur++;
	}
};

int main()
{
	DoubleArray da;
	for (int i = 0; i < 10; i++)
		da.insert_back(i);

	for (int i = 0; i < 10; i++)
		std::cout<< da[i]<<" ";	
}
