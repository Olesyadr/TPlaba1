#ifndef PRINTING_H
#define PRINTING_H
#include <iostream>
#include <fstream>
class Printing
{
public:
    Printing() { std::cout << "Printing default constructor called" << std::endl; }
    virtual ~Printing() { std::cout << "Printing destructor called" << std::endl; }
    virtual void print() = 0;
    virtual std::string getParam() = 0;
    virtual void serialize(std::ofstream& ofs) const = 0;
    virtual void deserialize(std::ifstream& ifs) = 0;
};

#endif