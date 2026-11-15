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

    int choice;

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

        std::cin >> choice;

        std::cout << std::endl;

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
                std::cin >> type;

                std::cout << "Name: ";
                std::cin >> name;

                std::cout << "Manufacturer: ";
                std::cin >> manufacturer;

                std::cout << "Batch number: ";
                std::cin >> batchNumber;

                std::cout << "Price: ";
                std::cin >> price;

                std::cout << "Quantity: ";
                std::cin >> quantity;

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

                    std::cout << "Doctor name: ";
                    std::cin >> doctorName;

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

                std::cout << "Medicine name: ";
                std::cin >> name;

                pharmacy.searchMedicine(name);
                break;
            }

            case 4: {
                std::string batchNumber, prescriptionCode;
                int quantity;

                std::cout << "Batch number: ";
                std::cin >> batchNumber;

                std::cout << "Quantity: ";
                std::cin >> quantity;

                std::cout << "Prescription code (0 if not required): ";
                std::cin >> prescriptionCode;

                if (prescriptionCode == "0") {
                    prescriptionCode = "";
                }

                pharmacy.sellMedicine(batchNumber, quantity, prescriptionCode);
                break;
            }

            case 5: {
                std::string name;

                std::cout << "Medicine name: ";
                std::cin.ignore();
                std::getline(std::cin,name);

                pharmacy.removeMedicine(name);
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

    } while (choice != 0);


    return 0;
}