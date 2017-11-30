#include "bTREE.h"

#include <iostream>
#include <queue>


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	root->right = NULL;
	root->left = NULL;
	root->timeStamp = 0;
	ops++;
}

bTREE::~bTREE()
{
	//Doesnt need to do anything.
}

int bTREE::numberOfNodes(treeNode* root)
{
	//if my rootnode is a leaf, return 1 node total.
	if (root == NULL)
	{
		return 1;
	}
	else
	{
		return(numberOfNodes(root->left) + 1 + numberOfNodes(root->right));
	}
}

void bTREE::isLeaf(treeNode * node)
{
	if (node->left == NULL && node->right == NULL)
	{
		node->leaf == true;
	}
	else
	{
		node->leaf == false;
	}
}

int bTREE::insert(string data)
{
	//Move data in the parent to the children and replace with a hash of the new data, and the parent's old data into the parent.
	ops++;

	if (root->leaf == true)
	{
		root->word = data;
		root->timeStamp = ops;
		root->leaf == false;
	}
	else
	{
		if (insert(data, root->left) == -1) //If the helper function returns to this function, run the helper function to the right of the root.
		{
			insert(data, root->right);
		}
	}
	return ops; //number of operations taken.
}

//Helper function, if the root treeNode is not a leaf, this function takes over to iterate through all the root node's children.
int bTREE::insert(string data, treeNode* node)
{

	if (node->leaf == false) //if this node is also a parent...
	{
		if (node->right == NULL) //If this node is only a parent of ONE child node, return back to the previous insert function.
		{
			return -1;
		}
		else
		{
			//if this node is a leaf, insert our new data left by running the function one last time.
			insert(data, node->left);
		}
	}
	else
	{
		ops++;
		node->leaf == false; //set this new parent node to not be a leaf
		node->left = new treeNode; //create a node to the left of our new parent
		node->left->word = data; //assign variables to our new child node
		node->left->timeStamp = ops;
		node->left->leaf = true;

		ops++;
		node->right = new treeNode; //create the other child node for our new parent node (the parent node's word will be placed into this one.)
		node->right->word == node->word; //Copy in the parent Node's data (word) to child
		node->right->timeStamp = ops;
		node->right->leaf = true;

		node->word = node->word + node->left->word; //Add together the new data from our new child node and the old data from our parent and insert it back into parent.
		node->word = hash(node->word); //Then hashes the data from both child nodes and puts it in the parent.
		return 0;
	}
}

int bTREE::findLeaf(treeNode* node)
{
	//cycle through nodes to find an empty leaf.
	ops++;
	if (node->left == NULL)
	{
		if (node->right == NULL)
		{
			return 0; //address to Node?
		}
		else
		{
			return findLeaf(node->right);
		}
	}
	else if (node->right == NULL)
	{
		return findLeaf(node->left);
	}
	return 0;
}


//Checks the root word data and see if it matches, if not, recurse left first, then right searching for a match. Return True if found and false if not.
bool bTREE::callerfind(string data)
{
	if (root->word == data)
	{
		return true;
	}
	else if (recursivefind(data, root->left) == false)
	{
		return recursivefind(data, root->right);
	}
	else
	{
		return true;
	}
}

bool bTREE::recursivefind(string data, treeNode* node)
{
	if (node->leaf == true)
	{
		if (node->word == data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (recursivefind(data, node->left) == false)
		{
			return recursivefind(data, node->right);
		}
	}
}

//Locates the hash and returns a string of the path there.
string bTREE::locate(string hashedWord)
{
	string path = "-";
	if (callerfind(hashedWord) == true)
	{
		//find the parent node the word exists in and concatenate the two words from the child nodes into a temp string. Return tmp.
		return recursiveLocate(hashedWord, root, path);
	}
	else
	{
		return ".";
	}
}

string bTREE::recursiveLocate(string hashedWord, treeNode* node, string path)
{
	if (node->word == hashedWord)
	{
		return path;
	}
	else
	{
		recursiveLocate(hashedWord, node->left, path + 'L');
		recursiveLocate(hashedWord, node->right, path + 'R');
	}
}

//Hashes the data for the parent nodes
string hash(string word)
{
	return word;
}

bool operator==(const bTREE & lhs, const bTREE & rhs)
{
	if (lhs.root->word == rhs.root->word && lhs.root->timeStamp == rhs.root->timeStamp)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const bTREE & lhs, const bTREE & rhs)
{
	if (lhs.root->word != rhs.root->word || lhs.root->timeStamp != rhs.root->timeStamp)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//display our tree
std::ostream & operator<<(std::ostream & out, const bTREE & p)
{
	cout << "Time: " << p.root->timeStamp << "\nData: " << p.root->word;
	return out;
}