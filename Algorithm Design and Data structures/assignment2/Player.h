#ifndef Player_H
#define Player_H
#include <string>

class Player
{
public:

	Player();

	Player(std::string);

	std::string getName();

	 virtual std::string performMove();

	 virtual void resetMove();


private:

	std::string m_name;
	
};

#endif