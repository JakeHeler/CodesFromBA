#pragma once
#include "Character.h"

class Tom : public Character{
public :
	int KillerPower = 200;// 
	// �Ϻ� ����Լ� ����
	Tom() 
	{
		LifePower = 300; 
		AttackPower = 100; 
		DefensePower = 400;
		ID = TOM;
	};
	
	Tom(int l , int a, int d) : Character(l,a,d) { ID = TOM;};
	
	// ������ ���� ��� �Լ� �������̵�
	void AttackWithFoot() { std::cout << "Tom Attack Foot\n"; };

	int GetKillerPower() { return KillerPower; };	

	// �� ĳ���͸� ���� ���� �ʻ�� ���� �Լ�
	void OwnKillerSkill() {};
};
