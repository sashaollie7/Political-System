//
// Created by sasha on 1/9/23.
//

#include "Republican_Leader.h"
Republican_Leader::~Republican_Leader(){}
int Republican_Leader::getPower()const {
    return _power;
}
int Republican_Leader::primePower()const{
    return _power;
}
void Republican_Leader::print()const{
    Republican_Politician::print();
    cout<<"Type:L, Chairman: "<<_chairman<<endl;
}