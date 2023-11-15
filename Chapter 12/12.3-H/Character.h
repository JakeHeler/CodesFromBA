class Character
{
private:
	// 데이터 멤버 초기화 : 
	// 대입 방식 or 중괄호 방식 가능. 
	int LifePower = 100; // int LifePower {100};  OK
	
	int AttackPower;
	int DefensePower;

public:
	// 다수의 생성자. 선언과 정의를 같이 함.
	explicit Character() {};	// 디폴트 생성자
	explicit Character(int l) 
	{ 
		LifePower =l ;
	};
	explicit Character(int l, int a , int d=100)	// 기본값 인자 설정
	{
		LifePower =l ;
		AttackPower = a;
		DefensePower = d;
	};	



	 int GetLifePower() { return LifePower; };
	 void SetLifePower( int Power) { LifePower = Power; };


     void MoveForward();
     void MoveBackward();
     void AttackWithFist();
     void AttackWithFoot();
};
