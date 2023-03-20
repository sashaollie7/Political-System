//
// Created by sasha on 1/10/23.
//

#ifndef ASSINGMENT5_PARTY_H
#define ASSINGMENT5_PARTY_H
#include "observer_pattern.h"
#include "Politician.h"

using namespace std;

class Party:public subject{
    /// this class represents an abstract political party
protected:
    /// basic field to represent a political party
    Politician* _chairman;
    string _name;
    vector <Politician*> _members;

public:
    // default destructor
    virtual ~Party();
    // party constructor , initiate a political party with the given name
    Party(string& name);
    // a function which receives a politician and delete it from the party
    virtual void deleteMember(const Politician* pol);
    // a function which represents primaries in the political party ,which chooses the strongest leader to be the chairman and notifies about it to all the party members
    bool primaries();
    // a function which calculates and returns the political strength of all the party member together
    int strength()const;
    // prints the party and all of it's members
    virtual void print()const=0;
    // returns the current size of the party
    int size()const;
    // returns the name of the party
    string getName()const;
    // a function which returns  a vector with all the party members
    vector<Politician*>* getMembers();
    // returns a pointer to the chairman of the party
    const Politician* getChairman()const;
    // compares 2 parties by their strength and if they are at the same size it compares their names
    bool operator>(const Party& other)const;
    // a function which notifies all the party members about a new chairman in the party
    void Notify(const string& chairman)const;

};



#endif //ASSINGMENT5_PARTY_H
