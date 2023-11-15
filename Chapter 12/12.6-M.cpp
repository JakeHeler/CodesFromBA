#include <iostream>


class Member {
public:
	static auto CreateMember(int age, bool man)
	{
		id++;	// static 데이터 멤버
		auto ret = new Member;

		// static 함수에서 직접 데이터 멤버를 가져올 수 없고 생성된 객체로 접근
		ret->age = age;
		ret->isMale = man;

		return ret;
	}

	int age;
	bool isMale;

	int getID() { return id; };

private:
	static int id;
};

// static 데이터 멤버 초기화. 이때 static 키워드를 다시 지정하지 않음.

int Member::id = 0;

int main()
{


	Member* m1 = Member::CreateMember(20,true);
	std::cout << "Member ID =" << m1->getID() <<"\n"; 
	std::cout << "Age =" << m1->age << " Male = " << m1->isMale <<"\n";


	Member* m2 = Member::CreateMember(33,false);
	std::cout << "Member ID =" << m2->getID() <<"\n" ;
	std::cout << "Age =" << m2->age << " Male = " << m2->isMale <<"\n";


	return 0;
}
