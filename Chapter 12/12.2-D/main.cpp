#include "Character.h"

int main()
{
     // int Ÿ�� ���� ����.
     int power;

     // Character Ŭ���� Ÿ�� ���� ����
     Character c;

     // ������ ����� ���� ����
     c.AttackPower = 100;

     // ���  �Լ� ȣ��
     power = c.GetLifePower();

     // ���  �Լ� ȣ��
     c.MoveForward();

     return 0;
}
