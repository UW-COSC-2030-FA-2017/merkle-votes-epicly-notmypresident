#include "bTREE.h"

#include <iostream>
#include <queue>
#include <vector>
#include <iterator>
#include <sstream>


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	ops++;
	root = new treeNode();
}

bTREE::~bTREE()
{
	ops++;
	//Doesnt need to do anything.
}

int bTREE::numberOfNodes(treeNode* root)
{
	ops++;
	//if my rootnode is a leaf, return 1 node total.
	if (root->leaf == true)
	{
		ops++;
		return 1;
	}
	else
	{
		ops++;
		return(numberOfNodes(root->left) + 1 + numberOfNodes(root->right));
	}
}

void bTREE::isLeaf(treeNode * node)
{
	ops++;
	if (node->left == NULL && node->right == NULL)
	{
		ops++;
		node->leaf == true;
	}
	else
	{
		ops++;
		node->leaf == false;
	}
}

int bTREE::insert(string data)
{
	//Move data in the parent to the children and replace with a hash of the new data, and the parent's old data into the parent.
	ops++;
	treeNode* tmp;
	tmp->word = data;
	tmp->timeStamp = ops;
	tmp->left = NULL;
	tmp->right = NULL;

	if (root == NULL)
	{
		root = tmp;
		treeQ.push(tmp);
	}
	else if (treeQ.front()->left == NULL)
	{
		treeQ.push(tmp);
	}
	else if (treeQ.front()->right == NULL)
	{
		treeQ.front()->right == tmp;
		treeQ.push(tmp);
		treeQ.pop();
	}
	return 0;
}

int bTREE::findLeaf(treeNode* node)
{
	ops++;
	//cycle through nodes to find an empty leaf.
	if (node->left == NULL)
	{
		ops++;
		if (node->right == NULL)
		{
			ops++;
			return 0; //address to Node?
		}
		else
		{
			ops++;
			return findLeaf(node->right);
		}
	}
	else if (node->right == NULL)
	{
		ops++;
		return findLeaf(node->left);
	}
	return 0;
}


//Checks the root word data and see if it matches, if not, recurse left first, then right searching for a match. Return True if found and false if not.
bool bTREE::callerfind(string data)
{
	ops++;
	if (root->word == data)
	{
		ops++;
		return true;
	}
	else if (recursivefind(data, root->left) == false)
	{
		ops++;
		return recursivefind(data, root->right);
	}
	else
	{
		ops++;
		return true;
	}
}

bool bTREE::recursivefind(string data, treeNode* node)
{
	ops++;
	if (node->leaf == true)
	{
		ops++;
		if (node->word == data)
		{
			ops++;
			return true;
		}
		else
		{
			ops++;
			return false;
		}
	}
	else
	{
		ops++;
		if (recursivefind(data, node->left) == false)
		{
			ops++;
			return recursivefind(data, node->right);
		}
	}
}

//Locates the hash and returns a string of the path there.
string bTREE::locate(string hashedWord)
{
	ops++;
	string path = "-";
	if (callerfind(hashedWord) == true)
	{
		ops++;
		//find the parent node the word exists in and concatenate the two words from the child nodes into a temp string. Return tmp.
		return recursiveLocate(hashedWord, root, path);
	}
	else
	{
		ops++;
		return ".";
	}
}

string bTREE::recursiveLocate(string hashedWord, treeNode* node, string path)
{
	ops++;
	if (node->word == hashedWord)
	{
		ops++;
		return path;
	}
	else
	{
		ops++;
		recursiveLocate(hashedWord, node->left, path + 'L');
		recursiveLocate(hashedWord, node->right, path + 'R');
	}
}

void bTREE::display(std::ostream& outfile)
{
	ops++;
	std::string prefix;
	if (root == NULL)
	{
		ops++;
		outfile << "-" << std::endl;
	}
	else
	{
		ops++;
		displayLeft(outfile, root->left, "    ");
		outfile << "---" << root->word << std::endl;
		displayRight(outfile, root->right, "    ");
	}
}

void  bTREE::displayLeft(std::ostream & outfile, treeNode* subtree, std::string prefix)
{
	ops++;
	if (subtree == NULL)
	{
		ops++;
		outfile << prefix + "/" << std::endl;
	}
	else
	{
		ops++;
		displayLeft(outfile, subtree->left, prefix + "     ");
		outfile << prefix + "/---" << subtree->word << std::endl;
		displayRight(outfile, subtree->right, prefix + "|    ");
	}
}

// Display the nodes connected to subtree.
// This is a right subtree.
// Use a line by line display, order nodes from left to
//   right, draw connecting lines.
void  bTREE::displayRight(std::ostream & outfile, treeNode* subtree, std::string prefix)
{
	ops++;
	if (subtree == NULL)
	{
		ops++;
		outfile << prefix + "\\" << std::endl;
	}
	else
	{
		ops++;
		displayLeft(outfile, subtree->left, prefix + "|    ");
		outfile << prefix + "\\---" << subtree->word << "|" << subtree->timeStamp << std::endl;
		displayRight(outfile, subtree->right, prefix + "     ");
	}
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