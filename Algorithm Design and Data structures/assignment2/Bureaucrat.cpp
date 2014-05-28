#include "Bureaucrat.h"



Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name) : Player(name){}

Bureaucrat::~Bureaucrat(){}

//Bureaucrat is a mostly empty class, it just overloads the perfromMove fucntion from the player class and simply returns "Rock"

std::string Bureaucrat::performMove(){
		
		return "Paper";
}
