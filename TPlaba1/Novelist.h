#ifndef NOVELIST_H
#define NOVELIST_H
#include <string>
#include "Printing.h"
#include <fstream>
class Novelist : public Printing
{
private:
    std::string fullname;
    std::string years;
    std::string work;
    std::string text;
public:
    Novelist() {
        std::cout << "Default Novelist constructor used" << std::endl;
    }
    Novelist(std::string fullname, std::string years, std::string work, std::string text) : fullname(fullname), years(years), work(work), text(text) { std::cout << "Parametrized Novelist constructor used" << std::endl; }
    Novelist(const Novelist& other) : fullname(other.fullname), years(other.years), work(other.work), text(other.text) {
        std::cout << "Copy Novelist constructor used" << std::endl;
    }
    ~Novelist();
    void print();
    std::string getParam();
    void serialize(std::ofstream& ofs) const override;
    void deserialize(std::ifstream& ifs) override;
    bool operator!=(const Novelist& other) const;
};

#endif