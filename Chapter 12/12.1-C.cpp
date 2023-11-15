class MyClass{
public:
	int m = 10;
	// 일반 열거형 타입 정의 : 해당 열거 리스트는 클래스의 멤버가 됨.
	enum Color {Red, Green, Blue};
};

int main()
{
    	MyClass my;
    	int b = my.Blue;
 
    	MyClass* pmy = new MyClass;
    	int g = pmy->Green;

    	int r = MyClass::Red; // MyClass::Color::Red 이런 형태도 가능함.
}

