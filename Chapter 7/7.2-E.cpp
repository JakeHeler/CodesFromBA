#include <iostream>
int main()
{

	char ar[2][3] = { {'a','b','c'} , {'d','e','f'} };


	char* po = (char*) ar;

	const int col = sizeof(ar[0]) / sizeof(char);      
	const int row = sizeof(ar) / sizeof(ar[0]); 

	for (int i = 0; i < row * col; i++)
		std::cout << po[i];

	return 0;
}
