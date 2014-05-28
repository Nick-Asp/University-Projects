#ifndef Tournament_H
#define Tournament_H

#include "Player.h"
#include "Computer.h"
#include "Human.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Toolbox.h"
#include "FistfullODollars.h"
#include "PaperDoll.h"
#include "Crescendo.h"
//#include "RandomComputer"
//#include "AdvancedComputer"
#include <string>
#include <vector>


class Tournament
{
public:

	Tournament();

	std::vector<Player*> returnPlayerFromInput(std::string input,std::vector<Player*>);

	Player* determineFromLetters(std::string input);

	std::string runTournament();
	
};

#endif