class Character
{
public:
      // 데이터 멤버(data member)
      int LifePower;
      int AttackPower;
      int DefensePower;

      // 멤버 함수(member function)
      int GetLifePower() { return LifePower; };  // 클래스 내에서 함수 선언 및 정의
      void MoveForward();
      void MoveBackward();
      void AttackWithFist();
      void AttackWithFoot();
};
