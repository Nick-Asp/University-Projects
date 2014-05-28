#ifndef INDIVIDUAL
#define INDIVIDUAL

#include "BinaryNode.h"
#include <string>

class Individual
{
public:
	Individual();
	Individual(int length);
	Individual(BinaryNode* head);
	Individual(std::string input);
	~Individual();
	std::string getString();
	BinaryNode *getFirstBit();
	void setFirstBit(BinaryNode *newHead);
	int getMaxOnes();
	int getLength();
	virtual void execute (int k);


protected:
	int lengthOfList;
	BinaryNode *firstNode;
	bool charConvert(std::string input,int index);


};

#endif