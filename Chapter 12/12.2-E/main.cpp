#include "Character.h"
int main()
{
     	int power;

     	Character c;

     	// ���� �߻�. private ������ ����� ���� ����
     	c.LifePower = 100;
	
	    c.SetLifePower(100);
 
     	power = c.GetLifePower();

        return 0;
}
