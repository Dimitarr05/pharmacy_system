#ifndef OTC_MEDICINE_H
#define OTC_MEDICINE_H

#include "Medicine.h"

class OTC_Medicine : public Medicine {
public:
    OTC_Medicine();

    OTC_Medicine(std::string name,
                 std::string manufacturer,
                 std::string batchNumber,
                 double price,
                 int quantity,
                 std::string expirationDate);

    double calculateFinalPrice() const override;
};

#endif