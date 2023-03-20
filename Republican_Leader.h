//
// Created by sasha on 1/9/23.
//

#ifndef ASSINGMENT5_REPUBLICAN_LEADER_H
#define ASSINGMENT5_REPUBLICAN_LEADER_H
#include "Republican_Politician.h"


class Republican_Leader : public Republican_Politician{
    /// this class represents a Republican leader politician which can be a chairman and also a president
public:
    // class constructor
    Republican_Leader(string& first_name,string& last_name,int id,int power): Republican_Politician(first_name,last_name,id,power){}
    // default destructor
    virtual ~Republican_Leader();
    // return this politician's power during elections
    virtual int getPower()const;
    // return this politician's power during primaries
    virtual int primePower()const;
    // print the politician
    virtual void print() const;
};


#endif //ASSINGMENT5_REPUBLICAN_LEADER_H
