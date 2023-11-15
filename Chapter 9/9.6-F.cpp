#include <iostream>
#include <chrono>
#include <thread>

int ReadFind(std::string file, int checkno)
{
    	int count = 5;
	   	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    	return count;
}


int SearchFile(int id, int search)
{
        std::string name = "file" + std::to_string(id) + ".txt";
    	return ReadFind(name, search);
}

int main()
{ 
    	int cn = 0;

    	auto start = std::chrono::steady_clock::now();


    	cn += SearchFile(1,10);
    	cn += SearchFile(2,10);

    	auto end = std::chrono::steady_clock::now();
    	std::chrono::duration<double> elapsed_seconds = end-start;

	
    	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n" ;
	
	    return 0;
}
