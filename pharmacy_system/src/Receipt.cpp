
#include "Receipt.h"
#include <iostream>
#include <stdexcept>

Receipt::Receipt() {
    medicineName = "";
    quantity = 0;
    unitPrice = 0.0;
    totalPrice = 0.0;
}

Receipt::Receipt(std::string medicineName, int quantity, double unitPrice) {
    if (quantity < 0 || unitPrice < 0) {
        throw std::invalid_argument("Invalid receipt data!");
    }

    this->medicineName = medicineName;
    this->quantity = quantity;
    this->unitPrice = unitPrice;
    this->totalPrice = quantity * unitPrice;
}

std::string Receipt::getMedicineName() const {
    return medicineName;
}

int Receipt::getQuantity() const {
    return quantity;
}

double Receipt::getUnitPrice() const {
    return unitPrice;
}

double Receipt::getTotalPrice() const {
    return totalPrice;
}

void Receipt::setMedicineName(std::string medicineName) {
    this->medicineName = medicineName;
}

void Receipt::setQuantity(int quantity) {
    if (quantity < 0) {
        throw std::invalid_argument("Quantity cannot be negative!");
    }

    this->quantity = quantity;
    totalPrice = quantity * unitPrice;
}

void Receipt::setUnitPrice(double unitPrice) {
    if (unitPrice < 0) {
        throw std::invalid_argument("Price cannot be negative!");
    }

    this->unitPrice = unitPrice;
    totalPrice = quantity * unitPrice;
}

std::ostream& operator<<(std::ostream& out, const Receipt& receipt) {
    out << "\n========== RECEIPT ==========" << std::endl;
    out << "Medicine: " << receipt.medicineName << std::endl;
    out << "Quantity: " << receipt.quantity << std::endl;
    out << "Unit price: " << receipt.unitPrice << " EUR" << std::endl;
    out << "Total price: " << receipt.totalPrice << " EUR" << std::endl;
    out << "=============================" << std::endl;

    return out;
}

void Receipt::displayReceipt() const {
    std::cout << *this;
}
