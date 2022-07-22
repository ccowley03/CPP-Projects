#include "Player.hpp"
//Using Constructor Initialization Lists
//Initiliazing members as they are being created

Player::Player(std::string name_value,int health_value,int xp_value)
:name{name_value},health{health_value},xp{xp_value}
{
}
Player::Player(const Player &source)
: name{source.name},health{source.health},xp{source.xp}
{
    std::cout<<"Copy made of: "<<source.name<<std::endl;
    
    
}
Player::~Player()
{
}
