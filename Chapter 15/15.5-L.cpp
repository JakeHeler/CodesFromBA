#include <type_traits>

template<typename T>
bool IsPrimeNumber(T num)
{
	// 정수 및 양수를 확인함
	static_assert(std::is_integral_v<T>, " Use integral types !!!");
	static_assert(std::is_unsigned_v<T>, " Use unsinged !!!");

     	for(int i=2; i<num ; i++){
		if( num % i == 0) 
			return false;
     	}
    	return true;
}
int main()
{
	unsigned int num1 =10;
	int num2 = -13;

	auto a = IsPrimeNumber(num1);	// 정상 동작

	// 자연수가 아니기 때문에 Use unsinged !!! 에러 메시지 발생
	// 에러 메시지는 템플릿 코드 내에 static_assert 이 설정된 해당 라인을 보여줌
	// 아래 사용된 코드라인이 아님. 
	auto b = IsPrimeNumber(num2);	
	
	// 정수가 아니기 때문에 오류 메시지 발생. 
	// 타입 체크하는 것과 별도로 타입이 서로 맞지 않아 컴파일 에러도 함께 발생함
	auto c = IsPrimeNumber(10.5);	
	
	return 0;
}
