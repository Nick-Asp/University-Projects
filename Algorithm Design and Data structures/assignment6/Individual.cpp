#include "Individual.h"
#include "BinaryNode.h"
#include <string>
#include <iostream>

using namespace std;

Individual::Individual() : lengthOfList(0), firstNode(0) {}

Individual::Individual(int length) : lengthOfList(length) {

//Constructor given a list length, just iterates and creates the desired size list.
	
	firstNode = new BinaryNode();

	BinaryNode* temp;

	temp = firstNode;

	for (int i = 1; i < lengthOfList; ++i)
	{
		temp->nextNode = new BinaryNode();
		
		temp = temp->nextNode;
	}

}

Individual::Individual(BinaryNode *head){

//Creates the new list given the head of another list.
//First iteration sorts out the head for the new list
//The while loop sorts out the rest of the list.

	BinaryNode* oldListPtr = firstNode;

	firstNode = new BinaryNode(oldListPtr->binary);	

	oldListPtr = oldListPtr->nextNode;
	    
	while (oldListPtr != 0){

		firstNode->nextNode = new BinaryNode(oldListPtr->binary);

		firstNode = firstNode->nextNode;

	    oldListPtr = oldListPtr->nextNode;
	}
	
}

Individual::Individual(string input) : lengthOfList(input.size()) {


//Takes in a string and sets up a binary node list with the same values.
//Using the character convert function to convert the 1 and 0 characters to their boolean equivilent.

	firstNode = new BinaryNode();

	firstNode->binary = charConvert(input,0);

	BinaryNode* temp;

	temp = firstNode;

	for (unsigned int i = 1; i < input.size(); ++i)
	{
		temp->nextNode = new BinaryNode(charConvert(input,i));

		temp = temp->nextNode;
	}
}

Individual::~Individual(){

//Iterates through the entire list and deletes all the binary nodes.

	BinaryNode *temp = firstNode;

	BinaryNode *otherTemp;

	while(temp != 0){

		otherTemp = temp->nextNode;

		delete temp;

		temp = otherTemp;
	}

	delete firstNode;
}

std::string Individual::getString(){

//Returns the string equvilent of the binary node linked list.

	string returnString;

	BinaryNode* temp;
 	
 	temp = firstNode;

	while (temp != 0){

		if (temp->binary == 0)
		{
			returnString.push_back('0');
		}

		else
		{
			returnString.push_back('1');
		}

		temp = temp->nextNode;
	}

	return returnString;
}

void Individual::setFirstBit(BinaryNode *newHead){

	firstNode = newHead;
}

int Individual::getMaxOnes(){

//Returns the max number of 1's in a sequence of 1's

	string binarySequence = getString();

	int maxOnes = 0;

	int counter = 0;

	for (unsigned int i = 0; i < binarySequence.size(); ++i)
	{
		if (binarySequence.at(i) == '0')
		{
			if (counter > maxOnes)
			{
				maxOnes = counter;
			}

			counter = 0;
		}

		else{

			counter++;
		}	
	}

	return maxOnes;
}

int Individual::getLength(){

	return lengthOfList;
}

BinaryNode* Individual::getFirstBit(){

	return firstNode;
}

void Individual::execute(int k){}

bool Individual::charConvert(string input, int index){

	if ('1' == input.at(index))
	{
		return 1;
	}

	else{

		return 0;
	}
}