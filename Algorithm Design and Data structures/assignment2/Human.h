#ifndef Human_H
#define Human_H

#include <string>
#include "Player.h"

class Human : public Player
{

public:
	
	Human();
	
	Human(std::string name);

	~Human();
	
	std::string performMove();
	
	

};

#endif