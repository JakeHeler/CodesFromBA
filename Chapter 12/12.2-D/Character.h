class Character
{
public:
      // ������ ���(data member)
      int LifePower;
      int AttackPower;
      int DefensePower;

      // ��� �Լ�(member function)
      int GetLifePower() { return LifePower; };  // Ŭ���� ������ �Լ� ���� �� ����
      void MoveForward();
      void MoveBackward();
      void AttackWithFist();
      void AttackWithFoot();
};
