#include <iostream>
#include <string>

struct MyData
{
	enum Type { IntData, DoubleData, StringData } type;

	// 익명(anonymous) 공용체 선언
	union
	{
		int i;
		double db;
		std::string str= "";	// 공용체에서는 최대 한 개 멤버는 초기화 가능
	};

	void SetValue(double value)
	{
		if (type == IntData)
			i = (int)value;

		else if (type == DoubleData)
			db = value;
	}

	void SetString(std::string value)
	{
		if (type == StringData)
			str = value;
	}

	MyData(Type t)
	{
		type = t;
		new (&str) std::string;
	}	 

	~MyData() {}
};

int main()
{
	MyData my(MyData::StringData);
	my.SetString("Hello");
}
