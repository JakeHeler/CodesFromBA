#include <iostream>
#include <chrono>
#include <coroutine>
#include <vector>

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

	// 함수 호출 연산자 : 함수를 재개하거나 co_yield 값을 가져오는 함수를 대체할 수 있음. 
    	auto operator()()
    	{
        		 unsigned long long int val =  myHandle.promise().value;
		    // 이것은 myHandle.resume() 동일함.
		    myHandle();

        		return val;
    	} 

};

// 코루틴 함수
MyYield fibo(unsigned int n)
{
    if (n == 0)
        co_return
 
    co_yield 0;
    co_yield 1;

    unsigned long long a = 0;
    unsigned long long b = 1;
 
    for (unsigned i = 2; i < n; i++)
    {
       unsigned long long s = a + b;
        co_yield s;
        a = b;
        b = s;
    }
}

 // 일반 함수
auto fibo_other(int n)
{
  std::vector<unsigned long long int> arr(n+2, 0);

    arr[0] = 0;
    arr[1] = 1;
 
    for(int i = 2; i <= n; i++)
    {
       arr[i] = arr[i - 1]+arr[i - 2];
    }
    return arr[n];
}

auto fibonacci(unsigned long long int num)
{
    if (num <= 1) return num;
    else return fibonacci(num - 1) + fibonacci(num - 2);
}

int main()
{ 
       	const unsigned int num = 40;
    	auto my = fibo(num);
    	unsigned long long sum = 0;
        
    	auto start = std::chrono::steady_clock::now();
    
        for (int j = 1; j <= num; j++)
    	{
            	if (j == (num-1) || j == num)
            	{
                		sum += my();
            	}
            	else
                		my(); 
            
        }
      
        auto end = std::chrono::steady_clock::now();
    	std::chrono::duration<double> elapsed_seconds = end-start;
    	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n" ;

        std::cout << "sum = " << sum<<"\n";

        std::cout << "sum = " << fibonacci(num);
        
        return 0;
}
