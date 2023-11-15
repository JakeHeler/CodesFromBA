#include <iostream>
#include <coroutine>


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

            void HandleDestroy()
            {
                myHandle.destroy();
                myHandle = nullptr;
            }

            ~MyCo() { 

                if( myHandle)
                    myHandle.destroy();
            }

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

	// 코루틴 함수가 완료되면 핸들의 done() 함수는 true 을 반환함
    	if ( my.myHandle.done())
	{
	    	// Retured Value = 123 출력됨
		std::cout << "Retured Value =" << my.getRetValue() <<"\n";

	    	// 코루틴 핸들의 메모리를 해제함
	    	my.HandleDestroy();
	}
  
    
        return 0;
}
