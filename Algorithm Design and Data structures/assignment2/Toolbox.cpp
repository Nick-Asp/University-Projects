#include "Toolbox.h"


//Constructor, defining the number of played games to be zero.
Toolbox::Toolbox(){}

Toolbox::Toolbox(std::string name) : Player(name){}

Toolbox::~Toolbox(){}

std::string Toolbox::performMove(){	

	return "Scissors";
}
