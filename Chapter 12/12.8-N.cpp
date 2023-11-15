#include <iostream>
#include <cstring>

struct VarData
{
	static constexpr int BUF_SIZE = 256;

	enum Type { FromChar, FromInt, FromLongLong } type;

    	union _Value
    	{
        		char ch[BUF_SIZE];
        		int it[BUF_SIZE];
        		long long ll[BUF_SIZE];
    	} value;

	VarData(Type t) { type = t ;}

	// 여러 데이터 타입을 대응하기 위해 템플릿 함수 선언
	template<typename T>
	void SetValue(T v,int count)
	{
		if( type == FromChar)
			std::memcpy(value.ch, v,count);

		else if( type == FromInt )
			std::memcpy(value.it, v, count*sizeof(int));

		else if ( type == FromLongLong)
			std::memcpy(value.ll, v, count*sizeof(long long));
	}
};

int main()
{
	VarData var(VarData::FromInt);

	const int count = 16;
	int in[count];
	
	for (int i=0; i < count; i++)
		in[i] = i;

	var.SetValue(in, count);
}
