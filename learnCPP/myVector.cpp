//
//  myVector.cpp
//  learnCPP
//
//  Created by Swapnil Bhalerao on 09/09/21.
//

#include "myVector.hpp"

myVector::myVector()
{
    mSize = 0;
    mCap = 2;
    mpData = new int[mCap];
}
myVector::myVector(myVector &&obj)
{
    this->mpData = obj.mpData;
    this->mSize = obj.mSize;
    this->mCap = obj.mCap;
    obj.mpData = nullptr;
}

void myVector::push_back(int val)
{
    if (mSize <= mCap - 1)
    {
        mpData[mSize] = val;
        mSize++;
    }
    else
    {
        int *temp = mpData;
        mpData = new int[mCap * 2];
        for (int i = 0; i < mCap; i++)
        {
            mpData[i] = temp[i];
        }
        delete[] temp;
        mCap = mCap * 2;
        mpData[mSize] = val;
        mSize++;
    }
}
void myVector::printData()
{
    cout << "\nVector Size  " << mSize << endl;
    cout << "Vector Capacity ==> " << mCap << endl;
    
    for (int i = 0; i < mSize; i++)
    {
        cout << mpData[i] << "\t";
    }
    cout << endl;
}