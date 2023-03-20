//
// Created by sasha on 1/17/23.
//

#ifndef ASSINGMENT5_SYSEXCEPTION_H
#define ASSINGMENT5_SYSEXCEPTION_H
#include "exception"
#include <iostream>
using namespace std;

class SysException: public exception{
    /// this class is a dummy class i made to catch all the possible exceptions in politicalSys
};
class wrongIDException: public SysException{
    /// exception class for wrong id exception
public:
virtual const char* what() const throw(){
    return "Please enter valid id";
}
};
class wrongNameException: public SysException{
    /// exception class for wrong name exceptionS
public:
    virtual const char* what() const throw(){
        return "Please enter valid name";
    }
};
class wrongDetailsException: public SysException{
    /// exception class for wrong details exception
public:
    virtual const char* what() const throw(){
        return "Please enter valid details";
    }
};


#endif //ASSINGMENT5_SYSEXCEPTION_H
