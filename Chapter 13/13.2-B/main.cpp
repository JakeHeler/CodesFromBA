#include "Jack.h"
#include "Tom.h"


void CheckPower(Character* ch)
{
	// �ϱ�ó�� ID �� ������ ������ �������� ��ȯ�� �ʿ� ����
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
