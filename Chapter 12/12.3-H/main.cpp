#include "Character.h"

int main()
{
	Character c = 500;		// ���� �߻�. Ÿ���� ���� ����
	Character c1 = Character(500);	
	Character c2 = (Character)500;	
	Character c3(500);		

	Character ch = { 500,100,200 };		// ���� �߻�. Ÿ���� ���� ����
	Character ch1 =  Character{ 500,100,200 };	
    	
	return 0;

}
