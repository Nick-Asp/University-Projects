#include "Rearrange.h"
#include "Individual.h"
#include "BinaryNode.h"
#include <iostream>

using namespace std;

//Rearrange uses all the constructors in the individual class.

Rearrange::Rearrange() : Individual() {}

Rearrange::Rearrange(int length) : Individual(length) {}

Rearrange::Rearrange(BinaryNode *head) : Individual(head) {}

Rearrange::Rearrange(string input) : Individual(input) {}

Rearrange::~Rearrange(){}

void Rearrange::execute(int k){

	//First section makes sures that k is non negative number.

	unsigned int d = 0;

	string originalBinary = getString();
	
	if (k < 0)
	{
		d = -k;
	}

	else{

		d = k;
	}

	while(d > originalBinary.size()){

		d = d - originalBinary.size();
	}

	//This fucntion uses string operations to implement execute mainly due to the fact that strings come indexed.

	string newBinary;

	for (unsigned int i = d -1 ; i < originalBinary.size(); ++i)
	{
		newBinary.push_back(originalBinary.at(i));
	}

	//Dependent comes from the fact that if k is the last binary in the sequence the next binarys are considered to start from the front of the sequence.

	unsigned int dependent;

	if (d == originalBinary.size())
	{
		dependent = originalBinary.size() - 1;
	}

	else{

		dependent = originalBinary.size() - d;
	}

	for (unsigned int i = 0; i < dependent; ++i)
	{
		newBinary.push_back(originalBinary.at(i));
	}

	//Iterate through the list changing all of the binary no's to be consistent with the new
	//Rearranged string.

	BinaryNode* temp;
 	
 	temp = firstNode;

 	int counter = 0;

 	while(temp != 0){

 		temp->binary = (charConvert(newBinary,counter));

 		counter++;

 		temp = temp->nextNode;

 	}

}