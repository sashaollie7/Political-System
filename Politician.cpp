//
// Created by sasha on 1/9/23.
//

#include "Politician.h"


void Politician::print() const{
    // print all the basic details
    cout<<" Person:"<<_first_name<<" "<<_last_name<<", Id:"<<_id<<", Power:"<<_power<<", ";
}

Politician::Politician(string& first_name,string& last_name,int id,int power):observer(),_chairman("None"),_party(nullptr){
    // a simple constructor
    _id = id;
    _power=power;
   _first_name = first_name;
    _last_name = last_name;

}

bool Politician::operator==(const Politician& other)const{
    return (_id==other.getID());// compare by id
}
void Politician::update(const string& name){
    if(name==_chairman)
        return;
    _chairman =name;
}

/// get functions
Party* Politician::getParty()const{
    return _party;
}

const string& Politician::getName()const{
    return _first_name;
}
int Politician::getID()const{
    return _id;
}