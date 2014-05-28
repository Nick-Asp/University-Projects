#ifndef INTQUEUE
#define INTQUEUE

#include "IntNode.h"

class intQueue
{
public:
	intQueue();
	~intQueue();

	void enQueue(char value);
	int deQueue();

private:
	IntNode* tail;
	IntNode* head;
	int sizeOfQueue;

};