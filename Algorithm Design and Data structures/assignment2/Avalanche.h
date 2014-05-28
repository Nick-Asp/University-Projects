#ifndef Avalanche_H
#define Avalanche_H

#include <string>
#include "Player.h"

class Avalanche : public Player
{
public:
	
	Avalanche();

	Avalanche(std::string);
	
	~Avalanche();
	
	std::string performMove();

};

#endif