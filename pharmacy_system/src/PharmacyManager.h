#ifndef PHARMACY_MANAGER_H
#define PHARMACY_MANAGER_H

#include "Medicine.h"
#include <vector>

class PharmacyManager {
private:
    std::vector<Medicine*> medicines;

public:
    ~PharmacyManager();

    void addMedicine(Medicine* medicine);
    void displayMedicines() const;
    void removeMedicine(std::string name);
    void searchMedicine(std::string name) const;
    void sellMedicine(std::string name, int quantity);
};

#endif
