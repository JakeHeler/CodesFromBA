#include "Jack.h"
#include "Tom.h"


int main()
{
	// ������ Jack Ŭ���� ��ü�� Character Ŭ���� ������ ����
	Character* my = new Jack (100, 200, 150);

	my->AttackWithFoot();	

	my = new Tom();
	my->AttackWithFoot();	

	return 0;
}

