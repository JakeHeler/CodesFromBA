#include <iostream>

struct st {

    int x;
    int y;
};

int var = 10;
int main()
{

     	long long a = (long long) &var;
    

     	int * p = &var;


       	std::printf("0x%X\n", a);	// 일정 주소 값 출력 
       	std::printf("0x%X\n", p);	// 위와 같은 주소 출력



	char* pt1;
	st* pt2;


	std::cout <<*p <<"\n";	//  출력 10
	*p =100;		// 해당 주소의 변수 값 변경

     	st s;
     	st* ptr = &s;
   	

     	(*ptr).x = 1;
     	ptr->y = 10;

	return 0;
}
