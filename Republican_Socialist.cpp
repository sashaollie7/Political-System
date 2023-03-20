//
// Created by sasha on 1/12/23.
//

#include "Republican_Socialist.h"
Republican_Socialist::~Republican_Socialist(){}
int Republican_Socialist::getPower()const {
    return _power*2;
}
int Republican_Socialist::primePower()const{
    return -1; //cant be a chairman then his power during primaries is irrelevant
}
void Republican_Socialist::print()const{
    Republican_Politician::print();
    cout<<"Type:S, Chairman: "<<_chairman<<endl;
}