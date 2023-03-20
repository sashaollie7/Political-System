//
// Created by sasha on 1/12/23.
//

#include "Democratic_Leader.h"
Democratic_Leader::~Democratic_Leader(){}
int Democratic_Leader::getPower()const {
    return _power;
}
int Democratic_Leader::primePower()const{
    return _power;
}
void Democratic_Leader::print()const{
    Democrat_Politician::print();
    cout<<"Type:L, Chairman: "<<_chairman<<endl;
}
