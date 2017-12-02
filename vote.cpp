#include<iostream>
#include<fstream>

#include "pMT.h"

int main()
{
	bTREE myMerkle;
	ifstream userFile;

	string line;
	int time;

	userFile.open("VotingBallot.txt");

	if (userFile.is_open())
	{
		//step one:
		//Create a dummy tree
		//Count the number of lines in the file
		//while our queue size x 2 is less than the number of lines in the file...
		//insert(" ") empty node

		//step two:
		//while there are lines in the file (or use a for loop)
		//insert(lineData) (You want to do all of this ONLY on the leaf nodes at the end.)

		//step 3:
		//recrusive update on the tree.
		//Create a new function with the node parameter that keeps calling itself to hash all the nodes left.
		//have them something like...
		//update()
		//{ rhash(root) }
		//rhash(root)
		//{
		//	rhash(root->left)
		//	rhash(root->right)
		//	root->word = rhash(root->left->word) + rhash(root->right->word)
		//}

		userFile.close();
	}

	userFile.open("VotingBallot2.txt");

	if (userFile.is_open())
	{
		//rinse and repeat above.
	}

	//output the root (first) node of the trees' words (should be a long hash for each)

	//compare the two trees. (Should only need to compare the root nodes. If the hashes dont match, then the trees differ.)
	//if they differ, print the nodes that are different.

	return 0;
}

