#include <iostream>

namespace MyVector{

	using size_t = unsigned int;

	template <typename _Ty>
	class allocator {
	public:
    		using size_type = size_t;	   
 		constexpr allocator() noexcept {}

		// 하기는 void*　operator new（size_t size) 함수를 직접 호출함
		// new 연산자를 사용하는 것이 아님.
	    	constexpr _Ty* allocate( const size_t _Count) 
	    	{
	        		size_t n = _Count * sizeof(_Ty);
	        		return static_cast<_Ty*>(::operator new(n));
	    	}
		// 하기는 void　operator delete（void*) 함수를 직접 호출함
	    	constexpr void deallocate(_Ty* const _Ptr) 
	    	{
	        		::operator delete(_Ptr);
	    	}
	};

	template <typename _Ty, typename _Alloc = allocator<_Ty>>
	class vector {
	public:
	 
	    	using pointer = _Ty*;
	    	using allot_type = _Alloc;
    		using size_type = typename _Alloc::size_type;

	    	constexpr vector() : _MyAllot(_Alloc()) {}

		// 설정 크기만큼 데이터 메모리를 할당하는 생성자
	    	constexpr explicit vector(const int _Count, const _Alloc& _Al = _Alloc())
		 : _MyAllot(_Al)
	    	{
		
	         	const auto _NewMemory = _MyAllot.allocate(_Count);

	
        			_ArrayStartPtr = _NewMemory;
					_ArrayLastPtr = _NewMemory + _Count;
					_ArrayEndPtr = _NewMemory + _Count;

				
				for(int i=0; i < _Count; ++i)
            			construct(_NewMemory+i);

	    	}

 			constexpr size_type size() const noexcept 
    		{
        		return static_cast<size_type>(_ArrayLastPtr - _ArrayStartPtr);
    		}

    		constexpr size_type capacity() const noexcept 
    		{
        		return static_cast<size_type>(_ArrayEndPtr - _ArrayStartPtr);
    		}

	
    		constexpr _Ty& operator[](const size_type _Pos) const noexcept 
    		{
        			return _ArrayStartPtr[_Pos];
    		}

    		constexpr _Ty& at(const size_t _Pos) 
    		{
        			return _ArrayStartPtr[_Pos];
    		}

	private:
    		template <class... Args>
    		pointer construct(pointer ptr, Args&&... _Val)
    		{
        		new (static_cast<void*>(ptr)) _Ty(std::forward<Args>(_Val)...);
        			return ptr;
    		}


	private:
	    	allot_type _MyAllot;
	    	// 할당된 메모리 포인터를 저장하는 데이터 멤버
	
    		pointer _ArrayStartPtr = nullptr;	// 할당된 메모리 첫 번째 주소
    		pointer _ArrayEndPtr = nullptr;	// 할당된 메모리 마지막 주소
    		pointer _ArrayLastPtr = nullptr;	// 저장된 데이터 크기의 마지막주소

	};

}

struct A{
	A()
    	{
        		std::cout << "A constructor\n";
    	}
  
};

int main()
{
	// 클래스 A 생성자가 정상적으로 호출됨.
	MyVector::vector<A> my(5);


	MyVector::vector<std::string> my1(5);
	my1[0] = "Hello";
	std::cout<<my1[0]; 

	
	return 0;
}
