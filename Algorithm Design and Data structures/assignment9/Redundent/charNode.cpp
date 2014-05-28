#include "charNode.h"

//charNode is always initialised with the nextNode pointer being a null pointer.

charNode::charNode() : data(0), nextNode(0) {}

charNode::~charNode(){}

charNode::charNode(char data) : data(data), nextNode(0) {} 