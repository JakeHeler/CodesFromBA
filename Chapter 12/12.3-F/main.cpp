#include "Character.h"
int main()
{
	Character c;	 			

	
	Character c1(500);		// Character(int) 호출됨
	Character c2(500,100,100);	// Character(int,int,int) 호출됨
	
	Character c3(500 , 100);	 
	
	// 에러발생 . 생성자를 직접 호출 할 수가 없음
	c.Character(500);		

	
	Character ch{};		
	Character ch1{ 500 };		
	Character ch2{ 500,100,200 };

	// 명시적 타입 변환 사용하여 객체 생성.
	Character c4 = Character(100);
	Character c5 = Character(100,200,300);

}
