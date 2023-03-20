//
// Created by sasha on 1/10/23.
//

#include "Party.h"

Party::Party(string& name):subject(),_chairman(nullptr){
    _name = name;
}

Party::~Party() {
_members.clear(); // clears all the pointers to politicians in the party
}
int Party::size()const{
    return _members.size();
}


void Party::deleteMember(const Politician* pol){
    if (pol==_chairman){ // if the chairman is deleted
        _chairman = nullptr;
        Notify("None");
    }

    for(auto iter = _members.begin();iter!=_members.end();iter++){
        if (**iter ==*pol){ // iterate from the first member to the last
            _members.erase(iter);
            break;
        }
    }
}

bool Party::primaries(){
    int max =0;
    Politician * pol = nullptr;
    auto iter = _members.begin();
    while(iter!=_members.end()){
        if((*iter)->primePower()>max){ // find the strongest leader politician
            pol=*iter;
            max = (*iter)->primePower();
        }
        iter++;
    }
    if (pol != nullptr){ // if pol is not null then there is a leader politician in the party
        _chairman = pol;
        Notify(pol->getName());
        return true;
    }
    else if (_chairman!=nullptr){ // if there is a chairman and no new chairman was elected
        Notify("None");
        return true;
    }
    return false;
}

int Party::strength()const{
    auto iter = _members.begin();
    int sum=0;
    while(iter!=_members.end()){// iterate from the first member to the last and add his strength to the total strength
        sum+=(*iter)->getPower();
        iter++;
    }
    return sum;
}


void Party::print()const {
    string chairman;
    if (_chairman== nullptr) // if there is no chairman print "None" as the chairman
        chairman="None";
    else
        chairman = _chairman->getName();
    cout<<"Party: "<<_name<<", chairman:"<<chairman<<", Size:"<<_members.size()<<endl;
    auto iter = _members.begin();
    while(iter!=_members.end()){ // iterate from the first member to the last and print them
        cout<<"\t";
        (*iter)->print();
        iter++;
    }
}

void Party::Notify(const string& chairman)const{
    auto iter = _members.begin();
    while(iter!=_members.end()){ // iterate from the first member to the last and update them
        (*iter)->update(chairman);
        iter++;
    }
}
/// basic getters
string Party::getName()const{
    return _name;
}
vector<Politician*>* Party::getMembers(){
    return &_members;
}

const Politician* Party::getChairman()const{
    return _chairman;
}

bool Party::operator>(const Party& other)const{
    if (this->strength()>other.strength()) // first check the strength of the parties
         return true;
    else if(this->strength()==other.strength()){ // if their strengths are equal then compare by their names
        if (this->getName()>other.getName())
             return true;
        return false;
     }
    return false;
}