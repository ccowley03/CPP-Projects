#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
//Only need one constructor that acts as 3
class Player
{

private:
    std::string name;
    int health;
    int xp;
    
public:
    Player(std::string name_value = "None",int health_value = 0,int xp_value = 0);
    ~Player();

};

#endif // PLAYER_HPP
