#ifndef INTNODE
#define INTNODE

class IntNode
{
public:
	
	IntNode();
	~IntNode();
	IntNode(int data);
private:

	int data;
	IntNode *nextNode;

	friend class Stack;
};

#endif