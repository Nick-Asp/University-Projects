#ifndef FistfullODollars_H
#define FistfullODollars_H

#include <string>
#include "Player.h"

class FistfullODollars : public Player
{
public:
	
	FistfullODollars();

	FistfullODollars(std::string);
	
	~FistfullODollars();
	
	std::string performMove();

	void resetMove();

private:

	int m_rotation;

};

#endif