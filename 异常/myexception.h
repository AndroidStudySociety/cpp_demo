//
// Created by Jesson on 2019/12/5.
//

#ifndef CPLUSPLUS_MYEXCEPTION_H
#define CPLUSPLUS_MYEXCEPTION_H

#include <iostream>
using namespace std;
struct myexception: public exception {
    const char* what() const throw(){
        return "this is c++ exception";
    }
};


#endif //CPLUSPLUS_MYEXCEPTION_H
