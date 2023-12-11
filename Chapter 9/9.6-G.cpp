#include <iostream>
#include <chrono>
#include <thread>
#include <string>

// 데이터 경합문제로 atomic 사용
std::atomic<int> sum = 0;
std::atomic<int> countdone = 0;

/*******************************************************
// gcc 에서 테스트를 할때 반드시 -pthread 옵션을 설정해야 됨.
*******************************************************/

void ReadFind(std::string file, int checkno)
{
    	int count = 5;
    	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    	sum += count;
    	countdone++;

}

void SearchFile(int id, int search)
{
    std::string name = "file" + std::to_string(id) + ".txt";
    	ReadFind(name, search);

}

void DisplayMenu()
{
    	while(true)
    	{
        		std::cout << "Display Menu\n";
        		std::this_thread::sleep_for(std::chrono::milliseconds(500));
                if (countdone == 2)
            		break;
    	}
}

int main()
{ 
    	auto start = std::chrono::steady_clock::now();
    	std::thread t1(SearchFile, 1, 10);
    	std::thread t2(SearchFile, 2, 10);
    	std::thread tmenu(DisplayMenu);

    	while(true)
    	{
        		if (countdone == 2)
            		break;
    	}

    	auto end = std::chrono::steady_clock::now();
    	std::chrono::duration<double> elapsed_seconds = end-start;
	
	
    	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";  

    	std::cout << "sum =" << sum<<"\n";	

           t1.join();
        t2.join();
        tmenu.join();
	    return 0;
}
