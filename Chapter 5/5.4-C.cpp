constexpr int Size(int n)
{
 	int r=10;
	return n * r;
}

int DecideNumberArray(int n)
{
	return n * n;
}

constexpr int FixNumberArray(int n)
{
    return n * n;
}

constexpr int Func(int n)
{
   	int count;			
	static int b=0;		// 에러 발생 
	return n * count;
}

int main()
{
    	const int size = DecideNumberArray(5);

	
    	int array[size];

	const int size1 = FixNumberArray(5);
	int array1[size1];
}
