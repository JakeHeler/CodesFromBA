

int op_one(int cm) { return 0; }
int op_two(int cm);
int op_three(int cm);


// 반환타입:  int (*)(int) ,  함수원형: ChooseFunc(char , int)
int (*ChooseFunc(char i, int j)) (int cm)
{
    	return op_one;
}

using MyFunPtr = int(*)(int);


typedef int (*MyFunPtr)(int cm);

MyFunPtr DecideFunc(char i, int j)
{
    	return op_one;
}


auto SelectFunc(char i, int j) -> int(*)(int)
{
    	return op_one;
}

int main()
{
    	// 함수 포인터 타입 반환.
	    auto fptr = ChooseFunc(0,1);
	    fptr(0);

    	MyFunPtr pfun = DecideFunc(0,1);
    	pfun(0);

    	auto ap = SelectFunc(0, 1);
    	ap(0);

	    return 0;
}
