#pragma once
#include "Character.h"

class Jack : public Character
{
public :
	int KillerPower = 100;	// 이 클래스에만 가지는 데이터 멤버
	
	// 부모 클래스의 데이터 멤버 사용 .함수 본체에서 파워 변수 초기화
	Jack() 
	{
		LifePower = 100; 
		AttackPower = 200; 
		DefensePower = 100;
		ID = JACK;
	};
	// 파워 관련 데이터 변수 초기화. 생성자 초기화 리스트: 부모 클래스 초기화
	Jack(int l , int a, int d) : Character(l,a,d) { ID = JACK;};

	void AttackWithFoot() { std::cout<<"Jack Attack Foot\n";};

	// 이 캐릭터만 가진 고유 필살기 공격 함수
	void OwnKillerSkill() {};
};
