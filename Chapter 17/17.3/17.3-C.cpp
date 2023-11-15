#include <iostream>

namespace MyVector{

	using size_t = unsigned int;

	template <typename _Ty>
	class allocator {
	public:
    		using size_type = size_t;	   
 		constexpr allocator() noexcept {}


	    	constexpr _Ty* allocate( const size_t _Count) 
	    	{
	        		size_t n = _Count * sizeof(_Ty);
	        		return static_cast<_Ty*>(::operator new(n));
	    	}

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


		template <class... Args>
		constexpr decltype(auto) emplace_back(Args&&... _Val) 
		{
      		
        		if (_ArrayEndPtr != _ArrayLastPtr) 
        		push_already_alloted_memory(std::forward<Args>(_Val)...);
			
		
	        	else
        			push_allot_new_memory(std::forward<Args>(_Val)...);

        		return 0;
    	}


    	constexpr void push_back(const _Ty& _Val) 
    	{ 
        		emplace_back(_Val);
    	}

    	template <class... Args>
    	void  push_already_alloted_memory(Args&&... _Val)
    	{
         	construct(_ArrayLastPtr, std::forward<Args>(_Val)...);
         	++_ArrayLastPtr;
    	}

    	template <class... Args>
    	void push_allot_new_memory(Args&&... _Val)
    	{
         	const auto oldsize = size();
            	const auto newsize = oldsize + 1;
			
		
            	auto newCapacity = calculate_newcapacitity(newsize);
            
            	const pointer _NewMemory = _MyAllot.allocate(newCapacity);

            		// 할당된 메모리에 추가된 데이터 생성.
            	construct(_NewMemory + oldsize, std::forward<Args>(_Val)...);
            
        		// 메모리 재할당으로 기존의 데이터를 다시 생성함 -- (3)
        		for(int i=0;i < oldsize;++i)
        			construct(_NewMemory+i, *(_ArrayStartPtr+i));


		    change_array_pointer(_NewMemory, newsize, newCapacity);  
	    }

	    size_type calculate_newcapacitity( size_type size)
	    {
		    const size_type _Nowcapacity = capacity();
		    auto ratio = 1.0;

         	size_type _Nextcapacity = _Nowcapacity + _Nowcapacity * ratio;
        
       		 if (_Nextcapacity < size) 
         		return size;
        
        		return _Nextcapacity;
        }

    	void change_array_pointer(const pointer _Newvec, const size_type _Size,	 const size_type _Newcapacity)
    	{
       		if (_ArrayStartPtr)
        	{
         		for (int i = 0; i < _Size; ++i)
         			destroy(_ArrayStartPtr + i);

         		_MyAllot.deallocate(_ArrayStartPtr);
        	}
   		    _ArrayStartPtr = _Newvec;
   		    _ArrayLastPtr  = _Newvec + _Size;
   		    _ArrayEndPtr   = _Newvec + _Newcapacity;
   	    }
   
	    constexpr void destroy(pointer ptr) 
   	    {
        		ptr->~_Ty();
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

 	MyVector::vector<int> my;
      
    for (int Index = 0; Index < 10; Index++)
    {
           	std::cout<<"Index= "<<Index<<" capacity= "<<my.capacity()<< "\n";
           	my.push_back(1);
    }


	
	return 0;
}
