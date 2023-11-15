#include "Character.h"

int main()
{
     // int 타입 변수 선언.
     int power;

     // Character 클래스 타입 변수 선언
     Character c;

     // 데이터 멤버에 값을 대입
     c.AttackPower = 100;

     // 멤버  함수 호출
     power = c.GetLifePower();

     // 멤버  함수 호출
     c.MoveForward();

     return 0;
}
