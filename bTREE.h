#pragma once
#include <string>
#include <queue>
#include "treeNode.cpp"
using namespace std;

//Nodes must
//hold a pseudo - time stamp(integer, non - unique)[5]
//hold a 128 bit data component(string of 32 characters)[5]
//have 2 pointers to type node[5]
//be differentiable if they are a leaf node or not [5]

class bTREE
{

private:
	//some data structure to hold your treeNodes together ...
	//DATASTUCTURE treeNodes tree;
	//any helper private variables you need
	treeNode* tree;

public:
	bTREE();
	~bTREE();

	//counts the number of nodes in the bTREE
	int numberOfNodes(treeNode* root);

	//Identifies the leaves of the bTREE
	void isLeaf(treeNode *node);

	//inserts a new node (children nodes) and hashes info in parent nodes.
	int insert(string data);

	//returns an empty TreeNode/leaf.
	int findLeaf(treeNode* node);

	//Find the treeNode with the associated info in it's string variable
	bool callerfind(string);
	bool recursivefind(string, treeNode* node);

	//Locates the hash string passed in the parameters, in the tree, and returns a string of the path navigated through the tree.
	string locate(string);
	string recursiveLocate(string hashedWord, treeNode* node, string path);

	queue <treeNode*> *treeQ;
	treeNode* root; //Node of the tree.
	int ops = 0; //Stores amount of operations and translates to psuedo time stamp of each node.

	void displayRight(std::ostream & outfile, treeNode* subtree, std::string prefix);
	void displayLeft(std::ostream & outfile, treeNode* subtree, std::string prefix);
	void display(std::ostream& outfile);

	friend bool operator==(const bTREE& lhs, const bTREE& rhs);
	friend bool operator!=(const bTREE& lhs, const bTREE& rhs);


};
