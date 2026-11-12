#include "PrescriptionMedicine.h"
#include <stdexcept>

PrescriptionMedicine::PrescriptionMedicine()
    : Medicine(),
      prescriptionCode("N/A"),
      doctorName("Unknown") {
}

PrescriptionMedicine::PrescriptionMedicine(
    std::string name,
    std::string manufacturer,
    std::string batchNumber,
    double price,
    int quantity,
    std::string expirationDate,
    std::string prescriptionCode,
    std::string doctorName)
    : Medicine(name, manufacturer, batchNumber,
               price, quantity, expirationDate),
      prescriptionCode(prescriptionCode),
      doctorName(doctorName) {
}

std::string PrescriptionMedicine::getPrescriptionCode() const {
    return prescriptionCode;
}

std::string PrescriptionMedicine::getDoctorName() const {
    return doctorName;
}

void PrescriptionMedicine::setPrescriptionCode(std::string prescriptionCode) {
    if (prescriptionCode.empty()) {
        throw std::invalid_argument("Prescription code cannot be empty!");
    }

    this->prescriptionCode = prescriptionCode;
}

void PrescriptionMedicine::setDoctorName(std::string doctorName) {
    if (doctorName.empty()) {
        throw std::invalid_argument("Doctor name cannot be empty!");
    }

    this->doctorName = doctorName;
}

double PrescriptionMedicine::calculateFinalPrice() const {
    return getPrice();
}
