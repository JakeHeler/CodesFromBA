#include "Character.h"
int main()
{
     	int power;

     	Character c;

     	// 에러 발생. private 데이터 멤버의 접근 에러
     	c.LifePower = 100;
	
	    c.SetLifePower(100);
 
     	power = c.GetLifePower();

        return 0;
}
