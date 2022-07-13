#include <iostream>
//reference is an alias of a value, reference to the actual value
// A pointer has its own memory address and size on the stack whereas
//a reference shares the same memory address (with the original variable) but also takes up some space on the stack.


int change_num(int &num)
{
    num = 45;
    return num;
    
}

int main()
{
    std::cout<<"Hello"<<std::endl;
    int num = 10;
    std::cout<<"Num before reference "<<num<<std::endl;
    change_num(num);
    std::cout<<"Num after reference "<<num<<std::endl;    

    return 0;
}