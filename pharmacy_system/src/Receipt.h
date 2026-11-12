#ifndef RECEIPT_H
#define RECEIPT_H

#include <string>

class Receipt {
private:
    std::string medicineName;
    int quantity;
    double unitPrice;
    double totalPrice;

public:
    Receipt(std::string medicineName, int quantity, double unitPrice);

    void displayReceipt() const;
};

#endif
