#include "Character.h"
int main()
{
	Character c;	 			

	
	Character c1(500);		// Character(int) ȣ���
	Character c2(500,100,100);	// Character(int,int,int) ȣ���
	
	Character c3(500 , 100);	 
	
	// �����߻� . �����ڸ� ���� ȣ�� �� ���� ����
	c.Character(500);		

	
	Character ch{};		
	Character ch1{ 500 };		
	Character ch2{ 500,100,200 };

	// ����� Ÿ�� ��ȯ ����Ͽ� ��ü ����.
	Character c4 = Character(100);
	Character c5 = Character(100,200,300);

}
