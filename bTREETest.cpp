#include <stdio.h>
#include <iostream>
#include <fstream>

#include "pMT.h"
#include "bTREE.h"

using namespace std;

int main()
{
	bTREE tree = bTREE(); //create bTree.
	int input = -1; //control var for user input.
	string wordData; //tmp var for userInput.

	while (input != 0)
	{
		cout << "Please select an option for your bTREE:" << endl << endl;
		cout << "1. Count nodes." << endl;
		cout << "2. Insert a new node." << endl;
		cout << "3. Find a node with it's string." << endl;
		cout << "4. Locate the path to a node via it's hash." << endl;
		cout << "5. Report the amount of total Operations so far." << endl;
		cout << "0. Exit." << endl;
		cin >> input;
		cout << endl;

		if (input != 0)
		{
			tree.ops++;
			switch (input)
			{
			case 1:
				tree.ops++;
				//this works
				cout << tree.numberOfNodes(tree.root) << endl;
				break;
			case 2:
				tree.ops++;
				//this no worky
				cout << "Please enter a string to insert into the new node:" << endl;
				cin >> wordData;
				tree.insert(wordData);
				//dont delete this function below from case 2 
				tree.display(cout);
				break;
			case 3:
				tree.ops++;
				//not tested yet.
				cout << "Enter a string to search for:" << endl;
				cin >> wordData;
				tree.callerfind(wordData);
				break;
			case 4:
				tree.ops++;
				//not tested yet.
				cout << "Enter a hash to search the tree for:" << endl;
				cin >> wordData;
				tree.locate(wordData);
				break;
			case 5:
				tree.ops++;
				//this works.
				cout << "Amount of operations so far: " << tree.ops << endl;
			default:
				tree.ops++;
				//this works.
				cout << "Not a Valid Option." << endl;
			}
		}
	}
	return 0;
}