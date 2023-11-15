int Check(int) { return 0;}
void GetID() {}

// Non 타입 파라미터를 선언 시 함수 포인터 타입의 파라미터를 가지는 함수 템플릿
template<int (*pf)(int)> void CallFunc() {
	
	int var = 0;
	if( pf != nullptr)
		pf(var);
};

// 타입 파라미터를 가지는 함수 템플릿
template<typename T> auto CallAnyFunction(T obj ){ /* ... */ };

int main()
{

	CallFunc<&Check>();
	//CallFunc<&GetID>();	// 에러 발생. 함수 타입이 다름.
	

	CallAnyFunction<int (*)(int)>(Check);
	

	CallAnyFunction(GetID);	

	return 0;
}
