class Character
{
private:
	// ������ ��� �ʱ�ȭ : 
	// ���� ��� or �߰�ȣ ��� ����. 
	int LifePower = 100; // int LifePower {100};  OK
	
	int AttackPower;
	int DefensePower;

public:
	// �ټ��� ������. ����� ���Ǹ� ���� ��.
	explicit Character() {};	// ����Ʈ ������
	explicit Character(int l) 
	{ 
		LifePower =l ;
	};
	explicit Character(int l, int a , int d=100)	// �⺻�� ���� ����
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
