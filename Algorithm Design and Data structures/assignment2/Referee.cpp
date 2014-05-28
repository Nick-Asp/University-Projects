#include "Referee.h"
#include "Computer.h"
#include "Human.h"
#include <iostream>
#include <string>
#include "Player.h"

Referee::Referee(){}

Referee::~Referee(){}

std::string Referee::fight(Player *p1,Player *p2){
	
	//Performs the moves and stores them in a string. 
	
	std::string playerOnesMove = p1->performMove(); 
	
	std::string playerTwosMove = p2->performMove();
	//Checks the format of both moves using the checkAndFormatInput defined bellow.
	playerOnesMove = checkAndFormatInput(playerOnesMove);
	
	playerTwosMove = checkAndFormatInput(playerTwosMove);
	//If there is invalid input, it returns error, otherwise using the scoreGame function defined
	//we return the name of the winning player.
	
	if(playerOnesMove != "Error, invalid input" && playerTwosMove != "Error, invalid input"){

		int win = scoreGame(playerOnesMove,playerTwosMove);

		if (win == 1)
		{
			return p1->getName();
		}

		if (win == 2)
		{
			return p2->getName();
		}

		if (win == 0)
		{
			return "Tie";
		}

		return "Error";
	}
}

std::string Referee::bestOfFive(Player *p1, Player *p2,int index1, int index2){
	//Gets the names of both of the players and stores them in strings.
	//A string variable is also defined.
	std::string playerOnesMove = p1->getName(); 

	std::string playerTwosMove = p2->getName();

	std::string winner;
	//The scores used to determine who wins after 5 games.
	int p1Score = 0;

	int p2Score = 0;

	//Makes the players fight 5 times.
	for (int i=0; i < 6; i++){

		winner = fight(p1,p2);

		//Incraments the scores after the fight depending on who won.

		if(winner == p1->getName()){
		
			p1Score++;
		}
		
		else if(winner == p2->getName()){
		
			p2Score++;
		}
		//If there is a tie the winner is determined by the smaller index.
		else{
			if(index1 < index2){
				
				p1Score++;
			}
			
			else if(index2 < index1){

				p2Score++;	
			}	
		}
	}
		//Resets the moves of all the players after all 5 games.
		p1->resetMove();

		p2->resetMove();
	
	//Returns the winner depending on who has the higher score.
	if(p1Score > p2Score){
				
		return p1->getName();
	}
	
	else if(p2Score > p1Score){

		return p2->getName();
	}	
}

std::string Referee::checkAndFormatInput(std::string input){

for (int i = 0; i < input.size(); ++i){

			if (input.at(i) <= 'Z' && input.at(i) >= 'A')
			{
				input.at(i) = input.at(i) + 32; 
			}	

	}
	
	//Checks if the entry is valid, finds keywords so the user doesn't have to have a specific input.
	if (input.find("rock") != -1)
	{
		return "rock";
	}

	else if (input.find("scis") != -1)
	{
		return "scissors";
	}

	else if (input.find("pap") != -1)
	{
		return "paper";
	}

	return "Error, invalid input";

}

//Scores the game based on the input from the computer and the human.
int Referee::scoreGame(std::string inputOne, std::string inputTwo){

		if (inputOne == inputTwo){
			
			return 0;

		}

		if(inputOne == "rock" && inputTwo == "scissors"){
		
			return 1;
		
		}
		
		else if(inputOne == "paper" && inputTwo == "rock"){
		
			return 1;

		
		}

		else if(inputOne == "scissors" && inputTwo == "paper"){
		
			return 1;

		}
		
		else if(inputTwo == "rock" && inputOne == "scissors"){
		
			return 2;
		
		}
		
		else if(inputTwo == "paper" && inputOne == "rock"){
		
			return 2;
		
		}

		else if(inputTwo == "scissors" && inputOne == "paper"){


			return 2;
		}

		return 3;
}
