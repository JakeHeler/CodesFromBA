#include <iostream>
  
int main()
{
    	int numbers[5] = { 100 , 55 , 20 , 35 , 5};
    	int temp;
    	for(int i =0 ; i < 5; i++)
    	{
        		for(int j=0 ; j < 5 ; j++)
        		{
            		if( numbers[i] <=  numbers[j] )
            		{
               			temp = numbers[i];
                			numbers[i] = numbers[j];
                			numbers[j] = temp; 
            		}
        		}
    	}
	
    	for(int n: numbers)              
        		std::cout << n << ' ';	

     	return 0;
}
