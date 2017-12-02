#pragma once

#include "bTREE.h"
#include <string>
using namespace std;
class pMT
{
private:
    int selectedHash;
    bTREE myMerkle;
    
    string hash_1(string);
    string hash_2(string);
    string hash_3(string);
    
public:
    pMT(int);
    ~pMT();
    
    int insert(string);
	int insert(string vote, treeNode* node);
    
    int find(string vote, int hashSelect);
    int findHash(string vote);
    
    string locateData(string vote);
	string locateHash(string vote);

	friend bool operator ==(const pMT & lhs, const pMT & rhs);
    
    friend bool operator !=(const pMT & lhs, const pMT & rhs);
    
    friend pMT operator^(const pMT& lhs, const pMT& rhs);
    
};

