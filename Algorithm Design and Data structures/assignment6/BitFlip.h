#ifndef BITFLIP
#define BITFLIP

#include "Individual.h"

class BitFlip : public Individual
{
public:
	BitFlip();
	BitFlip(int length);
	BitFlip(std::string);
	BitFlip(BinaryNode*);
	~BitFlip();
	void execute(int k);
};

#endif