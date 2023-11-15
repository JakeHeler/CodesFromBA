#include <iostream>
#include <thread>

static thread_local int index=1;

void func1(){

    	while (true)
    	{
        		std::cout << "func1 thread " << index << "\n";
        		index++;
        		if (index > 3)
            		break;
    	}
}

void func2(){

    	while (true)
    	{
            std::cout << "func2 thread " << index << "\n";
        		index++;
       		if (index > 3)
            		break;
    	}
}

int main()
{

    	std::thread t1(func1);
    	std::thread t2(func2);

    	for (;;);
}
