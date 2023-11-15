#include <type_traits>

template<typename T>
requires (std::is_integral_v<T> && std::is_unsigned_v<T>)
bool IsPrimeNumber(T num)
{
	for(int i=2; i<num ; i++){
		if( num % i == 0) 
			return false;
     	}
     	return true;
}

// requires 구문 :  함수 원형 뒤에 위치.
template<typename T> bool Function(T a)  requires std::is_integral_v<T>;

int main()
{
	unsigned int num1 =10;
	int num2 = -13;	
	auto a = IsPrimeNumber(num1);	// 정상 동작

	// 자연수가 아니기 때문에 에러 발생. 여기 사용된 코드의 라인 넘버를 알려줌.
	auto b = IsPrimeNumber(num2);	
	return 0;
}
