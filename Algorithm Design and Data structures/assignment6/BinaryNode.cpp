#include "BinaryNode.h"

//Binary node is always initialised with the nextNode pointer being a null pointer.

BinaryNode::BinaryNode() : binary(0), nextNode(0) {}

BinaryNode::~BinaryNode(){}

BinaryNode::BinaryNode(bool bin) : binary(bin), nextNode(0) {}