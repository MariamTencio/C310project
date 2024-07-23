#include "item.h"

// Constructor
Item::Item(const std::string& name, int quantity, double price)
    : name(name), quantity(quantity), price(price) {}

// Get item name
std::string Item::getName() const {
    return name;
}

// Get item quantity
int Item::getQuantity() const {
    return quantity;
}

// Get item price
double Item::getPrice() const {
    return price;
}

// Set item quantity
void Item::setQuantity(int quantity) {
    this->quantity = quantity;
}

// Set item price
void Item::setPrice(double price) {
    this->price = price;
}
