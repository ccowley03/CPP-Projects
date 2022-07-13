#include <iostream>
#include <string>
int main()
{
    int *ptr = nullptr;//pointer points to nowhere not anywhere! 
    std::string *strptr = nullptr; //pointer to a string object
    int score {10};
    std::string str = "dave";
    strptr = &str;
    int nums[] = {20,30,40};
    
    int *numptr = nums;
    std::cout<<"second value is "<<*(numptr + 1)<<std::endl;
    
    std::cout<<"first value is "<<*(numptr++)<<std::endl; //INCREMENT AFTER USAGE
    
    std::cout<<"second value is "<<*(++numptr)<<std::endl; //INCREMENT FIRST
    ptr = &score;
    std::cout<<"address is "<<ptr<<std::endl;
    std::cout<<"value is "<<*ptr<<std::endl;
    
    int *int_ptr = nullptr;
    int_ptr = new int; //allocate an integer on the heap
    *int_ptr = 10;
    std::cout<<"value is "<<*int_ptr<<std::endl;
    
    
    delete int_ptr;
    return 0;
}