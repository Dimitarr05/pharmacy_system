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

void PharmacyManager::removeMedicine(std::string name) {
    for (int i = 0; i < medicines.size(); i++) {
        if (medicines[i]->getName() == name) {
            delete medicines[i];

            medicines.erase(medicines.begin() + i);

            std::cout << "Medicine removed successfully!\n" << std::endl;
            return;
        }
    }

    std::cout << "Medicine not found!" << std::endl;
}


void PharmacyManager::sellMedicine(std::string name, int quantity) {
    for (int i = 0; i < medicines.size(); i++) {
        if (medicines[i]->getName() == name) {

            if (medicines[i]->isExpired()) {
                std::cout << "Cannot sell expired medicine!" << std::endl;
                return;
            }

            if (quantity <= 0) {
                std::cout << "Invalid quantity!" << std::endl;
                return;
            }

            if (medicines[i]->getQuantity() < quantity) {
                std::cout << "Not enough medicine in stock!" << std::endl;
                return;
            }

            medicines[i]->setQuantity(
                medicines[i]->getQuantity() - quantity
            );

            double totalPrice =
                medicines[i]->calculateFinalPrice() * quantity;

            std::cout << "Sale completed successfully!" << std::endl;
            std::cout << "Medicine: " << name << std::endl;
            std::cout << "Quantity sold: " << quantity << std::endl;
            std::cout << "Total price: " << totalPrice << " EUR" << std::endl;

            return;
        }
    }

    std::cout << "Medicine not found!" << std::endl;
}

