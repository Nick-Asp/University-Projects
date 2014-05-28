#include "Avalanche.h"
#include <string>

Avalanche::Avalanche(){}

Avalanche::Avalanche(std::string name) : Player(name){}

Avalanche::~Avalanche(){}

//Avalanche is a mostly empty class, it just overloads the perfromMove fucntion from the player class and simply returns "Rock"

std::string Avalanche::performMove(){
	
		return "Rock";
}
