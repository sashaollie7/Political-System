//
// Created by sasha on 1/9/23.
//

#ifndef ASSINGMENT5_POLITICIAN_H
#define ASSINGMENT5_POLITICIAN_H
#include "observer_pattern.h"
class Party;
using namespace std;

class Politician :public observer{
    /// this class is the abstract politician which is inherited by all the politicians
protected:
    /// all the variables needed to represent a politician
    string _first_name;
    string _last_name;
    int _id;
    int _power;
    string _chairman;
    Party* _party;
public:
    // a function which prints the politician
    virtual void print() const=0;
    // a constructor which initialize the basic politician
    Politician(string& _first_name,string& _last_name,int id,int power);
    // a function which computes the power of the politician in time of elections
    virtual int getPower()const=0;
    // a function which computes the power of the politician in time of primaries
    virtual int primePower()const=0;
    // a function which returns the first name of the politician
    const string& getName()const;
    // an operator of politician which compares 2 politicians by their id's
    bool operator==(const Politician& other)const;
    // a function which updates the politician when the chairman in his party changes
    void update(const string& name);
    // a function which returns the politician's ID number
    int getID()const;
    // a function which receives a party and adds the politician to the party(if it is possible)
    virtual void addParty(subject * par)=0;
    // a function which returns a pointer to the politician's party
    Party* getParty()const;

};


#endif //ASSINGMENT5_POLITICIAN_H
