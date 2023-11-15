#include <iostream>

const int var = 1;
#define Version	1

int main()
{

	#if  1
		std::cout << "Print !!! \n";
	#endif


	#if  var
		std::cout << "Print : var";
	#endif


	#if  Version
		std::cout << "Print : Version \n";
	#endif

	#if  Version == 1
		std::cout << "Version = 1";

	#elif  Version == 2
		std::cout << "Version = 2";

	#else
		std::cout << "Version else";
	#endif

	return 0;
}