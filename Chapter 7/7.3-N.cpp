struct st{
    int ar[10]={0};
	
	int& ChangeArray(int index) 
    	{ 
        		return ar[index]; 
    	}


	int& GetValue()
	{
		int a=10;
		return a;
	}
};

int main()
{
    	st mydata;
    
    	int a = mydata.ChangeArray(0);

    	mydata.ChangeArray(1) = 10;
		return 0;
}
