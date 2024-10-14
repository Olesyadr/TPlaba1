#include "keeper.h"
#include "Poet.h"
#include "Novelist.h"
#include "Fantastic.h"
#include "Printing.h"
#include "Exeption.h"
#include <fstream>
#include <iostream>
#include <typeinfo>   
#include <stdexcept>

Keeper::Keeper()
{
    books = nullptr;
    numBooks = 0;
    std::cout << "Keeper default constructor called\n";
}

Keeper::~Keeper()
{
    for (int i = 0; i < numBooks; i++)
    {
        delete books[i]; 
    }
    delete[] books; 
    std::cout << "Keeper default destructor called\n";
}

void Keeper::add(Printing* book)
{
    Printing** newBooks = new Printing * [numBooks + 1];
    for (int i = 0; i < numBooks; i++)
    {
        newBooks[i] = books[i];
    }
    newBooks[numBooks] = book; 
    numBooks++;
    delete[] books; 
    books = newBooks; 
}

void Keeper::remove(int index)
{
    if (index >= numBooks || index < 0)
        throw Exception("There is no such object!\n");

    Printing** newBooks = new Printing * [numBooks - 1];
    int j = 0;
    for (int i = 0; i < numBooks; i++)
    {
        if (i != index)
        {
            newBooks[j++] = books[i]; 
        }
    }
    delete books[index]; 
    delete[] books; 
    books = newBooks; 
    numBooks--;
}

void Keeper::print()
{
    if (numBooks == 0)
        throw Exception("There are no objects!\n");
    for (int i = 0; i < numBooks; i++)
    {
        books[i]->print();
    }
}

void Keeper::saveToFile(const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        throw Exception("Cannot open file for writing!\n");
    }
    ofs.write(reinterpret_cast<char*>(&numBooks), sizeof(numBooks)); 
    for (int i = 0; i < numBooks; i++) {
        std::string type = typeid(*books[i]).name(); 
        size_t typeSize = type.size();
        ofs.write(reinterpret_cast<char*>(&typeSize), sizeof(typeSize)); 
        ofs.write(type.c_str(), typeSize); 
        books[i]->serialize(ofs); 
    }
    ofs.close();
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        throw Exception("Cannot open file for reading!\n");
    }
    ifs.read(reinterpret_cast<char*>(&numBooks), sizeof(numBooks)); 
    books = new Printing * [numBooks]; 
    for (int i = 0; i < numBooks; i++) {
        size_t typeSize;
        ifs.read(reinterpret_cast<char*>(&typeSize), sizeof(typeSize)); 
        std::string type(typeSize, ' '); 
        ifs.read(&type[0], typeSize); 

        Printing* book = nullptr;
        if (type == typeid(Poet).name()) {
            book = new Poet();
        }
        else if (type == typeid(Novelist).name()) {
            book = new Novelist();
        }
        else if (type == typeid(Fantastic).name()) {
            book = new Fantastic();
        }
        else {
            throw Exception("Unknown book type!\n");
        }
        book->deserialize(ifs); 
        books[i] = book; 
    }
    ifs.close();
}
