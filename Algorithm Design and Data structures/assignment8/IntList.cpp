#include "IntList.h"
#include "IntNode.h"
#include <iostream>

IntList::IntList(): head(0), middleOne(0), middleTwo(0), tail(0), noOfNodes(0) {}

IntList::~IntList(){

	IntNode *temp = head;

	IntNode *otherTemp;

	while(temp != 0){

		otherTemp = temp->nextNode;

		delete temp;

		temp = otherTemp;
	}
	
	middleOne = 0;
	
	middleTwo = 0;

	tail = 0;
}


void IntList::addInt(int x){

	//This function is not dependent on the length of the list and hence takes O(1)

	if (head == 0)
	{
		head = new IntNode(x);
		middleOne = head;
		tail = head;
		noOfNodes++;
	}

	else{

		IntNode* temp = tail;

		temp->nextNode = new IntNode(x);

		tail = temp->nextNode;
		
		noOfNodes++;

		if (noOfNodes%2 == 0)
		{
			middleTwo = middleOne->nextNode;
		}

		else{

			middleOne = middleOne->nextNode;
			middleTwo = 0;
		}
	}


}

void IntList::removeHead(){

//This function is not dependent on the length of the list and hence takes O(1)
//If there are no nodes the function will not run.

if (noOfNodes != 0)
	{
	
	//Temp is used to delete the head. Temp is deleted at the end

	IntNode* temp;

	temp = head;

	head = head->nextNode;

	noOfNodes--;

	//When a node is removed middleOne either remains itself and middleTwo becomes the node after
	//MiddleOne or middleOne becomes the next node.

	if (noOfNodes%2 == 0)
		{
			middleTwo = middleOne->nextNode;

		}

	else{

			middleOne = middleOne->nextNode;
			middleTwo = 0;
		}

	//The head node is deleted at the end in case the middleNode is the head
	//And as the middleNode is required in the above operations we can't delete the
	//head until the end of the function.

	delete temp;
}

}

int* IntList::findMiddleNode(){

	//This function is not dependent on the length of the list and hence takes O(1)

	int* returnValue;

	returnValue = new int[2];

	//Negative one is used as an indicator that there is no second middle,
	//as all of the integers stored in the list are meant to be non negative.

	if (noOfNodes == 0)
	{
		returnValue[0] = 0;
		returnValue[1] = -1;
		return returnValue;
	}

	else if (middleTwo != 0)
	{
		returnValue[0] = middleOne->data;
		returnValue[1] = middleTwo->data;
	}

	else{

		returnValue[0] = middleOne->data;
		returnValue[1] = -1;
	}

	return returnValue;

}

void IntList::printList(){

	//Print list is the only function that takes O(n)

	IntNode* temp;

	temp = head;

	if (noOfNodes == 0)
	{
		std::cout << "empty";
	}

	while(temp != 0){

		std::cout << temp->data;

		if (temp->nextNode != 0)
		 {
		 	std::cout << "->";
		 }

		temp = temp->nextNode;
	}
}