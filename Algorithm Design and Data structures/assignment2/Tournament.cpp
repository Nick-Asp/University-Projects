#include "Tournament.h"
#include "Referee.h"
#include "Player.h"
#include "Computer.h"
#include "Human.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Toolbox.h"
#include "FistfullODollars.h"
#include "PaperDoll.h"
#include "Crescendo.h"
#include <string>
#include <iostream>
#include <vector>

Tournament::Tournament(){};

std::string Tournament::runTournament(){

	//Our main referee, steve, used throught the tournament.
	
	Referee *steve;

	steve = new Referee;

	//The vector used to store the pointers of all the players.
	
	std::vector<Player *> players;
	
	//The array 	

	int winNo[4];

	std::string winner;

	std::string input;

	std::cout << "Please enter the name of players" << std::endl;

	for (int i = 0; i < 8; ++i)
	{
		std::cin >> input;
		players = returnPlayerFromInput(input,players);
	}
	
	int matchCounter = 0;
	
	std::cout << "ROUND 1\n\n" << std::endl;

	//Round 1
		for (int i = 0; i < 8; i = i + 2)
		{
			std::cout << "Round 1, match " << matchCounter + 1 << " currently playing are "
			 << players.at(i)->getName() << " and " << players.at(i+1)->getName() << std::endl;
			
			winner = steve->bestOfFive(players.at(i),players.at(i+1),i,i+1);
			
			std::cout << "And the winner is " << winner << std::endl;
			
			if (winner == players.at(i)->getName() || winner == "Tie")
			{
				winNo[matchCounter] = i;
			}

			else{

				winNo[matchCounter] = i+1;
			}

			matchCounter++;
		}

		matchCounter = 0;

		std::cout << "The winners of this round are: " << players.at(winNo[0])->getName()
			<< " " << players.at(winNo[1])->getName() << " "  << players.at(winNo[2])->getName() 
			<< " " << players.at(winNo[3])->getName() << std::endl;
		
		//Round 2
		std::cout << "\n\nROUND 2\n\n" << std::endl;

		for (int i = 0; i < 4; i = i + 2)
		{
			std::cout << "Round 2, match " << matchCounter + 1 << " currently playing are " 
			<< players.at(winNo[i])->getName() << " and " << players.at(winNo[i+1])->getName() << std::endl;

			winner = steve->bestOfFive(players.at(winNo[i]),players.at(winNo[i+1]),winNo[i],winNo[i+1]);

			std::cout << "And the winner is " << winner << std::endl;
			
			if(winner == "Tie"){
				
				if(winNo[i] < winNo[i+1]){

					winNo[matchCounter] = i;
				}
				
				else{
					winNo[matchCounter] = i + 1;
				}
								

			}			
			
			else if (winner == players.at(i)->getName())
			{
				winNo[matchCounter] = i;
			}

			else{

				winNo[matchCounter + 1] = i+1;
			}
			
			matchCounter++;

		}

		//Round 3
		std::cout << "\n\nROUND 3\n\n" << std::endl;
		
		winner = steve->fight(players.at(winNo[0]),players.at(winNo[1]));
		
		if(winner == "Tie"){
				
				if(winNo[0] < winNo[1]){

					return players.at(winNo[0])->getName();
				}
				
				else{
					return players.at(winNo[0])->getName();
				}					
			}
		
		return winner;
}



	std::vector<Player*> Tournament::returnPlayerFromInput(std::string input, std::vector<Player*> returnVector)
	
	{

	Player *returnPlayer;

	for (int i = 0; i < input.length(); ++i)
	{

			if (input.at(i) == 'A')
			{
				returnPlayer = new Avalanche("Avalanche");
							
				returnVector.push_back(returnPlayer);
			}

			else if (input.at(i) == 'B')
			{
				returnPlayer = new Bureaucrat("Bureaucrat");
			
				returnVector.push_back(returnPlayer);
			}

			else if (input.at(i) == 'T')
			{
				returnPlayer = new Toolbox("Toolbox");
			
				returnVector.push_back(returnPlayer);
			}

			else if (input.at(i) == 'C')
			{
				returnPlayer = new Crescendo("Crescendo");
			
				returnVector.push_back(returnPlayer);
			}

			else if (input.at(i) == 'P')
			{
				returnPlayer = new PaperDoll("PaperDoll");
			
				returnVector.push_back(returnPlayer);
			}

			else if (input.at(i) == 'F')
			{
				returnPlayer = new FistfullODollars("FistfullODollars");
			
				returnVector.push_back(returnPlayer);
			}
		}

return returnVector;


}
