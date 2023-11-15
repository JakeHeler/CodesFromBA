enum Color {Red, Green, Blue};
struct A {};
class MyClass{
public:
     	int a = 10;  	
   		int b {10};  	
		int c = {1};

		static const int MyID = 10;

  		int m1(0);	// 에러 발생. 괄호 방식의 초기화는 허용되지 않음	
    	int m();	// 함수 선언

     	A* ch; 		
     	Color color;  	

     	// 중첩 클래스 정의
     	class Nest{

           	int a; 
     	};
	Nest n;		
	
	void func(){}	
};

int main()
{
	MyClass my;
	int var = my.a;
	my.func();

	int data = MyClass::a;		// 에러 발생. 데이터 멤버는 생성된 객체를 통해서만 가능
	int id = MyClass::MyID;	
}
