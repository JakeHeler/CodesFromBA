#pragma once
#include "Character.h"

class Tom : public Character{
public :
	int KillerPower = 200;// 
	// 일부 멤버함수 생략
	Tom() 
	{
		LifePower = 300; 
		AttackPower = 100; 
		DefensePower = 400;
		ID = TOM;
	};
	
	Tom(int l , int a, int d) : Character(l,a,d) { ID = TOM;};
	
	// 발차기 공격 멤버 함수 오버라이딩
	void AttackWithFoot() { std::cout << "Tom Attack Foot\n"; };

	int GetKillerPower() { return KillerPower; };	

	// 이 캐릭터만 가진 고유 필살기 공격 함수
	void OwnKillerSkill() {};
};
