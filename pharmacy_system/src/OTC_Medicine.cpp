#include "OTC_Medicine.h"

OTC_Medicine::OTC_Medicine()
    : Medicine() {
}

OTC_Medicine::OTC_Medicine(std::string name,
                           std::string manufacturer,
                           std::string batchNumber,
                           double price,
                           int quantity,
                           std::string expirationDate)
    : Medicine(name, manufacturer, batchNumber,
               price, quantity, expirationDate) {
}

double OTC_Medicine::calculateFinalPrice() const {
    return getPrice();
}