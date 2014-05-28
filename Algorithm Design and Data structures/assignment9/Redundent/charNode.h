#ifndef CHARNODE
#define CHARNODE

class charNode
{
public:
	
	charNode();
	~charNode();
	charNode(char data);
private:

	char data;
	charNode *nextNode;

	friend class charQueue;
};

#endif