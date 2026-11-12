#include "PharmacyManager.h"
#include "PrescriptionMedicine.h"
#include <iostream>

PharmacyManager::PharmacyManager() {
}

PharmacyManager::PharmacyManager(Medicine* medicine) {
    if (medicine != nullptr) {
        medicines.push_back(medicine);
    }
}

PharmacyManager::~PharmacyManager() {
    for (int i = 0; i < medicines.size(); i++) {
        delete medicines[i];
    }

    medicines.clear();
}

void PharmacyManager::addMedicine(Medicine* medicine) {
    if (medicine != nullptr) {
        medicines.push_back(medicine);
    }
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

void PharmacyManager::sellMedicine(std::string name, int quantity, std::string prescriptionCode) {
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

            PrescriptionMedicine* prescriptionMedicine =
                dynamic_cast<PrescriptionMedicine*>(medicines[i]);

            if (prescriptionMedicine != nullptr) {
                if (prescriptionCode != prescriptionMedicine->getPrescriptionCode()) {
                    std::cout << "Invalid prescription code!" << std::endl;
                    return;
                }
            }

            double unitPrice = medicines[i]->calculateFinalPrice();

            medicines[i]->setQuantity(
                medicines[i]->getQuantity() - quantity
            );

            Receipt receipt(name, quantity, unitPrice);
            receipt.displayReceipt();

            return;
        }
    }

    std::cout << "Medicine not found!" << std::endl;
}
