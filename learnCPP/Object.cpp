//
//  Object.cpp
//  learnCPP
//
//  Created by Swapnil Bhalerao on 06/09/21.
//

#include "Object.hpp"

Object::Object()
{
    std::cout << "Default Constructor \n";
    str = new char[12];
    std::string s = "Hello World";
    for (int i = 0; i < s.length(); i++)
    {
        str[i] = s[i];
    }
    str[s.length()] = '\0';
}

Object::Object(string s)
{
    std::cout << "Parameter Constructor \n";
    this->str = new char[s.length() + 1];
    for (int i = 0; i < s.length(); i++)
    {
        str[i] = s[i];
    }
    str[s.length()] = '\0';
    cout << this->str << endl;
}

Object::~Object()
{
    std::cout << "Destructor \n";
    if (str != nullptr)
    {
        delete[] str;
        str = nullptr;
    }
}

Object::Object(const Object &obj)
{
    std::cout << "Copy Constructor \n";
    int len = 0;
    while (obj.str[len] != '\0')
    {
        len++;
    }
    this->str = new char[len + 1];
    for (int i = 0; i <= len; i++)
    {
        this->str[i] = obj.str[i];
    }
    this->str[len + 1] = '\0';
}

Object &Object::operator=(const Object &obj)
{
    cout << "Assignment Operator \n";
    // check for self assignment
    if (this == &obj)
    {
        return (*this);
    }
    delete[] str;
    this->str = nullptr;
    int len = 0;
    while (obj.str[len++] != '\0')
    {
    }
    this->str = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        this->str[i] = obj.str[i];
    }
    this->str[len] = '\0';
    return (*this);
}

Object::Object(Object &&obj)
{
    std::cout << "Move Constructor \n";
    this->str = obj.str;
    obj.str = nullptr;
}

Object &Object::operator=(Object &&obj)
{
    std::cout << "Move Assignment operator \n";
    this->str = obj.str;
    obj.str = nullptr;
    return (*this);
}

void Object::printData()
{
    std::cout << str << std::endl;
}
