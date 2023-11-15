#include <iostream>
int main()
{
	char ch[5] = { 'a' , 'b', 'c', 'd' ,'e' };
	char* po = ch;	

	std::cout << ch[1]; 	 
	std::cout << *(po+1); 	
	std::cout << po[1] ;  	
	
	// 하기는 동일한 표현
	// ch[1] = *(ch +1) = *(po+1) = po[1]
	return 0;
}
