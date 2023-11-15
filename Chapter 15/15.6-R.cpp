#include <iostream>
#include <stdarg.h>  

void  printData(const char* fmt, ...  )
{
	va_list args;
	va_start(args, fmt);

	while (*fmt)
	{
	        	switch (*fmt++)
	        	{
	            	case 'i':
	                		std::cout << va_arg(args, int)<<"\n";
	                		break;

	            	case 'c':
                    	{
				        char c = (char)va_arg(args, int);
	                		std::cout << c<<"\n";
	                		break;
                    	}
	            	case 'd':
	                		std::cout << va_arg(args, double)<<"\n";
	                		break;
	        }
	}
	va_end(args);
}

int main()
{
	printData("icdi", 1,'A',  0.5,10);
}
