#include "Character.h"

int main()
{
	Character c = 500;		// 에러 발생. 타입이 맞지 않음
	Character c1 = Character(500);	
	Character c2 = (Character)500;	
	Character c3(500);		

	Character ch = { 500,100,200 };		// 에러 발생. 타입이 맞지 않음
	Character ch1 =  Character{ 500,100,200 };	
    	
	return 0;

}
