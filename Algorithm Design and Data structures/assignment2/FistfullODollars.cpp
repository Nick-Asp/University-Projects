#include "FistfullODollars.h"


//Constructor, defining the number of played games to be zero.
FistfullODollars::FistfullODollars(){}

FistfullODollars::FistfullODollars(std::string name) : Player(name){m_rotation = 1;}

FistfullODollars::~FistfullODollars(){}

std::string FistfullODollars::performMove(){

		if (m_rotation == 1)
		 {	
		 	m_rotation = 2;
			return "Rock";
			
		}
		else if (m_rotation == 2)
		{
			m_rotation = 3;
			return "Paper";
			
		}

		else if(m_rotation == 3)
		{	
			m_rotation = 1;
			return "Paper";
		}

}

void FistfullODollars::resetMove(){
	
	m_rotation = 1;
}