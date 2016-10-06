#pragma once
#include "BSTNode.h"
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

class BST
{
public:
	BST(BSTNode *newRoot = nullptr);
	~BST();

	char *searchBST(BSTNode *&root, char symbol);
	void printBST(BSTNode *root);

	void insertInBST(char newSymbol, char *newCode); //this will call the private insert function

	void getTranslate();

	BSTNode *getRoot() const;

	void runApp();

	void destroyer();
private:
	BSTNode *root;
	BSTNode *makeNode(char newSymbol, char *newCode);
	void insertInBST(BSTNode *&root, char newSymbol, char *newCode); //this will call make node too
	void destroyer(BSTNode *root);
	ifstream input;
	ofstream output;
};
