#include <iostream>
#include <string>
#include "Exeption.h"
#include "Keeper.h"
#include "Poet.h"
#include "Novelist.h"
#include "Fantastic.h"

using namespace std;

void showMenu()
{
    std::cout << "\nMenu:\n"
        "1. Add book\n"
        "2. Remove book\n"
        "3. Print book\n"
        "4. Save to File\n"
        "5. Restore from File\n"
        "6. Exit\n";
}

int main()
{
    Keeper keeper;
    while (true)
    {
        showMenu();
        int choice;
        cout << "\nEnter your choice:\n";
        cin >> choice;
        try {
            switch (choice) {
            case 1: {
                int book;
                cout << "\nEnter book type\n"
                    "1. Poet 2. Novelist 3. Fantastic:\n";
                cin >> book;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                switch (book) {
                case 1: {
                    string fullname;
                    string years;
                    string work;
                    Poet* ptr;
                    std::cout << "Enter Poet fullname:\n";
                    std::getline(std::cin, fullname);
                    std::cout << "Enter Poet years of living:\n";
                    std::getline(std::cin, years); 
                    std::cout << "Enter Poet works:\n";
                    std::getline(std::cin, work);
                    ptr = new Poet(fullname, years, work);
                    keeper.add(ptr);
                    break;
                }
                case 2: {
                    string fullname;
                    string years;
                    string work;
                    string text;
                    Novelist* nov;
                    std::cout << "Enter Novelist fullname:\n";
                    std::getline(std::cin, fullname); 
                    std::cout << "Enter Novelist years of living:\n";
                    std::getline(std::cin, years); 
                    std::cout << "Enter Novelist works:\n";
                    std::getline(std::cin, work);
                    std::cout << "Enter Novelist short biography:\n";
                    std::getline(std::cin, text);
                    nov = new Novelist(fullname, years, work, text);
                    keeper.add(nov);
                    break;
                }
                case 3: {
                    string fullname;
                    string work;
                    string film;
                    Fantastic* fnt;
                    std::cout << "Enter Fantastic fullname:\n";
                    std::getline(std::cin, fullname);
                    std::cout << "Enter Fantastic works:\n";
                    std::getline(std::cin, work);
                    std::cout << "Enter Fantastic film:\n";
                    std::getline(std::cin, film); 
                    fnt = new Fantastic(fullname, work, film);
                    keeper.add(fnt);
                    break;
                }
                default: {
                    cout << "Invalid type\n";
                    break;
                }
                }
                break;
            }
            case 2: {
                int index;
                cout << "Enter book index:\n";
                cin >> index;
                keeper.remove(index);
                break;
            }
            case 3: {
                keeper.print();
                break;
            }
            case 4: {
                string filename;
                cout << "Enter filename to save the data (e.g., books.dat):\n";
                cin >> filename;
                keeper.saveToFile(filename);
                cout << "Books saved to " << filename << "\n";
                break;
            }
            case 5: {
                string filename;
                cout << "Enter filename to load the data from (e.g., books.dat):\n";
                cin >> filename;
                keeper.loadFromFile(filename);
                cout << "Books loaded from " << filename << "\n";
                break;
            }
            case 6: {
                cout << "Goodbye!\n";
                return 0;
            }
            default: {
                cout << "Invalid choice\n";
                break;
            }
            }
        }
        catch (Exception error)
        {
            cout << error;
        }
    }
}