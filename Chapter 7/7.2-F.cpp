#include <iostream>
int main()
{
	char ar[2][3] = { {'a','b','c'} , {'d','e','f'} };

	char(*po)[3]  =  ar;

    	for(int i=0; i < 2 ; i++)
    	{
       		for (int j = 0; j < 3; j++)
            		std::cout << po[i][j]<<" ";	
    
    	}
	return 0;
}
