#ifndef Bureaucrat_H
#define Bureaucrat_H

#include <string>
#include "Player.h"

class Bureaucrat : public Player
{
public:
	
	Bureaucrat();

	Bureaucrat(std::string);
	
	~Bureaucrat();
	
	std::string performMove();

};

#endif