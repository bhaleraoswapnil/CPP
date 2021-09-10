//
//  myVector.cpp
//  learnCPP
//
//  Created by Swapnil Bhalerao on 09/09/21.
//

#include "myVector.hpp"

myVector::myVector()
{
    cout << "vector constructor\n";
    mCurrent = 0;
    mCapacity = 2;
    mpData = new int[mCapacity];
}

myVector::myVector(const myVector &rhs)
{
    cout << "vector copy constructor\n";
    this->mpData = new int[rhs.mCapacity];
    this->mCapacity = rhs.mCapacity;
    this->mCurrent = rhs.mCurrent;
    for (int i = 0; i < this->mCurrent; i++)
    {
        this->mpData[i] = rhs.mpData[i];
    }
}

myVector &myVector::operator=(const myVector &rhs)
{
    cout << "vector assignment operator\n";
    if (this == &rhs)
    {
        return (*this);
    }

    if (this->mCapacity != rhs.mCapacity)
    {
        delete[] this->mpData;
        this->mpData = new int[rhs.mCapacity];
        this->mCapacity = rhs.mCapacity;
    }
    this->mCurrent = rhs.mCurrent;
    for (int i = 0; i < this->mCurrent; i++)
    {
        this->mpData[i] = rhs.mpData[i];
    }

    return (*this);
}

myVector::myVector(myVector &&obj)
{
    cout << "vector move constructor\n";
    this->mpData = obj.mpData;
    this->mCurrent = obj.mCurrent;
    this->mCapacity = obj.mCapacity;
    obj.mpData = nullptr;
}
myVector::~myVector()
{
    cout << "vector Destructor\n";
    if (this->mpData != nullptr)
    {
        delete[] this->mpData;
        this->mpData = nullptr;
    }
    this->mCapacity = 0;
    this->mCurrent = 0;
}
void myVector::push_back(int val)
{
    if (mCurrent <= mCapacity - 1)
    {
        mpData[mCurrent] = val;
        mCurrent++;
    }
    else
    {
        int *temp = mpData;
        mpData = new int[mCapacity * 2];
        for (int i = 0; i < mCapacity; i++)
        {
            mpData[i] = temp[i];
        }
        delete[] temp;
        mCapacity = mCapacity * 2;
        mpData[mCurrent] = val;
        mCurrent++;
    }
}
void myVector::printData()
{
    cout << "\nVector Size  " << mCurrent << endl;
    cout << "Vector Capacity ==> " << mCapacity << endl;

    for (int i = 0; i < mCurrent; i++)
    {
        cout << mpData[i] << "\t";
    }
    cout << endl;
}
