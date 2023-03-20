//
// Created by sasha on 1/12/23.
//

#include "Democratic_Socialist.h"
Democratic_Socialist::~Democratic_Socialist(){}
int Democratic_Socialist::getPower()const {
    return _power*2;
}
int Democratic_Socialist::primePower()const{
    return -1; //cant be a chairman then his power during primaries is irrelevant
}
void Democratic_Socialist::print()const{
    Democrat_Politician::print();
    cout<<"Type:S, Chairman: "<<_chairman<<endl;
}

