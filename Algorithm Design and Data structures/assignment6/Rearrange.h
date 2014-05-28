#ifndef REARRANGE
#define REARRANGE

#include "Individual.h"

class Rearrange : public Individual
{
public:
	Rearrange();
	Rearrange(int length);
	Rearrange(BinaryNode*);
	Rearrange(std::string);
	~Rearrange();
	void execute(int k);

};

#endif