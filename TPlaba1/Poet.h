#ifndef POET_H
#define POET_H
#include <string>
#include "Printing.h"
class Poet : public Printing
{
private:
    std::string fullname;
    std::string years;
    std::string work;
public:
   Poet(std::string fullname, std::string years, std::string work);
    explicit Poet(std::string parameters);
    ~Poet();
    void print();
    std::string getParam();
};

#endif