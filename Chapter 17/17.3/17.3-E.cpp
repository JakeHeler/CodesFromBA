#include <iostream>

namespace MyList{

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


    	template< typename TNode>
    	class List_Iterator {
     	public: 
        		//using iterator_category = std::bidirectional_iterator_tag;

                using pointer =TNode*;
        		using reference = typename TNode::data_type&;
 
                using value_type = typename TNode::data_type;
        		using difference_type = int;
        
        		List_Iterator(pointer _Pnode) noexcept : _Ptr(_Pnode) {}

        		reference operator*() const noexcept {
            		return _Ptr->_Myval;
        		}

                List_Iterator& operator++() noexcept {
                    _Ptr = _Ptr->_Next;
                    return *this;
                }

        		List_Iterator operator++(int) noexcept {
            		_Ptr = _Ptr->_Next;
            		return *this;
        		}

        		List_Iterator& operator--() noexcept {
            		_Ptr = _Ptr->_Prev;
            		return *this;
        		}

        		bool operator==(const List_Iterator& _Right) const noexcept {
            		return _Ptr == _Right._Ptr;
        		}
     

                pointer _Ptr;
    	};



    template< typename T>
    struct List_Node {
       		using Node = List_Node<T>;
       		using data_type = T;

       		Node* _Next;   	// 다음 노드를 저장
       		Node* _Prev;    // 이전 노드를 저장
       		T  _Myval;   	// 저장되는 데이터
    };

    template< typename _Ty, typename _Alloc = allocator<_Ty>>
    class list {
    
    	public:
                using value_type = _Ty;
        		using Node = List_Node<_Ty>;
        		using pointer = _Ty*;
        		using allot_type = allocator<Node>;	
                using size_type = typename _Alloc::size_type;

       	 	    using iterator = List_Iterator<Node>;

        		list() :_MyAllot( allot_type())
        		{
            		const auto _Newhead = _MyAllot.allocate(1);
            
            		_Myhead = _Newhead;
                 	_Myhead->_Next = _Newhead;
            		_Myhead->_Prev = _Newhead;
         
        		}

      	        void push_back(const _Ty& _Val) 
                {
  
		             add_node(_Myhead, _Val);             
       	        }
	    
                void push_front(const _Ty& _Val) 
                { 
        	        add_node(_Myhead->_Next, _Val);   
    	        }	
        
                size_type size() const noexcept
                {
            	        return _Size;
                }

		        iterator begin() noexcept{
                 		return iterator(_Myhead->_Next);
        		}
        
        		iterator end() noexcept{
                    	return iterator(_Myhead);

        		}
       		
		        iterator insert(iterator position, const _Ty& x)
        		{
            		return iterator(add_node(position._Ptr,x));
        		} 

   	private:

                Node* add_node( Node* Where_node, const _Ty& _Val) noexcept 
		        {
                		
		      	        const auto NewNode = _MyAllot.allocate(1);
        
           		        construct(&NewNode->_Myval, _Val);
			
		
           		        const auto Node_Before_Add = Where_node->_Prev;

		                NewNode->_Next = Where_node;
          		        NewNode->_Prev = Node_Before_Add;

               	        Node_Before_Add->_Next = NewNode;
           		        Where_node->_Prev = NewNode;
              		
		    	        _Size++;
          		        return NewNode;
                }

                template <class... Args>
        	    pointer construct(pointer ptr, Args&&... _Val)
        		{
           		     new (static_cast<void*>(ptr)) _Ty(std::forward<Args>(_Val)...);
            		 return ptr;
        		}
    
        private:

        		allot_type _MyAllot;
        		int _Size = 0;
        		Node* _Myhead = nullptr;	// 처음 시작 노드 

    };

}

int main()
{
      	MyList::list<int> li;
     	li.push_back(1);
     	li.push_back(2);
     	li.push_back(3);
     	li.push_back(4);

     	auto ir = li.begin();
     	ir++;
         li.insert(ir , 10);

     	// 반복자 STL의 함수를 이용해 위치를 설정
	    auto ir1 = std::next(li.begin(), 3);
     	li.insert(ir1 , 50);

     	for (const auto x: li)
        		std::cout << x<< " ";	// 출력 1 10 2 50 3 4
	
	return 0;
}
