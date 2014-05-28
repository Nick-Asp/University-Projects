#ifndef Toolbox_H
#define Toolbox_H

#include <string>
#include "Player.h"

class Toolbox : public Player
{
public:
	
	Toolbox();

	Toolbox(std::string);
	
	~Toolbox();
	
	std::string performMove();

};

#endif