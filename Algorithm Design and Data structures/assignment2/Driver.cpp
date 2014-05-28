#include <iostream>
#include "Tournament.h"
#include "Player.h"
#include "Computer.h"
#include "Human.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Toolbox.h"
#include "FistfullODollars.h"
#include "PaperDoll.h"
#include "Crescendo.h"
#include "Referee.h"
//#include "RandomComputer"
//#include "AdvancedComputer"
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	//The Driver function simply creates a tournament object and uses it to run a tournament and returns the winner from the tournament function.
	
	Tournament myTournament;

	string winner = myTournament.runTournament();

	cout << "And the winner of the match is: " << winner << endl; 

	return 0;
}
