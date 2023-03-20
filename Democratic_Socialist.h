//
// Created by sasha on 1/12/23.
//

#ifndef ASSINGMENT5_DEMOCRATIC_SOCIALIST_H
#define ASSINGMENT5_DEMOCRATIC_SOCIALIST_H
#include "Democrat_Politician.h"

class Democratic_Socialist : public Democrat_Politician {
    /// this class represents a democratic socialist
public:
    // class constructor
    Democratic_Socialist(string& first_name,string& last_name,int id,int power): Democrat_Politician(first_name,last_name,id,power){}
    // default destructor
    virtual ~Democratic_Socialist();
    // return this politician's power during elections
    virtual int getPower()const;
    // return this politician's power during primaries
    virtual int primePower()const;
    // print the politician
    virtual void print() const;


};


#endif //ASSINGMENT5_DEMOCRATIC_SOCIALIST_H
