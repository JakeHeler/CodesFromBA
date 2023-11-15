#include <iostream>
#include <map>   

int main()
{

    	std::map<int, std::string> chanelInfo = { {3,"EBS"}, {7,"KBS"},{11,"MBC"},{21,"BBC"} };

    	if (chanelInfo.insert({ 100,"CNN" }).second)
        		std::cout << "Insert OK\n";


    	chanelInfo[11] = "iMBC";


    	chanelInfo.erase(3);


    	for (auto it = chanelInfo.begin(); it != chanelInfo.end(); ++it)
          	std::cout <<" Channel Num = "<< it->first <<" Name :"<<it->second<<"\n";
}
