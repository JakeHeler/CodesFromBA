#include <iostream>
int main()
{

	int width = 3, height = 5;

    	char** OmokCell;


    	OmokCell = new char* [width] ;


    	for (int i = 0; i < width; i++) {
        		OmokCell[i] = new char [height];
    	}

       	for (int i = 0; i < width; i++)
       	std::printf("0x%X ", OmokCell+i);

       	std::cout << "\n";

       	for (int i = 0; i < width; i++)
       	std::printf("0x%X ", OmokCell[i]);
	

    	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
            		OmokCell[i][j]= 1;

	    return 0; 
}
