#include "Poet.h"
#include "Printing.h"
#include <iostream>

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
void Poet::serialize(std::ofstream& ofs) const {
    size_t nameSize = fullname.size();
    ofs.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
    ofs.write(fullname.c_str(), nameSize);

    size_t yearsSize = years.size();
    ofs.write(reinterpret_cast<const char*>(&yearsSize), sizeof(yearsSize));
    ofs.write(years.c_str(), yearsSize);

    size_t workSize = work.size();
    ofs.write(reinterpret_cast<const char*>(&workSize), sizeof(workSize));
    ofs.write(work.c_str(), workSize);
}

void Poet::deserialize(std::ifstream& ifs) {
    size_t nameSize;
    ifs.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
    fullname.resize(nameSize);
    ifs.read(&fullname[0], nameSize);

    size_t yearsSize;
    ifs.read(reinterpret_cast<char*>(&yearsSize), sizeof(yearsSize));
    years.resize(yearsSize);
    ifs.read(&years[0], yearsSize);

    size_t workSize;
    ifs.read(reinterpret_cast<char*>(&workSize), sizeof(workSize));
    work.resize(workSize);
    ifs.read(&work[0], workSize);
}
bool Poet::operator!=(const Poet& other) const {
    return fullname != other.fullname ||
        years != other.years ||
        work != other.work;
}