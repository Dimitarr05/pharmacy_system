
#ifndef PRESCRIPTION_MEDICINE_H
#define PRESCRIPTION_MEDICINE_H

#include "Medicine.h"

class PrescriptionMedicine : public Medicine {
private:
    std::string prescriptionCode;
    std::string doctorName;

public:
    PrescriptionMedicine();

    PrescriptionMedicine(std::string name,
                         std::string manufacturer,
                         std::string batchNumber,
                         double price,
                         int quantity,
                         std::string expirationDate,
                         std::string prescriptionCode,
                         std::string doctorName);

    std::string getPrescriptionCode() const;
    std::string getDoctorName() const;

    void setPrescriptionCode(std::string prescriptionCode);
    void setDoctorName(std::string doctorName);

    double calculateFinalPrice() const override;
};

#endif
