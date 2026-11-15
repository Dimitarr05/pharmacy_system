#include <iostream>
#include "Medicine.h"
#include "OTC_Medicine.h"
#include "PrescriptionMedicine.h"
#include "PharmacyManager.h"
#include <limits>

int main() {
    PharmacyManager pharmacy;

    pharmacy.loadMedicines();
    pharmacy.loadSalesHistory();

    int choice = -1;

    do {
        std::cout << "\n===== PHARMACY MANAGEMENT SYSTEM =====\n";
        std::cout << "1. Display medicines\n";
        std::cout << "2. Add medicine\n";
        std::cout << "3. Search medicine\n";
        std::cout << "4. Sell medicine\n";
        std::cout << "5. Remove medicine\n";
        std::cout << "6. Sales history\n";
        std::cout << "0. Save and exit\n";
        std::cout << "Choose: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');

            choice = -1;

            std::cout << "Invalid input! Please enter a number.\n";
            continue;
}

        std::cout << std::endl;

        try {
            switch (choice) {

                case 1:
                    pharmacy.displayMedicines();
                    break;

                case 2: {
                    int type;
                    std::string name, manufacturer, batchNumber, expirationDate;
                    double price;
                    int quantity;

                    std::cout << "1. OTC medicine\n";
                    std::cout << "2. Prescription medicine\n";
                    std::cout << "Choose type: ";

                    if (!(std::cin >> type)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid medicine type!\n";
                        break;
                    }

                    std::cin.ignore(1000, '\n');

                    std::cout << "Name: ";
                    std::getline(std::cin, name);

                    std::cout << "Manufacturer: ";
                    std::getline(std::cin, manufacturer);

                    std::cout << "Batch number: ";
                    std::getline(std::cin, batchNumber);

                    std::cout << "Price: ";

                    if (!(std::cin >> price)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid price!\n";
                        break;
                    }

                    std::cout << "Quantity: ";

                    if (!(std::cin >> quantity)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid quantity!\n";
                        break;
                    }

                    std::cout << "Expiration date (DD-MM-YYYY): ";
                    std::cin >> expirationDate;

                    if (type == 1) {
                        pharmacy.addMedicine(
                            new OTC_Medicine(name, manufacturer, batchNumber,
                                             price, quantity, expirationDate)
                        );
                    }
                    else if (type == 2) {
                        std::string prescriptionCode, doctorName;

                        std::cout << "Prescription code: ";
                        std::cin >> prescriptionCode;

                        std::cin.ignore(1000, '\n');

                        std::cout << "Doctor name: ";
                        std::getline(std::cin, doctorName);

                        pharmacy.addMedicine(
                            new PrescriptionMedicine(
                                name, manufacturer, batchNumber,
                                price, quantity, expirationDate,
                                prescriptionCode, doctorName
                            )
                        );
                    }
                    else {
                        std::cout << "Invalid type!\n";
                    }

                    break;
                }

                case 3: {
                    std::string name;

                    std::cin.ignore(1000, '\n');

                    std::cout << "Medicine name: ";
                    std::getline(std::cin, name);

                    pharmacy.searchMedicine(name);
                    break;
                }

                case 4: {
                    std::string batchNumber, prescriptionCode;
                    int quantity;

                    std::cout << "Batch number: ";
                    std::cin >> batchNumber;

                    std::cout << "Quantity: ";

                    if (!(std::cin >> quantity)) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid quantity!\n";
                        break;
                    }

                    std::cout << "Prescription code (0 if not required): ";
                    std::cin >> prescriptionCode;

                    if (prescriptionCode == "0") {
                        prescriptionCode = "";
                    }

                    pharmacy.sellMedicine(batchNumber, quantity, prescriptionCode);
                    break;
                }

                case 5: {
                    std::string batchNumber;

                    std::cin.ignore(1000, '\n');

                    std::cout << "Batch number: ";
                    std::getline(std::cin, batchNumber);

                    pharmacy.removeMedicine(batchNumber);
                    break;
                }

                case 6:
                    pharmacy.displaySalesHistory();
                    break;

                case 0:
                    pharmacy.saveMedicines();
                    pharmacy.saveSalesHistory();
                    std::cout << "Goodbye!\n";
                    break;

                default:
                    std::cout << "Invalid option!\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

    } while (choice != 0);

    return 0;
}