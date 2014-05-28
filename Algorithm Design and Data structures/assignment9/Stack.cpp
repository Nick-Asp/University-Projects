#include "Stack.h"
#include "IntNode.h"

Stack::Stack(): tail(0), sizeOfStack(0) {}

Stack::~Stack(){}

void Stack::push(int value){

	//When a value is pushed onto the stack the nextNode is set to the tail and the tail is reset to the newly created node.

	IntNode *temp = new IntNode(value);

	temp->nextNode = tail;

	tail = temp;

	sizeOfStack++;
}

int Stack::pop(){

	//When a value is popped off the stack tail is set to the nextNode and the old tail is deleted and it's data is extracted.

	IntNode* temp = tail;

	tail = tail->nextNode;

	int returnValue = temp->data;

	delete temp;

	return returnValue;


}