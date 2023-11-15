#include <iostream>

struct MyStruct {};
class MyClass {};

int main()
{
  
    	MyStruct s;
    	MyClass c;

        std::cout << typeid(s).name() << "\n";
    	std::cout << typeid(MyClass).name();	

    	if (typeid(s) == typeid(c));	
}
