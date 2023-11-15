#include <iostream>
#include <coroutine>


// gcc에서 옵션 확인. 그리고 실행시 문제가 발생하면 library 확인 필요
// gcc : -std=c++20 옵션.
// export LD_LIBRARY_PATH=/usr/local/lib:/usr/lib:/usr/local/lib64:/usr/lib64

struct MyCo {
        	struct promise_type;
        	using cor_Handle = std::coroutine_handle<promise_type>;

    	struct promise_type {
        		MyCo get_return_object() 
				{
	 				return MyCo{ cor_Handle::from_promise(*this) };
	 			}
        		auto initial_suspend() { return std::suspend_never(); } 
        		auto final_suspend() noexcept { return std::suspend_always(); }
        		void unhandled_exception() {}
        		void return_void() {}

        		auto yield_value(int v) 
				{
					value = v; 
					return std::suspend_always{};
				}
				int value;
    	};
    	cor_Handle  myHandle;
    	MyCo(cor_Handle  h) : myHandle(h) {}

    	// 코루틴 함수에서 멈추고 있을 때 루틴을 재개하는 함수. 핸들을 이용함.
		void resumeRoutine() { return myHandle.resume(); }

		// 핸들을 이용해 promise_type의 멤버 변수를 접근함
		int getYieldValue() { return myHandle.promise().value; }
};

MyCo co_f()
{
    	std::cout<<"co routine Start\n";
    	co_yield 10;
    	std::cout<<"co routine End\n" ;
}

int main()
{ 
    	auto my= co_f();
    	std::cout << "Get Value= " << my.getYieldValue() << "\n"; 
	
    	my.resumeRoutine();
	
	return 0;
}
