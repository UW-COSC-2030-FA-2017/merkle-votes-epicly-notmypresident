#pragma once
#include <string>
using namespace std;

//Nodes must
//hold a pseudo - time stamp(integer, non - unique)[5]
//hold a 128 bit data component(string of 32 characters)[5]
//have 2 pointers to type node[5]
//be differentiable if they are a leaf node or not [5]

class bTREE
{
	struct treeNode
	{
		//The data stored in the node.
		string word = "";
		// psuedo int stored in node
		int timeStamp = 0;

		treeNode *left;
		treeNode *right;

		bool leaf = true; //Identifies as a leaf or not
	};

private:
	//some data structure to hold your treeNodes together ...
	//DATASTUCTURE treeNodes tree;
	//any helper private variables you need
	treeNode tree;

public:
	bTREE();
	~bTREE();

	//counts the number of nodes in the bTREE
	int numberOfNodes(treeNode* root);

	//Identifies the leaves of the bTREE
	void isLeaf(treeNode *node);

	//inserts a new node (children nodes) and hashes info in parent nodes.
	int insert(string data);
	int insert(string, treeNode* node);

	//returns an empty TreeNode/leaf.
	int findLeaf(treeNode* node);

	//Find the treeNode with the associated info in it's string variable
	bool callerfind(string);
	bool recursivefind(string, treeNode* node);

	//Locates the hash string passed in the parameters, in the tree, and returns a string of the path navigated through the tree.
	string locate(string);
	string recursiveLocate(string hashedWord, treeNode* node, string path);

	treeNode* root; //Root Node of the tree.
	int ops; //Stores amount of operations and translates to psuedo time stamp of each node.

	//Hashes the data for the parent nodes
	string hash(string);

	friend bool operator==(const bTREE& lhs, const bTREE& rhs);
	friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

	friend std::ostream& operator<<(std::ostream& out, const bTREE& p);

};
