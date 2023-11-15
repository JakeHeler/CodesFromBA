#include <iostream>
#include <map>

struct StudentScore{

    	StudentScore() = default;
    	StudentScore(std::string str){ score[str]; }
    
    	void AddScore(std::string name, std::string sub, int sc){

		// 같은 이름이 있는지 확인.
        		auto search = score.find(name);
        		if (search != score.end())
        		{
            		search->second[sub] = sc;
        		}
        		else
        		{
                		std::map<std::string, int> data;
                		data[sub] = sc;
                		score[name] = data;
        		}
    	}

     	const auto& GetData() { return score; };
private:
       	std::map< std::string, std::map<std::string, int>> score;
};

int main()
{
    StudentScore sc;
        std::string name = "김철수";
        sc.AddScore(name,"언어", 85);
        sc.AddScore(name,"수학", 75);
        sc.AddScore(name,"영어", 95);


        name = "홍길동";
        sc.AddScore(name,"언어", 55);
        sc.AddScore(name,"수학", 100);
        sc.AddScore(name,"영어", 95);

        name = "이영희";
        sc.AddScore(name,"언어", 95);
        sc.AddScore(name,"수학", 100);
        sc.AddScore(name,"영어", 100);
 
        for (auto it = sc.GetData().begin(); it != sc.GetData().end(); ++it)
        {
            	std::cout << " 이름 : " << it->first << "\n";

             	for (auto it1 = it->second.begin(); it1 != it->second.end(); ++it1)
                 		std::cout <<" Subject = "<< it1->first<<" Score = "	<<it1->second<<"\n";

                std::cout << "\n";
        }
        
}
