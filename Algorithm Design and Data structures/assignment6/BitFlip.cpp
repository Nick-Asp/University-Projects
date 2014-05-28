#include "BitFlip.h"
#include "Individual.h"
#include "BinaryNode.h"
#include <iostream>

using namespace std;

BitFlip::BitFlip() : Individual() {}

BitFlip::BitFlip(int length) : Individual(length) {}

BitFlip::BitFlip(BinaryNode *head) : Individual(head) {}

BitFlip::BitFlip(std::string input) : Individual(input) {}

BitFlip::~BitFlip(){}

void BitFlip::execute(int k){

	//i is 1 as we aren't working with strings and the first index isn't 0

	int i = 1;

	//Circular counter, if length is 10 and input is 12, the k value is 2.

	while(k > lengthOfList){

		k = k - lengthOfList;
	}

	BinaryNode* temp = firstNode;

	//Flips the binary if i and k are the same otherwise is i is incremented.

	while (temp != 0)
	{
		if (i == k)
			{
				temp->binary = !(temp->binary);
			}

		temp = temp->nextNode;

		i++;
	}
}