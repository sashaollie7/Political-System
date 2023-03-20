//
// Created by sasha on 1/12/23.
//

#include "Democrat_Party.h"

Democrat_Party::Democrat_Party(string name):Party(name){} // uses the politician constructor
Democrat_Party::~Democrat_Party(){} // default destructor
bool Democrat_Party::addMember(Democrat_Politician* pol){
    _members.push_back((Politician*)pol); // add the democrat politician
    if (_chairman==nullptr) // if no chairman send "None"
        pol->update("None");
    else
        pol->update(_chairman->getName());
    return true;
}

// do nothing for the republican
bool Democrat_Party::addMember(Republican_Politician* pol){return false;}


void Democrat_Party::print()const{
    cout<<"Democrat "; // print the type of the party
    Party::print();
}