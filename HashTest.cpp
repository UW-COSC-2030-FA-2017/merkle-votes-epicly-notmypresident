#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>

#include "bTREE.h"

using namespace std;

int hashFileOps = 0;

bool compare(bTREE* uno, bTREE* dos)
{
	int oddBalls = 0; //tmp Var to hold timeStamps of nodes that differ.
	if (uno->root->word != dos->root->word)
	{
		hashFileOps++;
		//Navigate through each node comparing root->word, grab their timeStamp values and print them.
		cout << "Trees differ at time stamps: " << oddBalls;
		cout << endl;
		return false;
	}
	else
	{
		return true;
	}
}

string myhash(string data)
{
	{
		//Reverses the spelling of the word, reassigns certain characters to new ones and pushes it into a vector, then returns the values in the vector back to a string in index order.
		for (int i = data.length(); i >= 0; i--)
		{
			hashFileOps++;
			replace(data.begin(), data.end(), 'a', '*');
			replace(data.begin(), data.end(), 'e', '|');
			replace(data.begin(), data.end(), 'i', '~');
			replace(data.begin(), data.end(), 'o', '9');
			replace(data.begin(), data.end(), 't', '7');
			replace(data.begin(), data.end(), 'n', '5');
			replace(data.begin(), data.end(), 's', '3');
			replace(data.begin(), data.end(), 'h', '1');
		}
		return data;
	}
}

//The function only hashes the root node, it does not contine on to hash Kappa. Something with my recursion is wrong.
int doMyHash(treeNode* node)
{
	if (node->leaf == false)
	{
		hashFileOps++;
		node->word = myhash(node->left->word) + myhash(node->right->word);
		return 0;
	}
	else
	{
		hashFileOps++;
		doMyHash(node->left);
		hashFileOps++;
		doMyHash(node->right);
	}
}

int main()
{
	bTREE tree = bTREE(); //create bTree.
	bTREE pine = bTREE();
	int input = -1; //control var for user input.
	string wordData;; //tmp var for userInput.

	tree.insert("GitGudKid");
	cout << "It takes this many ops to insert a new node: " << tree.ops + hashFileOps << endl << endl;
	tree.insert("Kappa");
	tree.insert("NetFlixAndChill");
	tree.insert("ILikeBigButts");
	tree.insert("Durka");

	tree.display(cout);

	doMyHash(tree.root);
	cout << "How many ops to hash one of our trees: " << hashFileOps + tree.ops << endl;

	pine.insert("GitGudKid");
	pine.insert("Kappa");
	pine.insert("NetFlixAndChill");
	pine.insert("ILikeBigButts");
	pine.insert("Murica"); //Here is where it differs.

	doMyHash(pine.root);
	pine.display(cout);

	cout << "How many ops to compare our trees : " << hashFileOps + tree.ops + pine.ops + 1 << endl;
	compare(&tree, &pine);
	cout << "How many ops to determine where one of our trees differ: " << hashFileOps + tree.ops + pine.ops + 1 << endl;
	
	system("PAUSE");
	return 0;
}