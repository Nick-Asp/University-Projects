#ifndef PaperDoll_H
#define PaperDoll_H

#include <string>
#include "Player.h"

class PaperDoll : public Player
{
public:
	
	PaperDoll();

	PaperDoll(std::string);
	
	~PaperDoll();
	
	std::string performMove();

	void resetMove();

private:

	int m_rotation;

};

#endif