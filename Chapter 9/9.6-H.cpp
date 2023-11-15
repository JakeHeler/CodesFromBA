#include <iostream>
#include <coroutine>

struct MyCo {

    	struct promise_type {
        		MyCo get_return_object() { return {}; }
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

};

MyCo co_f()
{
	    // int 타입을 전달하기 때문에 promise_type에서 yield_value(int v) 정의함
	    // 전달하는 타입에 따라 yield_value() 함수의 파라미터 타입을 설정하면 됨. 
    	std::cout<<"co routine Start\n";
    	co_yield 10;
    	std::cout<<"co routine End\n";
}

int main()
{ 
   	    co_f();	

    	for (;;);
}
