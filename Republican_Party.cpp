//
// Created by sasha on 1/13/23.
//

#include "Republican_Party.h"
Republican_Party::Republican_Party(string name):Party(name){} // uses the politician constructor
Republican_Party::~Republican_Party(){}// default destructor
// do nothing for the democrat
bool Republican_Party::addMember(Democrat_Politician* pol){return false;}

bool Republican_Party::addMember(Republican_Politician* pol){
    _members.push_back((Politician*)pol);  // add the republican politician
    if (_chairman==nullptr) // if no chairman send "None"
        pol->update("None");
    else
        pol->update(_chairman->getName());
    return true;
}

void Republican_Party::print()const{
    cout<<"Republican "; // print the type of the party
    Party::print();
}