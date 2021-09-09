//
//  myVector.hpp
//  learnCPP
//
//  Created by Swapnil Bhalerao on 09/09/21.
//

#ifndef myVector_hpp
#define myVector_hpp

#include <stdio.h>
#include <iostream>
#endif /* myVector_hpp */
using namespace std;
class myVector
{
private:
    int *mpData;
    int mSize;
    int mCap;

public:
    myVector();
    myVector(const myVector &) = delete;
    myVector &operator=(const myVector &) = delete;
    myVector(myVector &&);
    void push_back(int);
    void printData();
};
