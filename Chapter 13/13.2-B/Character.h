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
	// 다수의 생성자. 선언과 정의를 같이 함.
	Character() {};	// 디폴트 생성자
	Character(int l) 
	{ 
		LifePower =l ;
	};
	Character(int l, int a , int d=100)	// 기본값 인자 설정
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
