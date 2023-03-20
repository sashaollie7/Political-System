//
// Created by sasha on 1/14/23.
//

#ifndef ASSINGMENT5_OBSERVER_PATTERN_H
#define ASSINGMENT5_OBSERVER_PATTERN_H
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class Democrat_Politician;
class Republican_Politician;


/// this is an interface for the Observer pattern which is used to implement politician and party classes

class observer {
    /// this class represent an observer which gets updates from the subject
public:
    observer(){}
    virtual void update(const string& name)=0;
};
class subject{
    /// this class represents a subject which notifies his observers when something happens add can only contain Republican or Democrat Politicians
public:
    subject(){}
    virtual void Notify(const string& name)const=0;
    virtual bool addMember(Democrat_Politician * pol)=0;
    virtual bool addMember(Republican_Politician * pol)=0;
};

#endif //ASSINGMENT5_OBSERVER_PATTERN_H
