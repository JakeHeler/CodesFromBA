#include <iostream>


class Member {
public:
	// 테스트 함수에 friend 지정자 사용 
	friend void TestMemberClass();

	int GetZip() { return ZipCode; }
private:
	int Phone;
	int ZipCode;
	int RegisterDate;

	void ChangeCode(int code) { ZipCode = code; }
	void ChangePhone(int no) { Phone = no; };
};

void TestMemberClass()
{
	Member m;
	
	// friend 함수이기 때문에 Member 클래스 모든 멤버에 접근이 가능
	m.ChangeCode(12345);
	std::cout << m.ZipCode<<"\n";

	m.ChangePhone(9874);
	std::cout << m.Phone;
}

int main()
{

	TestMemberClass();
	
	// friend 함수는 해당 클래스의 멤버 함수가 아니기 때문에 아래처럼 접근이 안 됨
	Member m;
	// m.TestMemberClass();

	return 0;
}

