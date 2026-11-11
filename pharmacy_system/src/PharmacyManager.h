#ifndef PHARMACY_MANAGER_H
#define PHARMACY_MANAGER_H

#include "Medicine.h"
#include <vector>

class PharmacyManager {
private:
    std::vector<Medicine*> medicines;

public:
    void addMedicine(Medicine* medicine);
    void displayMedicines() const;
};

#endif
