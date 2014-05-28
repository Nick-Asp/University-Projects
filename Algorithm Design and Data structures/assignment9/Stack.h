#ifndef STACK
#define STACK

#include "IntNode.h"

class Stack
{
public:
	Stack();
	~Stack();
	void push(int value);
	int pop();

private:
	IntNode* tail;
	int sizeOfStack;


	
};

#endif
