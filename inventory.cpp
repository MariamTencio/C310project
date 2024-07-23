#include "inventory.h"
#include <iostream>
#include <algorithm>

// Constructor
Inventory::Inventory() {
    // Initialize anything if needed (empty in this case)
}

// Destructor
Inventory::~Inventory() {
    for (Item* item : items) {
        delete item;  // Free dynamically allocated memory
    }
}

// Add or update an item
void Inventory::addItem(const std::string& name, int quantity, double price) {
    Item* item = findItem(name);
    if (item) {
        item->setQuantity(item->getQuantity() + quantity);  // Update quantity
        item->setPrice(price);  // Update price
    } else {
        items.push_back(new Item(name, quantity, price));  // Add new item
    }
}

// Remove an item by name
void Inventory::removeItem(const std::string& name) {
    auto it = std::remove_if(items.begin(), items.end(), [&](Item* item) {
        if (item->getName() == name) {
            delete item;  // Free dynamically allocated memory
            return true;
        }
        return false;
    });
    items.erase(it, items.end());  // Remove item from vector
}

// Display the inventory
void Inventory::displayInventory() const {
    if (items.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }
    std::cout << "Inventory:\n";
    for (const Item* item : items) {
        std::cout << "Name: " << item->getName()
                  << ", Quantity: " << item->getQuantity()
                  << ", Price: $" << item->getPrice() << std::endl;
    }
}

// Find an item by name
Item* Inventory::findItem(const std::string& name) const {
    for (Item* item : items) {
        if (item->getName() == name) {
            return item;
        }
    }
    return nullptr;
}
