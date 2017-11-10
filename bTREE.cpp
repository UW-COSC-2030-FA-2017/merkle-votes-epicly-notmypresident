#include "bTREE.h"

#include <iostream>
#include <queue>


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
}

bTREE::~bTREE()
{
}

int bTREE::dataInserted()
{

}

int bTREE::numberOfNodes()
{
}

int bTREE::insert(string data, int time)
{
	//if NOT a leaf, find one
	if (leaf == false)
	{
		findleaf();
	}
	else
	{
		TreeNode.word = data;
		TreeNode.TimeStamp = time;
	}
	return; //number of operations taken.
}

int bTREE::findLeaf()
{
	//cycle through nodes to find an empty leaf.
}


bool bTREE::find(string)
{
}

string bTREE::locate(string)
{
}

bool operator==(const bTREE & lhs, const bTREE & rhs)
{
	return false;
}

bool operator!=(const bTREE & lhs, const bTREE & rhs)
{
	return false;
}

std::ostream & operator<<(std::ostream & out, const bTREE & p)
{
	// TODO: insert return statement here
}
