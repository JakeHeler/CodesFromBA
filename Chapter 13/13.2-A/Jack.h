#pragma once
#include "Character.h"

class Jack : public Character
{
public :
	int KillerPower = 100;	// �� Ŭ�������� ������ ������ ���
	
	// �θ� Ŭ������ ������ ��� ��� .�Լ� ��ü���� �Ŀ� ���� �ʱ�ȭ
	Jack() 
	{
		LifePower = 100; 
		AttackPower = 200; 
		DefensePower = 100;
		ID = JACK;
	};
	// �Ŀ� ���� ������ ���� �ʱ�ȭ. ������ �ʱ�ȭ ����Ʈ: �θ� Ŭ���� �ʱ�ȭ
	Jack(int l , int a, int d) : Character(l,a,d) { ID = JACK;};

	void AttackWithFoot() { std::cout<<"Jack Attack Foot\n";};

	// �� ĳ���͸� ���� ���� �ʻ�� ���� �Լ�
	void OwnKillerSkill() {};
};
