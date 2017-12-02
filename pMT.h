#pragma once

#include "bTREE.h"
#include <string>
using namespace std;
class pMT
{
private:
    int selectedHash; //Global Var for hash selected by user.
    bTREE myMerkle;
    
    string hash_1(string);
    string hash_2(string);
    string hash_3(string);
    
public:
    pMT(int); //Only keeps track of selected hash
    ~pMT();
    
    int insert(string); //SEPERATE from bTREE file. Needs it's own implementation.
    

	//Most of these below will only borrow from bTree, shouldn't need to add much if anything to these.
    int find(string vote, int hashSelect);
    int findHash(string vote);
    
    string locateData(string vote);
	string locateHash(string vote);


	//Shouldn't need to worry about these.
	friend bool operator ==(const pMT & lhs, const pMT & rhs);
    
    friend bool operator !=(const pMT & lhs, const pMT & rhs);
    
    friend pMT operator^(const pMT& lhs, const pMT& rhs);
    
};

