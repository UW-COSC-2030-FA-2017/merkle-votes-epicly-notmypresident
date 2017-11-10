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
		string word;
		int timeStamp;

		treeNode *left;
		treeNode *right;

		bool leaf;
	};

private:
	//some data structure to hold your treeNodes together ...
	//DATASTUCTURE treeNodes tree;
	//any helper private variables you need

public:
	bTREE();
	~bTREE();

	int dataInserted();
	int numberOfNodes();

	//inserts a TreeNode with a string and int into a leaf (Empty Node)
	int insert(string, int);
	//returns an empty TreeNode leaf.
	int findLeaf();
	bool find(string);

	string locate(string);


	friend bool operator==(const bTREE& lhs, const bTREE& rhs);
	friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

	friend std::ostream& operator<<(std::ostream& out, const bTREE& p);

};
