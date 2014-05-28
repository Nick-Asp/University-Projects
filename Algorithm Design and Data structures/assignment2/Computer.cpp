#include "Computer.h"
#include <time.h>
#include <string>
#include <stdlib.h>

//Constructor, defining the number of played games to be zero.
Computer::Computer(){

	srand(time(NULL));

}

Computer::Computer(std::string name) : Player(name){}

Computer::~Computer(){}

std::string Computer::performMove(){
	//Computer randomly chooses between Rock, Paper and Scissors.
	int randomNumber = rand() % 99;

	if (randomNumber <= 33 ){
		
		return "Rock";
	}

	else if(randomNumber >= 66){

		return "Paper";
	}

	else {

		return "Scissors";

	}
}
