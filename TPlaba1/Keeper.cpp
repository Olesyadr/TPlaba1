#include "keeper.h"
#include "Poet.h"
#include "Novelist.h"
#include "Fantastic.h"
#include "Printing.h"
#include "Exeption.h"
#include <fstream>
#include <iostream>

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
    delete[] book;
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
void Keeper::save(std::string filename)
{
    std::ofstream file(filename);
    file << numBooks << std::endl;
    for (int i = 0; i < numBooks; i++) {
        file << books[i]->getParam() << "\n";

    }
    file.close();
}

void Keeper::load(std::string filename)
{
    std::ifstream file(filename);
    std::string s;
    while (getline(file, s))
    {
        std::string book, parameters;
        book = s.substr(0, s.find(' '));
        s.erase(0, s.find(' ') + 1);
        parameters = s;
        std::cout << parameters << std::endl;
        if (book == "Poet")
        {
            Poet* ptr;
            ptr = new Poet(parameters);
            this->add(ptr);
        }
        if (book == "Novelist")
        {
            Novelist* nov;
            nov = new Novelist(parameters);
            this->add(nov);
        }
        if (book == "Fantastic")
        {
            Fantastic* fnt;
            fnt = new Fantastic(parameters);
            this->add(fnt);
        }
    }
    file.close();
}