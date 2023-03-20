//
// Created by sasha on 1/12/23.
//

#include "Democrat_Politician.h"
void Democrat_Politician::print()const{
    cout<<"Democratic"; // print the type of the politician
    Politician::print();
}

void Democrat_Politician::addParty(subject * par){
    if (par==nullptr){ //null check
        _party= nullptr;
        return;
    }
    if (par->addMember(this)){ // check if the politician was successfully added
        if (_party!=nullptr) // if this politician had a party then delete him from there
            _party->deleteMember(this);
        _party = (Party*)par;
    }

}