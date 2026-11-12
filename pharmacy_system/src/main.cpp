#include <iostream>
#include "Medicine.h"
#include "OTC_Medicine.h"
#include "PrescriptionMedicine.h"
#include "PharmacyManager.h"

int main() {
    PharmacyManager pharmacy;

    pharmacy.loadMedicines();

    pharmacy.displayMedicines();

    std::cout << "\nSearching for Paracetamol:\n";
    pharmacy.searchMedicine("Paracetamol");

    // std::cout << "\nRemoving Paracetamol..\n";
    // pharmacy.removeMedicine("Paracetamol");
    // pharmacy.displayMedicines();

    // std::cout << "\nSelling Paracetamol:\n";
    // pharmacy.sellMedicine("Paracetamol", 5);
    // std::cout << "\nUpdated inventory:\n";
    // pharmacy.displayMedicines();
    pharmacy.sellMedicine("Paracetamol", 5);
    pharmacy.sellMedicine("Voltaren", 2, "RX001");
    pharmacy.sellMedicine("Voltaren", 2, "wrong code");

    pharmacy.saveMedicines();
    pharmacy.displayMedicines();

    return 0;
}