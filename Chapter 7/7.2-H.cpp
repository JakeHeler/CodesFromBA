void func(int* p)
{ 
    *p = 100;
}

void allotmemory(int* ptr)
{ 
    ptr = new int;
}

auto allotmemory()
{ 
    auto ptr = new int;
    return ptr;
}

int main()
{
     	int i = 0;
     	int* p =  &i;

     	func(p);	

	    p = (int*) 0x10;
	    //func(p);


	
     	int* ptr = nullptr;
     	allotmemory(ptr);

	    //  ptr는 nullptr 를 가지고 있음. 여기에 값을 쓰게 되면 오동작 발생.
  	     *ptr = 1;


	    ptr = allotmemory();
	    if( ptr != nullptr)
         	*ptr = 1;
	    return 0; 
}
