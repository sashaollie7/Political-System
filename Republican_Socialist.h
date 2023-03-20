//
// Created by sasha on 1/12/23.
//

#ifndef ASSINGMENT5_REPUBLICAN_SOCIALIST_H
#define ASSINGMENT5_REPUBLICAN_SOCIALIST_H
#include "Republican_Politician.h"


class Republican_Socialist : public Republican_Politician{
    /// this class represents a republican socialist
public:
    // class constructor
    Republican_Socialist(string& first_name,string& last_name,int id,int power): Republican_Politician(first_name,last_name,id,power){}
    // default destructor
    ~Republican_Socialist();
    // return this politician's power during elections
    virtual int getPower()const;
    // return this politician's power during primaries
    virtual int primePower()const;
    // print the politician
    virtual void print() const;
};


#endif //ASSINGMENT5_REPUBLICAN_SOCIALIST_H
