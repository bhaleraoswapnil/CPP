//
//  main.cpp
//  learnCPP
//
//  Created by Swapnil Bhalerao on 06/09/21.
//
// clang++ -std=c++11 -stdlib=libc++ -fno-elide-constructors main.cpp Object.hpp Object.cpp myVector.hpp myVector.cpp
#include "Object.hpp"
#include "myVector.hpp"
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

    cout << "========= Two Dimensional Array =============\n";
    int *p = new int[5];
    for (int i = 0; i < 5; i++)
    {
        p[i] = i + 1;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << "\n";
    }
    delete[] p;
    static int a = 0;
    int **q;
    q = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        q[i] = new int[3];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            q[i][j] = a++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << q[i][j] << " => " << &q[i][j] << "\t";
        }
        cout << "\n";
    }

    for (int i = 0; i < 3; i++)
    {
        cout << q[i] << " ";
        delete[] q[i];
    }
    cout << "\n";
    delete[] q;

    cout << "=============================================\n";

    cout << "~~~~~~~~~~~~~~~~~~ My Vector ~~~~~~~~~~~~~~~~~\n";
    myVector v1;
    v1.printData();

    for (int i = 1; i < 10; i++)
    {
        v1.push_back(i);
        v1.printData();
    }
    myVector v2 = myVector();

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    return 0;
}
