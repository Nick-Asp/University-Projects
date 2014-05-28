#include "IntNode.h"

//IntNode is always initialised with the nextNode pointer being a null pointer.

IntNode::IntNode() : data(0), nextNode(0) {}

IntNode::~IntNode(){}

IntNode::IntNode(int data) : data(data), nextNode(0) {} 