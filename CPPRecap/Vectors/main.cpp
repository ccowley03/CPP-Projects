#include <iostream>
#include <vector>
//Dynamic Array during runtime size isnt fixed, changes
//Container in the CPP STD Library
//Bounds Checking!
int main()
{
    std::vector<int>numbers(5);
    numbers[0] = 5;
    std::cout<<numbers.at(0)<<std::endl;
    return 0;
}