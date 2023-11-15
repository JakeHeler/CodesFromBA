#include <iostream>
int main()
{
    	const char* str = "Hello ! Strings !!!";
    
    	int index = 0;
    	int count = 0;
    	while(true)
    	{
        		if (str[index] == '\n')
            		break;

        		if (str[index] == '!')
            		count++;
        		index++;
    	}

    	std::cout << count;	// 출력 4
  
	return 0; 
}
