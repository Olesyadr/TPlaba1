#ifndef FANTASTIC_H
#define FANTASTIC_H
#include <string>
#include "Printing.h"
#include <fstream>
class Fantastic : public Printing
{
private:
    std::string fullname;
    std::string work;
    std::string film;
public:
    Fantastic() {
        std::cout << "Default Fantastic constructor used" << std::endl;
    }
    Fantastic(std::string fullname, std::string work, std::string text) : fullname(fullname), work(work), film(film) { std::cout << "Parametrized Fantastic constructor used" << std::endl; }
    Fantastic(const Fantastic& other) : fullname(other.fullname), work(other.work), film(other.film) {
        std::cout << "Copy Fantastic constructor used" << std::endl;
    }
    ~Fantastic();
    void print();
    std::string getParam();
    void serialize(std::ofstream& ofs) const override;
    void deserialize(std::ifstream& ifs) override;
    bool operator!=(const Fantastic& other) const;
};

#endif