#include "Shop.h"
#include <iostream>
using namespace std;

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add Overcoat\n";
    cout << "2. Remove Overcoat\n";
    cout << "3. Edit Overcoat Size\n";
    cout << "4. Find Overcoats by Type\n";
    cout << "5. Sort Overcoats by Price\n";
    cout << "6. Exit\n";
}

void addSampleOvercoats(Shop& shop) {
    shop.addOvercoat(Overcoat("Winter Jacket", "men", "40", 150.0));
    shop.addOvercoat(Overcoat("Raincoat", "women", "38", 120.0));
    shop.addOvercoat(Overcoat("Trench Coat", "kids", "30", 100.0));
    shop.addOvercoat(Overcoat("Spring Jacket", "men", "42", 130.0));
    shop.addOvercoat(Overcoat("Summer Coat", "women", "36", 110.0));
    shop.addOvercoat(Overcoat("Autumn Coat", "kids", "32", 90.0));
}

int main() {
    Shop myShop;
    addSampleOvercoats(myShop);

    cout << "-------------------------------------------\n";
    cout << "-------------------------------------------\n";
    myShop.displayAllOvercoats();
    cout << "-------------------------------------------\n";
    cout << "-------------------------------------------\n";

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Overcoat newCoat;
                cin >> newCoat;
                myShop.addOvercoat(newCoat);
                cout << "New overcoat added.\n";
                myShop.displayAllOvercoats();
                break;
            }
            case 2: {
                size_t index;
                cout << "Enter index of overcoat to remove: ";
                cin >> index;
                myShop.removeOvercoat(index);
                cout << "Overcoat removed.\n";
                myShop.displayAllOvercoats();
                break;
            }
            case 3: {
                size_t index;
                int option;
                std::cout << "Enter index of overcoat to edit: ";
                std::cin >> index;
                std::cout << "Enter 1 to increase size by 2 or 0 to decrease size by 1: ";
                std::cin >> option;
                myShop.editOvercoatSize(index, option);
                std::cout << "Overcoat size updated.\n";
                myShop.displayAllOvercoats();
                break;
            }
            case 4: {
                string type;
                cout << "Enter type to search (men/women/kids): ";
                cin >> type;
                auto foundCoats = myShop.findOvercoatsByType(type);
                cout << "Found overcoats:\n";
                for (const auto& coat : foundCoats) {
                    cout << coat << endl;
                }
                break;
            }
            case 5: {
                myShop.sortOvercoatsByPrice();
                cout << "Overcoats sorted by price.\n";
                myShop.displayAllOvercoats();
                break;
            }
            case 6: {
                cout << "Exiting program.\n";
                break;
            }
            default: {
                cout << "Invalid choice, please try again.\n";
            }
        }
    } while (choice != 6);

    return 0;
}
