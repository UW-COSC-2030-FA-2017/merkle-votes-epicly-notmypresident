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
		node->leaf = true;
	}
	else
	{
		ops++;
		node->leaf = false;
	}
}

int bTREE::insert(string data)
{
	//Using a tmp variable...
	ops++;
	treeNode* tmp = new treeNode();
	tmp->word = data;
	tmp->timeStamp = ops;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->leaf = true;

	//If our tree hasn't had any nodes put in it yet, just assign the tmp values to it, and push it into the q.
	if (root->leaf == true)
	{
		root = tmp;
		root->leaf = false;
		treeQ.push(root);
	}
	//Check to see if the node in front has an open spot to it's left. If it doesn't, assign the tmp node to the spot and push in temp
	else if (treeQ.front()->left == NULL)
	{
		treeQ.front()->left = tmp;
		treeQ.push(tmp);
	}
	//if the spot to the right of the node in the front of the q is free, fill it and then pop the front node off the q (because it now has 2 childen nodes and cant connect anymore to it)
	else if (treeQ.front()->right == NULL)
	{
		treeQ.front()->right = tmp;
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
	//if the root has the data, return true
	if (root->word == data)
	{
		ops++;
		return true;
	}
	//if not, check left for the data. If not left, check right.
	else if (recursivefind(data, root->left) == false)
	{
		ops++;
		return recursivefind(data, root->right);
	}
}

bool bTREE::recursivefind(string data, treeNode* node)
{
	ops++;
	//if it's a leaf node, then it has potential to having our data. If not, look left and then right for a leaf.
	if (node->leaf == true)
	{
		ops++;
		//If we found a leaf, check to see if it has our data, if not, start all over.
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
		//adds the left and right directions to our path string recursively till we find our hash we were looking for
		recursiveLocate(hashedWord, node->left, path + 'L');
		recursiveLocate(hashedWord, node->right, path + 'R');
	}
}

//prints. Dont need to mess with anything down here.
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

//queue<treeNode*> bTREE::accessQ()
//{
	//return treeQ;
//}

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