#include <iostream>
#include <vector>
//Move constructors (moves an object instead of copying it)
//copies the address of the resource from the source to current and nulls outs the source pointer
//'steals' the data
class Player
{
private:
   int *data;
   
public:
   Player(int d);
   
   //Copy Constructor
   Player(const Player &source);
   //Move Constructor
   Player(Player &&source) noexcept;
   ~Player();
   
};

Player::Player(int d)
{
    data = new int;
    *data = d;
    std::cout<<"Constructor"<<std::endl;
}
Player::Player(const Player &source) //creates new object and copies all data
: Player{*source.data}
{
    std::cout<<"Deep Copy"<<std::endl;
    
}
Player::Player(Player &&source) noexcept
   :data{source.data}
{
    source.data = nullptr;
       
    std::cout<<"Move constructor - moving resource"<<std::endl;
       
}
Player::~Player()
{
    if(data != nullptr)
    {
        std::cout<<"Freeing data for :" <<*data<<std::endl;
        
    }
    else
    {
        std::cout<<"Freeing data for nullptr"<<std::endl;
    }
}

   
     
   

int main()
{
    std::vector<Player>Players;
    Players.push_back(Player{10}); //moving the temporary object and steal the data
    //temporary object doesnt have any data anymore the object inside the vector does
    
    return 0;
}