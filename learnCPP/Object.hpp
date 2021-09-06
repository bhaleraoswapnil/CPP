//
//  Object.hpp
//  learnCPP
//
//  Created by Swapnil Bhalerao on 06/09/21.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <iostream>
#include "string"

#endif /* Object_hpp */
using namespace std;
class Object
{
private:
    char *str;
    std::string name;

public:
    //Default Constructor
    Object();

    //Parameter Constructor
    // Object(std::string);

    //Copy Constructor
    Object(const Object &);

    //Assignment Operator
    // Object &operator=(const Object &);

    //Destructor
    ~Object();

    void PrintData();
};