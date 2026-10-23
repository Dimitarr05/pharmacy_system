#include <iostream>
#include "Medicine.h"

int main() {
    Medicine medicine(
        "Paracetamol",
        "Sopharma",
        "BATCH001",
        5.50,
        100,
        "05-11-2027"
    );

    std::cout << "Medicine: "
              << medicine.getName() << '\n';

    std::cout << "Price: "
              << medicine.calculateFinalPrice() << " eur\n";

    std::cout << "Available quantity: "
              << medicine.getQuantity() << '\n';

    return 0;
}