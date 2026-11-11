
#include "PrescriptionMedicine.h"

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

double PrescriptionMedicine::calculateFinalPrice() const {
    return getPrice();
}
