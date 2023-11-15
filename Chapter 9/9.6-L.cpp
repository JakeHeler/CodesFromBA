#include <iostream>
#include <chrono>
#include <coroutine>

// gcc에서 옵션 확인. 그리고 실행시 문제가 발생하면 library 확인 필요
// gcc : -std=c++20 옵션.
// export LD_LIBRARY_PATH=/usr/local/lib:/usr/lib:/usr/local/lib64:/usr/lib64

struct MyYield {
    	struct promise_type;
    	using handle_type = std::coroutine_handle<promise_type>;

    	struct promise_type {
        	MyYield get_return_object() 
		{ 
			return MyYield{ handle_type::from_promise(*this)}; 
		}
        	auto initial_suspend() { return  std::suspend_always(); } 
        	auto final_suspend() noexcept { return std::suspend_never(); }
        	void unhandled_exception() {}
        	void return_void() {}
        	auto yield_value(unsigned long long int v) 
		{ 
			value = v; 
			return  std::suspend_always{}; 
		}
        	unsigned long long int value;

    	};
    
    	MyYield(handle_type h) : myHandle(h) {}
    	handle_type myHandle;


    	auto operator()()
    	{
        	unsigned long long int val =  myHandle.promise().value;
		// 이것은 myHandle.resume() 동일함.
		myHandle();
       		return val;
    	} 



};

// 코루틴 함수
MyYield CreateID()
{
    	int id = 0;
    	while (true)
    	{
        	co_yield ++id;
    	}
}

 // 일반 함수
 int CreateID_Other()
 {
        static int id = 0;
        return ++id;
 }

 
int main()
{ 
    	int sum=0;
	auto my = CreateID();
    	
	for (int j = 0; j <= 10000; j++)
    	{
        	sum +=my();
        }
	std::cout<<"sum ="<<sum;
   
        return 0;
}
