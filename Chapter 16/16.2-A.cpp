#include <iostream>


void* operator new[](size_t _Size)
{
    throw 0;
}

struct ArrayData{

    	ArrayData(int size)
    	{
        		try {
            		ptr = new int[size];
        		}
        		catch(...)
        		{
            		std::cout << "Fatal Error !!!";
			        throw;	//예외 발생한 것 재전송
        		}
    	}

    	int* ptr;
};

int main()
{

	try{
		ArrayData(20);
	}
	catch(...){
        		std::cout << "\nProgram Terminated \n";
       	 	exit(0);
	}
}
