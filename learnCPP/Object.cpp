//
//  Object.cpp
//  learnCPP
//
//  Created by Swapnil Bhalerao on 06/09/21.
//

#include "Object.hpp"

Object::Object()
{
    std::cout << "Default Constructor ------>\n";
    str = new char[12];
    std::string s = "Hello World";
    for (int i = 0; i < s.length(); i++)
    {
        str[i] = s[i];
    }
    str[s.length()] = '\0';
    this->name = "defaultObject";
}

Object::~Object()
{
    std::cout << "Destructor ------>" << this->name << "\n";
    if (str != nullptr)
    {
        delete[] str;
        str = nullptr;
    }
}

Object::Object(const Object &obj)
{
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
    this->name = obj.name;
    this->name = this->name + " 1";
}

void Object::PrintData()
{
    std::cout << str << std::endl;
}
