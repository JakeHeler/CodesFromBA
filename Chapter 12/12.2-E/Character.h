class Character
{
private:
     	int LifePower;

public:
     	int AttackPower;
    	int DefensePower;

public:
    	// private ������ ����� ���ؼ��� ��� �Լ��� ���ؼ� ���� �ϵ��� ��.
	// �̰��� ������ ����� ���� Get / Set �Լ���� ��. 
	int GetLifePower() { return LifePower; };
	void SetLifePower( int Power) { LifePower = Power; };


      void MoveForward();
      void MoveBackward();
      void AttackWithFist();
      void AttackWithFoot();
};
