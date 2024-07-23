#include "inventory.h"

int main() {
    Inventory* inventory = new Inventory();  // Dynamically allocate Inventory object
    int choice;

    do {
        std::cout << "\n--- Inventory System ---\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Remove Item\n";
        std::cout << "3. Display Inventory\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                int quantity;
                double price;
                std::cout << "Enter item name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                std::cout << "Enter price: ";
                std::cin >> price;
                inventory->addItem(name, quantity, price);
                break;
            }
            case 2: {
                std::string name;
                std::cout << "Enter item name to remove: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                inventory->removeItem(name);
                break;
            }
            case 3:
                inventory->displayInventory();
                break;
            case 4:
                std::cout << "Exiting the system.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    delete inventory;  // Free the dynamically allocated Inventory object
    return 0;
}
