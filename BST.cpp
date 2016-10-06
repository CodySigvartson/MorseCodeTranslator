#include "BST.h"

void BST::runApp()
{
	BST bst;
	//printBST(root); //this was a test to print out my BST and made sure it printed out correctly and in order

	getTranslate();
}

BST::BST(BSTNode *newRoot)
{
	root = newRoot;
	//make temp variables to make node with
	char tempChar = '\0';
	char *tempCode = new char[10];
	char tempSpace = '\0';

	//open files
	input.open("MorseTable.txt", ios::in);
	//read from file until end
	while (!input.eof())
	{
		input.get(tempChar); //read in the symbol
		input.get(tempSpace); //store the space into between symbol and morse into a buffer
		input.getline(tempCode, 10); //read in the morse 
		insertInBST(tempChar, tempCode); //insert the read info into BST
	}
	input.close();
}

BST::~BST()
{
	//call function that traverses post-order and deletes
	destroyer();
}

void BST::destroyer()
{
	//call private destroyer
	destroyer(root);
}

//private member function
void BST::destroyer(BSTNode *root)
{
	if (root != nullptr) //list isn't empty
	{
		destroyer(root->getLeft()); //go left as possible
		destroyer(root->getRight()); //go right
		delete root; //delete current node
	}
}

BSTNode *BST::getRoot() const
{
	return root;
}

BSTNode *BST::makeNode(char newSymbol, char *newCode)
{
	BSTNode *node = new BSTNode(newSymbol, newCode);
	return node;
}

void BST::insertInBST(char newSymbol, char *newCode)
{
	//call the private insert function
	insertInBST(root, newSymbol, newCode);
}

//private
void BST::insertInBST(BSTNode *&root, char newSymbol, char *newCode)
{
	//check if tree is empty
	if (root == nullptr)
	{
		//insert node into tree (inserting the root)
		BSTNode *node = makeNode(newSymbol, newCode);
		root = node; 
	}
	else
	{
		//check if the node being inserted is less ASCII than root
		if (newSymbol < root->getSymbol())
		{
			insertInBST(root->getLeft(), newSymbol, newCode);
		}
		else if(newSymbol > root->getSymbol()) //check if ASCII is greater (go right)
		{
			insertInBST(root->getRight(), newSymbol, newCode);
		}
	}
}

void BST::getTranslate()
{
	//temp vairables
	char tempChar = '\0';
	char *code = new char[10];
	//open file to read from
	input.open("Translate.txt", ios::in);

	//read the .txt that needs to be translated into morse
	while (!input.eof())
	{
		input.get(tempChar); //read in individual character
		tempChar = toupper(tempChar); //convert to upper
		if (tempChar != '\n') //don't read in the new line character
		{
			//set code to what searchBST returns which will be the corresponding morse code for the plaintext
			code = searchBST(root, tempChar);
			cout << code << " ";
		}
		else if (tempChar == '\n') //if newline is read, print a new line
		{
			cout << endl;
		}
	}
	cout << endl; //formatting
	input.close();
}

char *BST::searchBST(BSTNode *&root, char symbol)
{
	if (root == nullptr) //search was unsuccessful/or list is empty
	{
		return nullptr;
	}
	char *morse = new char[10]; //allocate a string to return the correct translation
	if (symbol == root->getSymbol())
	{
		strcpy(morse, root->getCode());
		return morse;
	}
	if 
		(symbol < root->getSymbol()) //ASCII is less, go left
	{
		morse = searchBST(root->getLeft(), symbol);
		return morse;
	}
	else if (symbol > root->getSymbol())
	{
		morse = searchBST(root->getRight(), symbol);
		return morse;
	}
}

void BST::printBST(BSTNode *root)
{
	//check that list isn't empty
	if (root != nullptr)
	{
		printBST(root->getLeft());
		cout << root->getSymbol() << ": " << root->getCode() << endl;
		printBST(root->getRight());
	}
}