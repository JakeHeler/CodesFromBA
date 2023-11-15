#include <iostream>
int foo(int n)
{
	n++; 
   	return 0;
}

void swap(int *pa, int *pb)
{
    	int temp = *pa;
    	*pa = *pb;
    	*pb = temp;
}

int main()
{
     	int a = 0 , b=10 ;

     	foo(a);

     	// Before Swap 
     	std::cout << a << " " << b<<"\n";	
     
     	swap(&a, &b);
     	// After Swap 
     	std::cout << a << " " << b;	
	return 0; 
}
