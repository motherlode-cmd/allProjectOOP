#ifndef MYEXEPTION_H
#define MYEXEPTION_H
#include <iostream>
#include <fstream>
class MyExeption: public std::exception
{
public:
    MyExeption(){}
    virtual ~MyExeption(){}
    virtual std::string what_() = 0;
protected:
    std::string what;
};

#endif // MYEXEPTION_H
