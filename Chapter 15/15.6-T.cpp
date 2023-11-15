#include <iostream>

void VarFunc(){}

template <typename T1, typename...  Types>
void VarFunc(T1 t1,Types... args) {
 	std::cout<< t1<< " ";
    	VarFunc(args...);
};

int main()
{
	VarFunc(1, 'a', 0.3);	// 출력 1 a 0.3
	return 0;
}
