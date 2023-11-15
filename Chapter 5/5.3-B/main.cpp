#include <iostream>
#include <iostream>
#include "inVar.h"

int gVar = 0;
void SetData();

int main()
{
     SetData();
     std::cout<<"inVar = "<< inVar;
     std::cout<<"gVar = " << gVar;      
}
