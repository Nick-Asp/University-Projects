#ifndef Computer_H
#define Computer_H

#include <string>
#include "Player.h"

class Computer : public Player
{
public:
	
	Computer();

	Computer(std::string);
	
	~Computer();
	
	std::string performMove();

};

#endif