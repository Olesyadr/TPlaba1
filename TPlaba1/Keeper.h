#ifndef TPLABA1_KEEPER_H
#define TPLABA1_KEEPER_H

#include "Printing.h"
#include<string>
class Keeper {
private:
    Ptinting** books;
    int numBooks;
public:
    Keeper();
    ~Keeper();
    void add(Printing* books);
    void print();
    void remove(int index);
    void save(std::string fileName);
    void load(std::string fileName);
};

#endif