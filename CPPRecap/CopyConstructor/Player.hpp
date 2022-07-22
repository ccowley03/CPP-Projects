#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
//Copy Constructor
// Want a reference(Alias of the object we want) to be passed through
//Want it to not be changed (Const)
class Player
{

private:
    std::string name;
    int health;
    int xp;
    
public:
    Player(std::string name_value = "None",int health_value = 0,int xp_value = 0);
    Player(const Player &source);
    
    ~Player();

};

#endif // PLAYER_HPP
