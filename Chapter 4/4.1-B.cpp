#include <iostream>

const int var = 1;
#define Version 1

int main()
{

	#ifdef 	var
		std::cout << "Print : var \n";
	#endif
	
	
	#ifdef  Version	
		std::cout << "Defined Version \n";
	#endif


	#if defined Version && defined Version1
		std::cout << "defined Veraion and Version1 \n";
	#endif

	return 0;
}

