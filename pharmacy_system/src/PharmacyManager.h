#ifndef PHARMACY_MANAGER_H
#define PHARMACY_MANAGER_H

#include "Medicine.h"
#include "Receipt.h"
#include <vector>

class PharmacyManager {
private:
    std::vector<Medicine*> medicines;

public:
    PharmacyManager();
    PharmacyManager(Medicine* medicine);

    ~PharmacyManager();

    void addMedicine(Medicine* medicine);
    void displayMedicines() const;
    void removeMedicine(std::string name);
    void searchMedicine(std::string name) const;
    void sellMedicine(std::string name, int quantity, std::string prescriptionCode = "");
};

#endif
