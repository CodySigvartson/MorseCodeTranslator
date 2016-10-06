#include "BSTNode.h"


BSTNode::BSTNode(char newSymbol, char *newCode)
{
	code = new char[10];
	symbol = newSymbol;
	strcpy(code, newCode);
	left = nullptr;
	right = nullptr;
}


BSTNode::~BSTNode()
{
}

void BSTNode::setSymbol(const char newSymbol)
{
	symbol = newSymbol;
}

void BSTNode::setCode(const char *newCode)
{
	strcpy(code, newCode);
}

char BSTNode::getSymbol() const
{
	return symbol;
}

char *BSTNode::getCode() const
{
	return code;
}

BSTNode *&BSTNode::getLeft()
{
	return left;
}

BSTNode *&BSTNode::getRight()
{
	return right;
}
