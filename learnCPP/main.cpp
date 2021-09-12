//
//  main.cpp
//  learnCPP
//
//  Created by Swapnil Bhalerao on 06/09/21.
//
// clang++ -std=c++11 -stdlib=libc++ -fno-elide-constructors main.cpp Object.hpp Object.cpp myVector.hpp myVector.cpp
// clang++ -std=c++14 -stdlib=libc++ -fno-elide-constructors main.cpp Object.hpp Object.cpp myVector.hpp myVector.cpp
#include "Object.hpp"
#include "myVector.hpp"
#include "memory"

//---------------------------------------------------------------------------------------------------
template <class T>
class myUniquePointer
{
private:
    T *ptr;

public:
    myUniquePointer();
    myUniquePointer(T *p);
    myUniquePointer(myUniquePointer &&);
    void operator=(myUniquePointer &&);
    myUniquePointer(const myUniquePointer &) = delete;
    myUniquePointer &operator=(const myUniquePointer &) = delete;
    ~myUniquePointer();
};

template <class T>
myUniquePointer<T>::myUniquePointer()
{
    cout << "template class Default Constructor" << endl;
    this->ptr = nullptr;
}

template <class T>
myUniquePointer<T>::myUniquePointer(T *p)
{
    cout << "template class Parameter Constructor" << endl;
    this->ptr = p;
}

template <class T>
myUniquePointer<T>::myUniquePointer(myUniquePointer &&rhs)
{
    cout << "template class move Constructor" << endl;
    this->ptr = rhs.ptr;
    rhs.ptr = nullptr;
}
template <class T>
void myUniquePointer<T>::operator=(myUniquePointer &&rhs)
{
    cout << "template class move Assignment operator" << endl;
    if (nullptr != this->ptr)
    {
        delete this->ptr;
        this->ptr = nullptr;
    }
    this->ptr = rhs.ptr;
    rhs.ptr = nullptr;
}
template <class T>
myUniquePointer<T>::~myUniquePointer()
{
    cout << "template class Destructor" << endl;
    if (nullptr != this->ptr)
    {
        delete this->ptr;
        this->ptr = nullptr;
    }
}
//---------------------------------------------------------------------------------------------------
void printObject(Object obj)
{
}
int main(int argc, const char *argv[])
{
    // Object obj1;
    // obj1.printData();

    // Object obj2(obj1);
    // obj2.printData();

    // Object obj3("Object 3");
    // obj3.printData();

    // Object obj4;
    // obj4 = obj3;
    // obj4.printData();

    // cout << "\n********* move constructor ************\n";
    // Object obj5((Object())); // Copy elision -- here default constructor will call.
    // obj5.printData();
    // printObject(Object());
    // Object obj6;
    // obj6 = Object(); // move assignment operator
    // cout << "\n*****************************************\n";

    // cout << "========= Two Dimensional Array =============\n";
    // int *p = new int[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     p[i] = i + 1;
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << p[i] << "\n";
    // }
    // delete[] p;
    // static int a = 0;
    // int **q;
    // q = new int *[3];
    // for (int i = 0; i < 3; i++)
    // {
    //     q[i] = new int[3];
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         q[i][j] = a++;
    //     }
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << q[i][j] << " => " << &q[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << q[i] << " ";
    //     delete[] q[i];
    // }
    // cout << "\n";
    // delete[] q;

    // cout << "=============================================\n";

    // cout << "~~~~~~~~~~~~~~~~~~ My Vector ~~~~~~~~~~~~~~~~~\n";
    // myVector v1;
    // v1.printData();

    // for (int i = 1; i < 10; i++)
    // {
    //     v1.push_back(i);
    //     v1.printData();
    // }
    // myVector v2 = myVector();

    // cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    // cout << "~~~~~~~~~~~~~~~~ Unique pointer ~~~~~~~~~~~~~~~\n";
    // unique_ptr<int> ptr1(new int);
    // cout << ptr1.get() << endl;
    // {
    // unique_ptr<Object> ptr2(new Object);
    // unique_ptr<Object> ptr3 = make_unique<Object>("ptr3");
    // ptr2 = move(ptr3);
    // ptr2->printData();

    //checking unique pointer as empty
    // if (ptr3 == nullptr)
    // {
    //     cout << "ptr3 is empty \n";
    // }

    // release() will release ownership and return raw pointer. Now developer has responsiblity to free memory using raw pointer.
    // unique_ptr<Object> ptr4 = make_unique<Object>("ptr4");
    // Object *p = ptr4.release();
    // delete p;

    //deleting array of unique pointers
    // unique_ptr<Object[]> ptr5(new Object[5]);

    // unique_ptr<Object> ptr4;
    // ptr4 = ptr2; // Error can't copy to other Unique pointer.
    // }
    // cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    cout << "~~~~~~ Unique pointer class Implementation ~~~~~~\n";
    {
        myUniquePointer<Object> a1(new Object());
        myUniquePointer<Object> a2 = move(a1);
        myUniquePointer<Object> a3;
        a3 = move(a2);
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    return 0;
}
