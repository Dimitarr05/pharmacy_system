#ifndef MEDICINE_H
#define MEDICINE_H

#include <string>

class Medicine {
private:
    std::string name;
    std::string manufacturer;
    std::string batchNumber;
    double price;
    int quantity;
    std::string expirationDate;

public:
    Medicine();

    Medicine(std::string name,
             std::string manufacturer,
             std::string batchNumber,
             double price,
             int quantity,
             std::string expirationDate);

    std::string getName() const;
    std::string getManufacturer() const;
    std::string getBatchNumber() const;
    double getPrice() const;
    int getQuantity() const;
    std::string getExpirationDate() const;

    void setName(std::string name);
    void setPrice(double price);
    void setQuantity(int quantity);
    void setManufacturer(std::string manufacturer);
    void setBatchNumber(std::string batchNumber);
    void setExpirationDate(std::string expirationDate);

    virtual double calculateFinalPrice() const;

    virtual ~Medicine() = default;

};

#endif