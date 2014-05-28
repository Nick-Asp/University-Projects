#include "IntNode.h"

class IntList
{
public:
	IntList();
	~IntList();
	void addInt(int x);
	void removeHead();
	int* findMiddleNode();
	void printList();


private:
	//Four pointers, two middle pointers as the middle could be one number if the list is odd length
	//Or two pointers if the list is even length.
	IntNode* head;
	IntNode* middleOne;
	IntNode* middleTwo;
	IntNode* tail;
	int noOfNodes;
	//No of nodes isn't used as an index, only used for conditionals.
	
};