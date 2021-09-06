//
//  main.cpp
//  learnCPP
//
//  Created by Swapnil Bhalerao on 06/09/21.
//
#include "Object.hpp"
int main(int argc, const char *argv[])
{
    Object obj1;
    obj1.PrintData();
    Object obj2(obj1);
    obj2.PrintData();
    return 0;
}
