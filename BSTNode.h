#pragma once
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

class BSTNode
{
public:
	BSTNode(char newSymbol = '\0', char *newCode = "");
	~BSTNode();

	//mutators
	void setSymbol(const char newSymbol);
	void setCode(const char *newCode);
	
	//accessors
	char getSymbol() const;
	char *getCode() const;
	BSTNode *&getLeft();
	BSTNode *&getRight();
private:
	char symbol;
	char *code;
	BSTNode *left;
	BSTNode *right;
};
