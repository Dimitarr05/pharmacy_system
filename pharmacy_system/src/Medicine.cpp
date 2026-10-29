#include "Medicine.h"

#include <stdexcept>
#include <utility>
#include <sstream>
#include <ctime>

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

    if (!isValidDate()) {
    throw std::invalid_argument(
        "Invalid expiration date"
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
    std::string oldDate = this->expirationDate;

    this->expirationDate = expirationDate;

    if (!isValidDate()) {
        this->expirationDate = oldDate;

        throw std::invalid_argument(
            "Invalid expiration date"
        );
    }
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

bool Medicine::isValidDate() const {
    if (expirationDate.length() != 10 ||
        expirationDate[2] != '-' ||
        expirationDate[5] != '-') {
        return false;
    }

    int day, month, year;
    char separator1, separator2;

    std::istringstream input(expirationDate);

    input >> day >> separator1 >> month
          >> separator2 >> year;

    if (input.fail() ||
        separator1 != '-' ||
        separator2 != '-') {
        return false;
    }

    if (month < 1 || month > 12 ||
        day < 1 || year < 1) {
        return false;
    }

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    bool leapYear = (year % 400 == 0) ||
                    (year % 4 == 0 && year % 100 != 0);

    if (leapYear) {
        daysInMonth[1] = 29;
    }

    return day <= daysInMonth[month - 1];
}

bool Medicine::isExpired() const {
    if (!isValidDate()) {
        throw std::invalid_argument("Invalid expiration date");
    }

    std::time_t now = std::time(nullptr);
    std::tm* currentDate = std::localtime(&now);

    int currentDay = currentDate->tm_mday;
    int currentMonth = currentDate->tm_mon + 1;
    int currentYear = currentDate->tm_year + 1900;

    int day = std::stoi(expirationDate.substr(0, 2));
    int month = std::stoi(expirationDate.substr(3, 2));
    int year = std::stoi(expirationDate.substr(6, 4));

    if (year < currentYear) {
        return true;
    }

    if (year == currentYear && month < currentMonth) {
        return true;
    }

    if (year == currentYear &&
        month == currentMonth &&
        day < currentDay) {
        return true;
    }

    return false;
}