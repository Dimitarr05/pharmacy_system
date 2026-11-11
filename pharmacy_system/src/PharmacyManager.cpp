#include "PharmacyManager.h"
#include <iostream>

void PharmacyManager::addMedicine(Medicine* medicine) {
    medicines.push_back(medicine);
}

void PharmacyManager::displayMedicines() const {
    for (int i = 0; i < medicines.size(); i++) {
        std::cout << "Name: " << medicines[i]->getName() << std::endl;
        std::cout << "Manufacturer: " << medicines[i]->getManufacturer() << std::endl;
        std::cout << "Price: " << medicines[i]->calculateFinalPrice() << " EUR" << std::endl;
        std::cout << "Quantity: " << medicines[i]->getQuantity() << std::endl;
        std::cout << "Expiration date: " << medicines[i]->getExpirationDate() << std::endl;
        std::cout << "-------" << std::endl;
    }
}

void PharmacyManager::searchMedicine(std::string name) const {
    bool found = false;

    for (int i = 0; i < medicines.size(); i++) {
        if (medicines[i]->getName() == name) {
            std::cout << "Medicine found!" << std::endl;
            std::cout << "Name: " << medicines[i]->getName() << std::endl;
            std::cout << "Price: " << medicines[i]->calculateFinalPrice() << " EUR" << std::endl;
            std::cout << "Quantity: " << medicines[i]->getQuantity() << std::endl;

            found = true;
        }
    }

    if (!found) {
        std::cout << "Medicine not found!" << std::endl;
    }
}

