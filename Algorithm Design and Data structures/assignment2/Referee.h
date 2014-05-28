#ifndef Referee_H
#define Referee_H

#include "Human.h"
#include "Computer.h"
#include <string>
#include "Player.h"

class Referee
{
public:

	Referee();
	
	~Referee();

	std::string fight(Player *p1, Player *p2);

	std::string bestOfFive(Player *p1, Player *p2,int index1, int index2);
	

private:

	int scoreGame(std::string, std::string);

	std::string checkAndFormatInput(std::string input);

};

#endif
