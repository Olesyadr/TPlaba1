#ifndef PRINTING_H
#define PRINTING_H
#include <iostream>

class Printing
{
public:
    Printing() { std::cout << "Printing default constructor called" << std::endl; }
    virtual ~Printing() { std::cout << "Printing destructor called" << std::endl; }
    virtual void print() = 0;
    virtual std::string getParam() = 0;
};

#endif