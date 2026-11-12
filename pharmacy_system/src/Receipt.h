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
    Receipt();
    Receipt(std::string medicineName, int quantity, double unitPrice);

    std::string getMedicineName() const;
    int getQuantity() const;
    double getUnitPrice() const;
    double getTotalPrice() const;

    void setMedicineName(std::string medicineName);
    void setQuantity(int quantity);
    void setUnitPrice(double unitPrice);

    void displayReceipt() const;

    friend std::ostream& operator<<(std::ostream& out, const Receipt& receipt);
};

#endif
