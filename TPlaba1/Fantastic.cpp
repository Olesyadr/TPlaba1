#include "Fantastic.h"
#include "Printing.h"
#include <iostream>

Fantastic::~Fantastic()
{
    std::cout << "Fantastic default destructor called\n";
}

void Fantastic::print() {
    std::cout << "Fantastic: " << "\n";
    std::cout << fullname << " " << work << " " << film << "\n";
}

std::string Fantastic::getParam() {
    std::string parameters;
    parameters = "Fantastic " + fullname + " " + work + " " + film;
    return parameters;
}

void Fantastic::serialize(std::ofstream& ofs) const {
    size_t nameSize = fullname.size();
    ofs.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
    ofs.write(fullname.c_str(), nameSize);

    size_t workSize = work.size();
    ofs.write(reinterpret_cast<const char*>(&workSize), sizeof(workSize));
    ofs.write(work.c_str(), workSize);
    
    size_t filmSize = film.size();
    ofs.write(reinterpret_cast<const char*>(&filmSize), sizeof(filmSize));
    ofs.write(film.c_str(), filmSize);
}

void Fantastic::deserialize(std::ifstream& ifs) {
    size_t nameSize;
    ifs.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
    fullname.resize(nameSize);
    ifs.read(&fullname[0], nameSize);

    size_t workSize;
    ifs.read(reinterpret_cast<char*>(&workSize), sizeof(workSize));
    work.resize(workSize);
    ifs.read(&work[0], workSize); 
    
    size_t filmSize;
    ifs.read(reinterpret_cast<char*>(&filmSize), sizeof(filmSize));
    film.resize(filmSize);
    ifs.read(&film[0], filmSize);
}

bool Fantastic::operator!=(const Fantastic& other) const {
    return fullname != other.fullname ||
        film != other.film ||
        work != other.work;
}