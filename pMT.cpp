#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>

#include "pMT.h"
#include "bTREE.h"

/**
* @brief
* @param hashSelect a number corresponding to the hashfunction to use for this pMT
* @return
*/
pMT::pMT(int hashSelect)
{
	//All this needs to do is store the selected hash in a global variable
	selectedHash = hashSelect;
}

pMT::~pMT()
/**
* @brief destructor
* @return nada
*/
{
	//Do Nothing.
}

int pMT::insert(string vote)
/**
* @brief insert a vote and time into a leaf node of tree
* @param vote - a string
* @param time - an int representing the time
* @return the number of operations needed to do the insert, -1 if out of memory
*/

{
	myMerkle.ops++;
	int functionOps = myMerkle.ops;
	treeNode* tmp = new treeNode();
	treeNode* tmp2 = new treeNode();
	treeNode* tmp3 = new treeNode();
	tmp->word = vote;
	tmp->timeStamp = myMerkle.ops;
	tmp->left = NULL;
	tmp->right = NULL;

	tmp2 = findLeaf(myMerkle.root);
	tmp3 = tmp2;
	tmp2->leaf = false;
	tmp2->left = tmp;
	tmp2->right = tmp3;
	myMerkle.treeQ.push(tmp2);
	myMerkle.treeQ.push(tmp);
	adjustHash();

	return myMerkle.ops - functionOps;
}


treeNode* pMT::findLeaf(treeNode* start)
{
	treeNode* current = new treeNode();
	current = start;
	if (isLeaf(current) == true)
	{
		return current;
	}
	else
	{
		myMerkle.treeQ.push(current);
		findLeaf(current->left);
		findLeaf(current->right);
	}
}

bool pMT::isLeaf(treeNode* node)
{
	if (node->leaf == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void pMT::adjustHash()
{
	treeNode* tmp = new treeNode();
	while (!myMerkle.treeQ.empty())
	{
		tmp = myMerkle.treeQ.back();
		if (tmp->leaf == true)
		{
			myMerkle.treeQ.pop();
		}
		else 
		{
			if (selectedHash == 1)
			{
				tmp->word = hash_1(tmp->left->word + tmp->right->word);
			}
			else if (selectedHash == 2)
			{
				tmp->word = hash_2(tmp->left->word + tmp->right->word);
			}
			else
			{
				tmp->word = hash_3(tmp->left->word + tmp->right->word);
			}
			myMerkle.treeQ.pop();
		}
	}
}

/**
* @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
* @param vote, a string
* @param time, an int
* @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
* @return 0 if not found, else number of opperations required to find the matching vote
*/
int pMT::find(string vote, int hashSelect)
{
	if (hashSelect == selectedHash)
	{
		myMerkle.callerfind(vote);
		return myMerkle.ops + 1;
	}
	else
	{
		return 0;
	}
}

int pMT::findHash(string mhash)
/**
* @brief does this hash exist in the tree?
* @param mhash, a string to search for in the tree
* @return 0 if not found, else number of opperations required to find the matching hash
*/
{
	if (myMerkle.locate(mhash) == ".")
	{
		return myMerkle.ops + 1;;
	}
	return myMerkle.ops + 1;
}


string pMT::locateData(string vote)
/**
* @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
* @param vote, the data to search for
* @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
*/
{
	myMerkle.ops++;
	if (findHash(vote) == 0)
	{
		return ".";
	}
	return myMerkle.locate(vote);
}

string pMT::locateHash(string mhash)
/**
* @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
* @param mhash, the hash to search for
* @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
*/
{
	//The problem is the same as above.
	return locateData(mhash);
}



string pMT::hash_1(string key)
/**
* @brief A function that takes in a key and returns a hash of that key using some custom function
* @param key, a string
* @return a hash of the key
*/
{
	vector<int> keyInts;
	int length = key.size();
	for (int i = 0; i <= length; i++) {
		char temp = key.at(i);
		int temp2 = temp;
		keyInts.push_back(temp2);
	}
	int total = 0;
	string hash;
	for (int i = 0; i <= length; i++) {
		total = total + i;
	}
	hash = to_string(total);

	return hash;
}

string pMT::hash_2(string key)
/**
* @brief A function that takes in a key and returns a hash of that key using some custom function
* @param key, a string
* @return a hash of the key
*/
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;
	string queenb;


	for (std::size_t i = 0; i < key.length(); i++)
	{
		hash = hash * a + key[i];
		a = a * b;
	}

	queenb = to_string(hash);
	return queenb;
}

string pMT::hash_3(string key)
/**
* @brief A function that takes in a key and returns a hash of that key using some custom function
* @param key, a string
* @return a hash of the key
*/
{
	char tmp;
	string newKey;
	vector<char> vect[1];

	//Reverses the spelling of the word, reassigns certain characters to new ones and pushes it into a vector, then returns the values in the vector back to a string in index order.
	for (int i = key.length(); i >= 0; i--)
	{
		tmp = key.at(i);
		if (tmp == '|')
		{
			tmp = '*';
		}
		else if (tmp == 'e')
		{
			tmp = '}';
		}
		else if (tmp == 'i')
		{
			tmp = '~';
		}
		else if (tmp == 'o')
		{
			tmp = '9';
		}
		else if (tmp == 't')
		{
			tmp = '7';
		}
		else if (tmp == 'n')
		{
			tmp = '5';
		}
		else if (tmp == 's')
		{
			tmp = '3';
		}
		else if (tmp == 'h')
		{
			tmp = '1';
		}
		vect->push_back(tmp);
	}

	stringstream ss;
	copy(vect->begin(), vect->end(), ostream_iterator<char>(ss, " "));

	newKey = ss.str();
	newKey = newKey.substr(0, newKey.length() - 1);
	return newKey;
}

//an attempt to make the errors go away. It doesnt work lmao
//void accessQ()
//{
//	return treeQ;
//}


//Dont need to mess with these.
bool operator==(const pMT& lhs, const pMT& rhs)
/**
* @brief Comparison between two merkle trees
* @param lhs, the left hand side of the equality statment
* @param rhs, the right hand side of the equality statement
* @return true if equal, false otherwise
*/
{
	if (lhs.myMerkle.root->word == rhs.myMerkle.root->word && lhs.myMerkle.root->timeStamp == rhs.myMerkle.root->timeStamp)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool operator !=(const pMT& lhs, const pMT& rhs)
/**
* @brief Comparison between two merkle trees
* @param lhs, the left hand side of the equality statment
* @param rhs, the right hand side of the equality statement
* @return true if not equal, false otherwise
*/
{
	if (lhs.myMerkle.root->word == rhs.myMerkle.root->word && lhs.myMerkle.root->timeStamp == rhs.myMerkle.root->timeStamp)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//pMT operator ^=(const pMT& lhs, const pMT& rhs)
/**
* @brief XOR between two merkle trees
* @param lhs, the left hand side of the equality statment
* @param rhs, the right hand side of the equality statement
* @return true if not equal, false otherwise
*/
//{
//    //bTREE accessbTREE() { return myMerkle; }
//	if ()
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}

//pMT operator ^(const pMT& lhs, const pMT& rhs)
/**
* @brief Where do two trees differ
* @param lhs
* @param rhs
* @return a tree comprised of the right hand side tree nodes that are different from the left
*/
//{
//	return;
//}