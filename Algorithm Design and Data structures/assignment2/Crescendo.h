#ifndef Crescendo_H
#define Crescendo_H

#include <string>
#include "Player.h"

class Crescendo : public Player
{
public:
	
	Crescendo();

	Crescendo(std::string);
	
	~Crescendo();
	
	std::string performMove();

	void resetMove();

private:

	int m_rotation;

};

#endif