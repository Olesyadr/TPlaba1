#include "Novelist.h"
#include "Printing.h"
#include <iostream>

Novelist::~Novelist()
{
    std::cout << "Novelist default destructor called\n";
}

void Novelist::print() {
    std::cout << "Novelist: " << "\n";
    std::cout << fullname << " " << years << " " << work << " " << text << "\n";
}

std::string Novelist::getParam() {
    std::string parameters;
    parameters = "Novelist " + fullname + " " + years + " " + work + " " + text;
    return parameters;
}
void Novelist::serialize(std::ofstream& ofs) const {
    size_t nameSize = fullname.size();
    ofs.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
    ofs.write(fullname.c_str(), nameSize);

    size_t yearsSize = years.size();
    ofs.write(reinterpret_cast<const char*>(&yearsSize), sizeof(yearsSize));
    ofs.write(years.c_str(), yearsSize);

    size_t workSize = work.size();
    ofs.write(reinterpret_cast<const char*>(&workSize), sizeof(workSize));
    ofs.write(work.c_str(), workSize);

    size_t textSize = text.size();
    ofs.write(reinterpret_cast<const char*>(&textSize), sizeof(textSize));
    ofs.write(text.c_str(), textSize);
}

void Novelist::deserialize(std::ifstream& ifs) {
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

    size_t textSize;
    ifs.read(reinterpret_cast<char*>(&textSize), sizeof(textSize));
    text.resize(textSize);
    ifs.read(&text[0], textSize);
}
bool Novelist::operator!=(const Novelist& other) const {
    return fullname != other.fullname ||
        years != other.years ||
        work != other.work;
}