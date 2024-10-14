#ifndef TPLABA1_KEEPER_H
#define TPLABA1_KEEPER_H

#include "Printing.h"
#include<string>
#include "Exeption.h"
#include <fstream>

class Keeper {
private:
    Printing** books;
    int numBooks;
public:
    Keeper();
    ~Keeper();
    void add(Printing* books);
    void print();
    void remove(int index);
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};

#endif