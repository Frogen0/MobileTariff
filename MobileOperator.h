#ifndef MOBILEOPERATOR_H
#define MOBILEOPERATOR_H

#include <vector>
#include "MobileTariff.h"

class MobileOperator {
private:
    std::vector<MobileTariff> tariffs;

public:
    // Конструктори
    MobileOperator();

    // Методи гетери
    std::vector<MobileTariff> getTariffs() const;
    int getTotalUserCount() const;

    // Методи сетери
    void addTariff(const MobileTariff& tariff);
    
    // Додаткові методи
    void sortTariffsBySubscriptionFee();
    std::vector<MobileTariff> findTariffsInPriceRange(double minPrice, double maxPrice);
    void saveTariffsToFile(const std::string& filename, char encryptionKey);
    void printSortedTariffs();
};

#endif