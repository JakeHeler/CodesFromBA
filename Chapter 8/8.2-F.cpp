struct Member {
	int age;
	bool man;
	int phone ;

	// 여러 생성자들
	Member(int a) {}
	Member(int a, bool m, int p) {}
};

int main()
{
	Member m1 {30};		// Member(int a) 호출됨
	Member m2 (30);		// Member(int a) 호출됨
	Member m3= {30,true,123456};	// Member(int a, bool m, int p) 호출됨
	Member m4 (30,true,123456);		// Member(int a, bool m, int p) 호출됨
	
	// 명시적 타입 변환의 초기화
	Member m5 = Member(30);

	// 클래스 배열 : 초기화 식을 중괄호 안에 넣어 사용하면 됨
	Member mm[] = { {30,true,123}, {20}, {10} };	

	// 에러 발생 :　일치하는 생성자가 없음.
	Member m5 (30,true);

	return 0;
}
