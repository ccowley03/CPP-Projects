#include <iostream>
// Includes elements of the same type
// Fixed Size

void printarr(int arr[],int len)
{
    std::cout<<"[";
    for(int i = 0;i<len;i++)
    {
        std::cout<<arr[i];
        std::cout<<",";
    }
    
    std::cout<<"]"<<std::endl;
}
int main()
{
    std::cout<<"Hello"<<std::endl;
    int scores[10] = {};
    int score = 0;
    for(int i =0;i<10;i++)
    {
        std::cout<<"Enter "<<i+1<<"th Score"<<std::endl;
        std::cin>>score;
        scores[i] = score;
 
    }
    printarr(scores,10);
    
    return 0;
}