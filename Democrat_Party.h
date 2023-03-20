//
// Created by sasha on 1/12/23.
//

#ifndef ASSINGMENT5_DEMOCRAT_PARTY_H
#define ASSINGMENT5_DEMOCRAT_PARTY_H
#include "Party.h"
#include "Democrat_Politician.h"


class Democrat_Party :protected Party{
public:
    // basic constructor
    Democrat_Party(string name);
    //  Democrat Party destructor
    virtual ~Democrat_Party();
    // add a democrat member to the party
    virtual bool addMember(Democrat_Politician* pol);
    // add a republican member to the party
    virtual bool addMember(Republican_Politician* pol);
    // override printing the party
    virtual void print()const;
};


#endif //ASSINGMENT5_DEMOCRAT_PARTY_H
