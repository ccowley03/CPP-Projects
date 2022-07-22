#include "Player.hpp"
//Using Constructor Initialization Lists
//Initiliazing members as objects are being created
//Dont want the consteuctor to already initiliaze the object members
Player::Player()
: name{"None"},health{0}, xp{0}
{
    
    
}
Player::Player(std::string name_value)
:name{name_value},health{0},xp{0}
{
}
Player::Player(std::string name_value,int health_value,int xp_value)
:name{name_value},health{health_value},xp{xp_value}
{
}
Player::~Player()
{
}
