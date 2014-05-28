#ifndef CHARQUEUE
#define CHARQUEUE

#include "charNode.h"

class charQueue
{
public:
	charQueue();
	~charQueue();

	void enQueue(char value);
	int deQueue();

private:
	charNode* tail;
	charNode* head;
	int sizeOfQueue;

};



#endif