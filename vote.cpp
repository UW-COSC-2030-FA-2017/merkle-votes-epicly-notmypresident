#include <stdio.h>
#include <iostream>
#include <fstream>

//#include "pMT.h"
#include "bTREE.h"

using namespace std;

int main()
{
	bTREE tree;
	int input = -1;
	string wordData;

	while (input != 0)
	{
		cout << "Please select an option for your bTREE:" << endl;
		cout << "1. Count nodes " << endl;
		cout << "2. Insert a new node" << endl;
		cout << "3. Find a node with it's string" << endl;
		cout << "4. Locate the path to a node via it's hash" << endl;
		cout << "5. Display tree" << endl;
		cout << "0. Exit." << endl;
		cin >> input;

		if (input != 0)
		{
			switch (input)
			{
			case 1:
				tree.numberOfNodes(tree.root);
			case 2:
				cout << "Please enter a string to insert into the new node:" << endl;
				cin >> wordData;
				tree.insert(wordData);
			case 3:
				cout << "Enter a string to search for:" << endl;
				cin >> wordData;
				tree.callerfind(wordData);
			case 4:
				cout << "Enter a hash to search the tree for:" << endl;
				cin >> wordData;
				tree.locate(wordData);
			case 5:
				ostream & operator<<(ostream & out, const bTREE & p);
			default:
				cout << "Not a Valid Option." << endl;
			}
		}
	}
	return 0;
}
