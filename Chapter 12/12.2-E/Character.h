class Character
{
private:
     	int LifePower;

public:
     	int AttackPower;
    	int DefensePower;

public:
    	// private 데이터 멤버에 대해서는 멤버 함수를 통해서 접근 하도록 함.
	// 이것을 데이터 멤버에 대한 Get / Set 함수라고 함. 
	int GetLifePower() { return LifePower; };
	void SetLifePower( int Power) { LifePower = Power; };


      void MoveForward();
      void MoveBackward();
      void AttackWithFist();
      void AttackWithFoot();
};
