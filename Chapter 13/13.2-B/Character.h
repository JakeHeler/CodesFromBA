#pragma once

#include <iostream>

enum CharacterID { JACK , TOM };

class Character
{
public:


	int LifePower;
	int AttackPower;
	int DefensePower;
	CharacterID ID;


public:
	// �ټ��� ������. ����� ���Ǹ� ���� ��.
	Character() {};	// ����Ʈ ������
	Character(int l) 
	{ 
		LifePower =l ;
	};
	Character(int l, int a , int d=100)	// �⺻�� ���� ����
	{
		LifePower =l ;
		AttackPower = a;
		DefensePower = d;
	};	



	 int GetLifePower() { return LifePower; };
	 void SetLifePower( int Power) { LifePower = Power; };

	 virtual void AttackWithFist() { std::cout<<"Base Fist";};
	 virtual void AttackWithFoot() { std::cout<<"Base Foot";};

	 virtual int GetKillerPower() { return 0; };


     void MoveForward();
     void MoveBackward();

};
