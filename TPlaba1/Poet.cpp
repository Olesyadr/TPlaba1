#include "Poet.h"
#include "Printing.h"
#include <iostream>
Poet::Poet(std::string fullname, std::string years, std::string work)
{
    this->fullname = fullname;
    this->years = years;
    this->work = work;
 
    std::cout << "Poet default constructor called\n";
}

Poet::Poet(std::string parameters)
{
    this->fullname = parameters.substr(0, parameters.find(' '));
    parameters.erase(0, parameters.find(' ') + 1);
    this->years = parameters.substr(0, parameters.find(' '));
    parameters.erase(0, parameters.find(' ') + 1);
    this->work = parameters.substr(0, parameters.find(' '));
    parameters.erase(0, parameters.find(' ') + 1);

    std::cout << "Poet load-from-file constructor called\n";
}

Poet::~Poet()
{
    std::cout << "Poet default destructor called\n";
}

void Poet::print() {
    std::cout << "Poet: " << "\n";
    std::cout << fullname << " " << years << " " << work << "\n";
}

std::string Poet::getParam() {
    std::string parameters;
    parameters = "Poet " + fullname + " " + years + " " + work;
    return parameters;
}