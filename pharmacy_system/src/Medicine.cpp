#include "Medicine.h"

#include <stdexcept>
#include <utility>

Medicine::Medicine()
    : name("Unknown"),
      manufacturer("Unknown"),
      batchNumber("N/A"),
      price(0.0),
      quantity(0),
      expirationDate("01-01-2099") {
}

Medicine::Medicine(std::string name,
                   std::string manufacturer,
                   std::string batchNumber,
                   double price,
                   int quantity,
                   std::string expirationDate)
    : name(std::move(name)),
      manufacturer(std::move(manufacturer)),
      batchNumber(std::move(batchNumber)),
      price(price),
      quantity(quantity),
      expirationDate(std::move(expirationDate)) {

    if (price < 0 || quantity < 0) {
        throw std::invalid_argument(
            "Price and quantity cannot be negative"
        );
    }
}

std::string Medicine::getName() const {
    return name;
}

std::string Medicine::getManufacturer() const {
    return manufacturer;
}

std::string Medicine::getBatchNumber() const {
    return batchNumber;
}

double Medicine::getPrice() const {
    return price;
}

int Medicine::getQuantity() const {
    return quantity;
}

std::string Medicine::getExpirationDate() const {
    return expirationDate;
}

void Medicine::setName(std::string name) {
    this->name = std::move(name);
}

void Medicine::setManufacturer(std::string manufacturer) {
    this->manufacturer = std::move(manufacturer);
}
void Medicine::setBatchNumber(std::string batchNumber) {
    this->batchNumber = std::move(batchNumber);
}
void Medicine::setExpirationDate(std::string expirationDate) {
    this->expirationDate = std::move(expirationDate);
}

void Medicine::setPrice(double price) {
    if (price < 0) {
        throw std::invalid_argument("Invalid price");
    }

    this->price = price;
}

void Medicine::setQuantity(int quantity) {
    if (quantity < 0) {
        throw std::invalid_argument("Invalid quantity");
    }

    this->quantity = quantity;
}

double Medicine::calculateFinalPrice() const {
    return price;
}