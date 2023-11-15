#include <iostream>
#include <chrono>
#include <coroutine>
#include <queue>
#include <functional>
#include <thread>

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

// 람다 함수 저장을 위한 컨테이너 queue 클래스 사용
std::queue<std::function<bool()>> wait_queue;


using namespace std::chrono;

struct MyWaitRead {
        	int read_count = 0;

     	bool await_ready() { return false; }
     	void await_suspend(std::coroutine_handle<void> h) 
     	{ 
            	auto start = std::chrono::steady_clock::now();
       	            wait_queue.push( [start, h, out = time_out, this] 

                	{

			        if ( std::chrono::steady_clock::now() - start > out ) 
                   	{
                        		read_count=5;

                                h.resume();
                        		return true;
                    	} 
                    	else 
                        		return false;
                
                	});
        
     	}
     	int await_resume() { return read_count; }

     	std::chrono::milliseconds time_out = 1000ms;
};

int sum=0;

MyCo ReadFind(std::string file, int checkno)
{
    	int count = 0;
     	count= co_await MyWaitRead();
    	sum += count;

}

void SearchFile(int id, int search)
{
    	std::string name="file" + std::to_string(id)+".txt";
    	ReadFind(name, search);
}

int main()
{ 
    	int cn = 0;

    	auto start = std::chrono::steady_clock::now();

    	SearchFile(1,10);
    	SearchFile(2,10);

         while (!wait_queue.empty()) {
            	auto lm = wait_queue.front();

		        // queue에서 람다함수를 가져와서 호출함
            	if (! lm() ) {
                		wait_queue.push(lm); // 람다함수 저장
            	}
            	wait_queue.pop();	        // 가져온 람다함수를 queue에서 삭제

            	std::this_thread::sleep_for(std::chrono::milliseconds(1));
        	}
    	auto end = std::chrono::steady_clock::now();
    	std::chrono::duration<double> elapsed_seconds = end-start;

    	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n" ;

	std::cout << "Sum ="<<sum; 

	return 0;
}
