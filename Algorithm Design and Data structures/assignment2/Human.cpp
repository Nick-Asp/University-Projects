#include "Human.h"
#include <iostream>
#include <string.h>

Human::Human(){}

Human::Human(std::string name) : Player(name) {}

Human::~Human(){}

std::string Human::performMove(){
	//Simply gets the current move.
	std::string inputMove;
	
	std::cout << "Please enter Rock, Paper or Scissors: ";
	
	std::cin >> inputMove;

	return inputMove;
}