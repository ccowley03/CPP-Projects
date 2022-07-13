#include <iostream>
#include <string>
#include <vector>


void print(int num)
{
    std::cout<<"Printing integer number "<<num<<std::endl;
    
    
}
void print(double num)
{
     std::cout<<"Printing double number "<<num<<std::endl;
}

void print(std::string s1,std::string s2)
{
     std::cout<<"Printing strings "<<s1<<"and "<<s2<<std::endl;
     
    
} 

void print(std::vector<std::string>strings)
{
    std::cout<<"Printing vector of strings ";
    for(auto s:strings)
    {
        std::cout<<s + " ";
        
    }
    std::cout<<std::endl;
    
    
}
int main()
{
    print(100);
    std::vector<std::string>strings;
    strings.push_back("Hello");
    strings.push_back("There");
    print(strings);
    
    return 0;
}