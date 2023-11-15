#include <iostream>
int main()
{
	int ar[5] =  { 1 , 2, 3, 4 ,5 };

	int* pt = ar + 2; 

	std::cout << pt[-2]<<"\n";	
	std::cout << pt[0]<<"\n";	
	std::cout << pt[2]<<"\n";	
	return 0;
}
