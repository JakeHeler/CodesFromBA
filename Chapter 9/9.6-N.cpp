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
        		auto final_suspend() noexcept { return std::suspend_never(); }
        		void unhandled_exception() {}

                	void return_value(int i) { retValue = i; }
        		int retValue;


        		auto yield_value(int v) 
			{
				value = v; 
				return std::suspend_always{};
			}
			int value;
    		};

    		cor_Handle  myHandle;
    		MyCo(cor_Handle  h) : myHandle(h) {}

		void resumeRoutine() { return myHandle.resume(); }
		int getYieldValue() { return myHandle.promise().value; }
        	int getRetValue() { return myHandle.promise().retValue; }
};

MyCo fun()
{
    	co_yield 0;
        co_return 123;		// return_value() 호출되고 final_suspend() 이동.
}

int main()
{
    	auto my = fun();
    	my.resumeRoutine();

	// Retured Value = -45178 쓰레기 값 출력됨
      	std::cout << "Retured Value =" << my.getRetValue() <<"\n";
	
	return 0;
}
