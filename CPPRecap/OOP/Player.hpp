#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
//thesec constructors are overloaded as it takes advantage of
// parametric polymorphism (multiple functions of same name, different params)
class Player
{

private:
    std::string name;
    int health;
    int xp;
    
public:
   
    Player();
    Player(std::string name_value);
    Player(std::string name_value,int health_value,int xp_value);
    ~Player();

};

#endif // PLAYER_HPP
