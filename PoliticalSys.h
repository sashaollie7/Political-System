//
// Created by sasha on 1/15/23.
//

#ifndef ASSINGMENT5_POLITICALSYS_H
#define ASSINGMENT5_POLITICALSYS_H
#include "Politician.h"
#include "Party.h"
#include "Democratic_Leader.h"
#include "Democratic_Socialist.h"
#include "Republican_Leader.h"
#include "Republican_Socialist.h"
#include <algorithm>
#include "SysException.h"
#include <limits>
#include <sstream>
#include <fstream>

class compere{
    /// this is a functor which compares 2 parties by their sizes
public:
bool operator()(Party* party1,Party* party2) { return (party1->size()<party2->size()); }
};

class PoliticalSys {
    /// this class represents a political system which can store Democratic and Republican parties as well as Politicians of those types
    /// this class keeps the 2 types of politicians in the same type party and can represent elections
private:
    // basic fields of the system
    vector<Politician*> _politicians;
    vector<Party*> _parties;
    // vector which contains all the parties sorted from the smallest to the biggest
    vector<Party*> _sortedParties;
    // a helper function which receives a new party and adds to it all the politicians of the same type and whose who are in a bigger party
    void addNewParty(Party* par);
    // a function which receives a name and a political type and creates a party based on the data,throws exception if there is already a party with that name or wrong letter (not 'R' or 'D')
    void createParty(string& partyName,char partyType);
    // a function which receives data needed to create a politician and constructs it based on the data .
    // throws exceptions in case of bad details: negative power ,id that already exists , political type not 'R'(republican) or 'D' (democrat), politician type not 'S'(social) or 'L' (leader)
    void createPolitician(string& first_name,string& last_name,int id,int pow,char partyType, char politicianType);
    // a function which receives a politician and finds and adds him to the smallest party of the same type  political type(if there is one)
    void searchNiceParty(Politician* pol);
    // sorts the parties by size from the smallest to the biggest
    void sortParties(){sort(_sortedParties.begin(), _sortedParties.end(), compere());}
    public:
    // default constructor
    PoliticalSys(){}
    // a constructor which receives a file name and stores the politicians and the parties from the file
    PoliticalSys(string& filestream);
    // the class destructor
    ~PoliticalSys();
    // a function that receives all the details needed to create a politician from the user (which are listed in 'createPolitician') throws exceptions in case of bad input
    void addPolitician();
    // a function that receives party name and political type from the user and creates a party,uses 'createParty' and throws the same exceptions
    void addParty();
    // a function which receives a politician's id and removes him from the system, throws exception in case the politician doesn't exist
    void removePolitician();
    // a function which receives a party name and removes it from the system, throws exception in case the party by that name doesn't exist
    void removeParty();
    // performs primaries in all the parties and prints the chairman of every party , it also prints the president which is the chairman of the strongest party
    void elections();
    // print all the politicians
    void printPoliticians();
    // prints all the parties and the politicians in them
    void printParties();
    // prints the party with the most members in O(1) runtime
    void BiggestParty();
};


#endif //ASSINGMENT5_POLITICALSYS_H
