#ifndef BINARYNODE
#define BINARYNODE

class BinaryNode
{
public:
	BinaryNode();
	~BinaryNode();
	BinaryNode(bool bin);
private:
	bool binary;
	BinaryNode *nextNode;

	//I make all the classes in this practical friends for convinence, and I believe these classes should have full access to there node lists.
	//This is as there are no cases where restriction of the member variables values is necessary.
	//But I don't want to make the members public so I used friends instead.

	friend class Individual;
	friend class BitFlip;
	friend class Rearrange;
};

#endif