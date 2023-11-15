#include "Jack.h"
#include "Tom.h"


void CheckPower(Character* ch)
{
	// 하기처럼 ID 로 나누고 별도로 인위적인 변환이 필요 없음
	//if (ch->ID == JACK)
	//Jack* jack = static_cast<Jack*>(ch);
	
	std::cout << ch->GetKillerPower() << "\n";
}

int main()
{
	Character* my = new Jack();
	CheckPower(my);	

	my = new Tom();
	CheckPower(my);	


	return 0;
}
