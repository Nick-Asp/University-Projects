#include "charQueue.h"
#include "charNode.h"

charQueue::charQueue(): head(0), tail(0), sizeOfQueue(0) {}

charQueue::~charQueue(){}

void charQueue::enQueue(char value){

	charNode *temp = new charNode(value);
	
	if (sizeOfQueue == 0)
	{
		tail = temp;

		head = temp;
	}

	else {

		head->nextNode = temp;

		head = temp;
	}

	sizeOfQueue++;
}

int charQueue::deQueue(){


	charNode* temp = tail;

	tail = tail->nextNode;

	char returnValue = temp->data;

	delete temp;

	return returnValue;


}