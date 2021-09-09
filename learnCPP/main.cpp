//
//  main.cpp
//  learnCPP
//
//  Created by Swapnil Bhalerao on 06/09/21.
//
// clang++ -std=c++11 -stdlib=libc++ main.cpp Object.hpp Object.cpp
#include "Object.hpp"
void printObject(Object obj)
{
}
int main(int argc, const char *argv[])
{
    Object obj1;
    obj1.printData();

    Object obj2(obj1);
    obj2.printData();

    Object obj3("Object 3");
    obj3.printData();

    Object obj4;
    obj4 = obj3;
    obj4.printData();

    cout << "\n********* move constructor ************\n";
    Object obj5((Object())); // Copy elision -- here default constructor will call.
    obj5.printData();
    printObject(Object());
    Object obj6;
    obj6 = Object(); // move assignment operator
    cout << "\n*****************************************\n";

    return 0;
}
