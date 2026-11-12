#include "Receipt.h"
#include <iostream>

Receipt::Receipt(std::string medicineName, int quantity, double unitPrice) {
    this->medicineName = medicineName;
    this->quantity = quantity;
    this->unitPrice = unitPrice;
    this->totalPrice = quantity * unitPrice;
}

void Receipt::displayReceipt() const {
    std::cout << "\n========== RECEIPT ==========" << std::endl;
    std::cout << "Medicine: " << medicineName << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
    std::cout << "Unit price: " << unitPrice << " EUR" << std::endl;
    std::cout << "Total price: " << totalPrice << " EUR" << std::endl;
    std::cout << "=============================" << std::endl;
}
