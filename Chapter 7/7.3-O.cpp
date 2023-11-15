int func()
{
    return 10;
}

int main()
{
    	int a = 0;
    	int& refL = a;		
	
    	int&& refR1 = a ;	    // 에러 발생. 변수는 rvalue 참조형의 대상이 될 수 없음
    	int&& refR2 = a + 1;	
    	int&& refR3 = func();	
	return 0;
}
