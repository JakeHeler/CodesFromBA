#include <iostream>

void fun() { }

class Myclass{
     int var1;
     int var2;
};

int main()
{
    	char var;


    	std::cout<< "Type Size ="<< sizeof var<<"\n";  

    	int var1[10];
	

    	std::cout<<"Type Size ="<< sizeof var1<<"\n"; 
    
	    Myclass var2;
	

    	std::cout<<"Type Size ="<< sizeof var2<<"\n"; 
                                         
   	    std::cout<<"Type Size ="<<sizeof (Myclass)<<"\n"; 

	    // 에러 발생.
    	std::cout<<"Fun Size ="<< sizeof fun; 	

    	std::cout<<"Fun Size ="<< sizeof (int); 

}
