#include <iostream>
#include "Medicine.h"
#include "OTC_Medicine.h"
#include "PrescriptionMedicine.h"
#include "PharmacyManager.h"

int main() {
    PharmacyManager pharmacy;

    OTC_Medicine* medicine1 = new OTC_Medicine(
        "Paracetamol",
        "Sopharma",
        "BATCH001",
        5.50,
        100,
        "05-11-2027"
    );

    PrescriptionMedicine* medicine2 = new PrescriptionMedicine(
        "Voltaren",
        "Sopharma",
        "BATCH002",
        12.50,
        50,
        "10-12-2027",
        "RX001",
        "Dr. Ivanov"
    );

    pharmacy.addMedicine(medicine1);
    pharmacy.addMedicine(medicine2);

    pharmacy.displayMedicines();

    delete medicine1;
    delete medicine2;

    return 0;
}