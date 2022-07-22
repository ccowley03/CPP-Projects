#include "Player.hpp"
//Using Constructor Initialization Lists
//Initiliazing members as they are being created

Player::Player(std::string name_value,int health_value,int xp_value)
:name{name_value},health{health_value},xp{xp_value}
{
}
Player::~Player()
{
}
