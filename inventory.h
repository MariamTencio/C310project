#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
#include <vector>

class Inventory {
public:
    Inventory();
    ~Inventory();  // Destructor to clean up dynamic memory

    void addItem(const std::string& name, int quantity, double price);
    void removeItem(const std::string& name);
    void displayInventory() const;

private:
    std::vector<Item*> items;  // Vector to hold pointers to Item objects

    Item* findItem(const std::string& name) const;
};

#endif // INVENTORY_H
