#include "Crescendo.h"
#include <string>


//Constructor, defining the number of played games to be zero.
Crescendo::Crescendo(){m_rotation = 1;}

Crescendo::Crescendo(std::string name) : Player(name){m_rotation = 1;}

Crescendo::~Crescendo(){}

std::string Crescendo::performMove(){

//Crescendo rotates between Paper, Scissors and Rock in that order. This is done by the conditionals bellow and incramenting the m_rotation every return
		if (m_rotation == 1)
		 {	
		 	m_rotation = 2;
			return "Paper";
			
		}
		else if (m_rotation == 2)
		{
			m_rotation = 3;
			return "Scissors";
			
		}

		else if(m_rotation == 3)
		{	
			m_rotation = 1;
			return "Rock";
		}
		

}

//This is an overload of the resetMove function and is used to reset m_rotation as required in the specifications for this practical.

void Crescendo::resetMove(){
	
	m_rotation = 1;
}
