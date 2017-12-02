#include <string>

struct treeNode
{
	//The data stored in the node.
	std::string word = "";
	// psuedo int stored in node
	int timeStamp = 0;

	treeNode *left = NULL;
	treeNode *right = NULL;

	bool leaf = true; //Identifies as a leaf or not
};

//Seperate file because it's easier.