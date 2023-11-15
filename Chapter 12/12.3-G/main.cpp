#include "Character.h"

int main()
{
	// 디폴트 생성자 Character() 호출됨. 
	// 괄호를 사용하지 않아도 문제 없음. ex) new Character;
	Character *c  = new Character();	

	Character *c1 = new Character(500);	// Character(int) 호출됨
	
	// Character(int,int,int) 호출됨
	Character *c2 = new Character(500,100,200);	
	
	// 중괄호를 이용 초기화 객체 생성. 
	Character* ch  = new Character {};
	Character* ch1 = new Character {500};
	Character* ch2 = new Character { 500,100,200 };

	return 0;

}
