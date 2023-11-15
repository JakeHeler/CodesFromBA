#include <iostream>

int i=0;

namespace A{

   	namespace B{
    
        		int i=2;
        
        		void f()
        		{
            		std::cout << "f() i value =" << i <<"\n";
        		}
     	}
    	
	void g()
    	{
        		std::cout << "g() i value =" << i <<"\n";
    	}
	
}

int main()
{
    	A::B::f();	
        A::g();	
}
