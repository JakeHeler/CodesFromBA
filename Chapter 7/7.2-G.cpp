int foo(int n)
{
    return 0;
}

void func1( int* p, int ar[], int* ap[]) {}
void func2( int ar[][5], int(*pa)[10]) {}
void func3( int(*pf)(int) ) {}

int main()
{
     	int i = 0;
     	int a[5];
    	int* p[5];
	
     	func1(&i, a, p);

     	int ar1[3][5];
     	int ar2[3][10];

     	func2(ar1, ar2);

     	func3(foo);
}
