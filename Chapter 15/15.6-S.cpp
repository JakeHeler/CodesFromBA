#include <iostream>

template <typename...  T>
void VarFunc(T... args) {
 
    	static constexpr unsigned int size= sizeof...(args);
    	std::cout<< "Number of parameter Pack = "<< size<<"\n";
    
    	int data[size] = { args... };	// 중괄호 초기화
    
    	for (int i = 0; i < size; i++)
        		std::cout << data[i] << " ";
};

int main()
{
	VarFunc(1, 2, 3, 4);	
}
