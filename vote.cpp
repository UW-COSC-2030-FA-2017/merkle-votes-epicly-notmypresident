//vote.cpp
#include "pMT.h"

#include<string>
using std::string;

#include<fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;

string PromptUser()
{
	string filename;
	cout << "Please enter the name of a file." << endl;
	cin >> filename;
	return filename;
}

int CheckFile(ifstream& in)
{
	if (!in.is_open()) {
		return 1;
	}
	else {
		
		return 0;
	}
	// returns 0 if everything went well.
	// returns 1 if the file was not open
}

void CompareFiles(string first, string second)
{
	vector <string> v1, v2;
	ifstream file;

	file.open(first.c_str(), ifstream::in);
	while (getline(file, first))
	{
		v1.push_back(first);
	}
	file.close();

	file.open(second.c_str(), ifstream::in);
	while (getline(file, second))
	{
		v2.push_back(second);
	}
	file.close();

	int found = 0;

	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v2.size(); j++)
		{
			if (v1[i] == v2[j])
			{
				found++;
			}
		}
		if (found == 0)
		{
			cout << "Not Validated" << endl;
			break;
		}
		else if (i == v1.size() - 1)
		{
			cout << "Validated" << endl;
		}
	}
}

int main()
{
	string filename;
	ifstream infile;
	string data;
	int time;
	pMT tree = pMT(1);
	treeNode* temp;
	/*
	* Get the filename
	*/
	filename = PromptUser();
	

	/*
	* Get the filename
	*/
	filename = PromptUser();
	/*
	* Open the file.
	* If the filename is bad (file will not open)
	* reset the ifstream with ifstream.clear().
	* Prompt the user again and
	* repeat until the input file is opened.
	*
	*/
	infile.open(filename);
	while (!infile) 
	{
		cout << "\nCould not open " << filename << endl;
		infile.clear();
		filename = PromptUser();
		infile.open(filename);
	}

	infile.open(filename);

	while (!infile) 
	{
		cout << "\nCould not open " << filename << endl;
		infile.clear();
		filename = PromptUser();
		infile.open(filename);
	}

	int rtn = CheckFile(infile);

	if (rtn == 1) {
		cout << "File could not be opened.";
		return 1;
	}

	while (!infile.eof())
	{
		cin >> data;
		cin >> time;
		tree.insert(data);
	}

	infile.close();

	return 0;
}
