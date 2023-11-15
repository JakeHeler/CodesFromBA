#include <iostream>
int main()
{

    	int ar[3][5] = {{1,2,3,4,5}, {10,20,30,40,50}, {100,200,300,400,500}};
    	int* row[3]= {ar[0],ar[1],ar[2]};
	

    	int** ptr = row;
	

         std::cout << ptr[0][0]<<" "<<ptr[1][1]<<" "<<ptr[2][2];

	return 0; 
}
