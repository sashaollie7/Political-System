//
// Created by sasha on 1/12/23.
//

#ifndef ASSINGMENT5_REPUBLICAN_POLITICIAN_H
#define ASSINGMENT5_REPUBLICAN_POLITICIAN_H
#include "Politician.h"
#include "Democrat_Party.h"
#include "Republican_Party.h"

class Republican_Politician:public Politician {
    /// this abstract class represents a republican politician, it was made mainly to not over flow the party class with many functions
public:
    // sends all the data needed to create a politician to the basic politician
    Republican_Politician(string& first_name,string& last_name,int id,int power): Politician(first_name,last_name,id,power){}
    // print the politician
    virtual void print() const;
    // default destructor
    ~Republican_Politician(){};
    // a function which receives the party as a subject and dispatches him self to this party
    virtual void addParty(subject* par);
};


#endif //ASSINGMENT5_REPUBLICAN_POLITICIAN_H
