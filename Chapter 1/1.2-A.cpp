#include <iostream>

int i = 1;   // 파일 전체에 영향을 주는 전역변수

int main()
{

 	std::cout<<"i value = "<< i<<"\n";  
                               
    	int i = 10;   


    	std::cout<<"i value = "<< i<<"\n";  
    
	    {
         	int i = 100;

         	std::cout<<"i value = "<< i<<"\n";   
    	}

    	{
         	
		std::cout<<"i value = "<< i<<"\n";  
    	}
}
