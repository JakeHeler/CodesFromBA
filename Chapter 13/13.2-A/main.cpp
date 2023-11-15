#include "Jack.h"
#include "Tom.h"


int main()
{
	// 생성된 Jack 클래스 객체를 Character 클래스 포인터 지정
	Character* my = new Jack (100, 200, 150);

	my->AttackWithFoot();	

	my = new Tom();
	my->AttackWithFoot();	

	return 0;
}

