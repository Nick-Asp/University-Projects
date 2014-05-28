#include "Player.h"
#include <string>

Player::Player() : m_name("Name"){}

Player::Player(std::string name) : m_name(name){}
//Accessor for the name member.
std::string Player::getName(){

	return m_name;

}

//Cannot return anything as a player object doesn't have a move to perform. All derived classes
//overload the performMove function, the error return is just there for saftey.

std::string Player::performMove() {return "Error";}

//An empty function, reset move is only used by some of the derived classes and hence why it does nothing here.

void Player::resetMove(){};
