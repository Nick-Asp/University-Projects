#include "PaperDoll.h"


//Constructor, defining the number of played games to be zero.
PaperDoll::PaperDoll(){}

PaperDoll::PaperDoll(std::string name) : Player(name){m_rotation = 1;}

PaperDoll::~PaperDoll(){}

std::string PaperDoll::performMove(){
	
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
				return "Scissors";
			}

}

void PaperDoll::resetMove(){
	
	m_rotation = 1;
}
