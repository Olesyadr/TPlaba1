#ifndef POET_H
#define POET_H
#include <string>
#include "Printing.h"
#include <fstream>
class Poet : public Printing
{
private:
    std::string fullname;
    std::string years;
    std::string work;
public:
    Poet() {
        std::cout << "Default Poet constructor used" << std::endl;
    }
   Poet(std::string fullname, std::string years, std::string work) : fullname(fullname), years(years), work(work) { std::cout << "Parametrized Poet constructor used" << std::endl; }
   Poet(const Poet& other) : fullname(other.fullname), years(other.years), work(other.work) { std::cout << "Copy Poet constructor used" << std::endl;
   }
    ~Poet();
    void print();
    std::string getParam();
    void serialize(std::ofstream& ofs) const override;
    void deserialize(std::ifstream& ifs) override;
    bool operator!=(const Poet& other) const;
};

#endif