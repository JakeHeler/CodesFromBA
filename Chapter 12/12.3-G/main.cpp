#include "Character.h"

int main()
{
	// ����Ʈ ������ Character() ȣ���. 
	// ��ȣ�� ������� �ʾƵ� ���� ����. ex) new Character;
	Character *c  = new Character();	

	Character *c1 = new Character(500);	// Character(int) ȣ���
	
	// Character(int,int,int) ȣ���
	Character *c2 = new Character(500,100,200);	
	
	// �߰�ȣ�� �̿� �ʱ�ȭ ��ü ����. 
	Character* ch  = new Character {};
	Character* ch1 = new Character {500};
	Character* ch2 = new Character { 500,100,200 };

	return 0;

}
