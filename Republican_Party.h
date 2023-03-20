//
// Created by sasha on 1/13/23.
//

#ifndef ASSINGMENT5_REPUBLICAN_PARTY_H
#define ASSINGMENT5_REPUBLICAN_PARTY_H
#include "Party.h"
#include "Republican_Politician.h"

class Republican_Party :public Party{
public:
    // basic constructor
    Republican_Party(string name);
    //  Democrat Party destructor
    virtual ~Republican_Party();
    // add a democrat member to the party
    virtual bool addMember(Democrat_Politician* pol);
    // add a republican member to the party
    virtual bool addMember(Republican_Politician* pol);
    // override printing the party
    virtual void print()const;
};


#endif //ASSINGMENT5_REPUBLICAN_PARTY_H
