#ifndef MOBILEOPERATOR_H
#define MOBILEOPERATOR_H

#include <vector>
#include "MobileTariff.h"

class MobileOperator {
private:
    std::vector<MobileTariff> tariffs;

public:
    // ������������
    MobileOperator();

    // ������ ������
    std::vector<MobileTariff> getTariffs() const;
    int getTotalUserCount() const;

    // ������ ������
    void addTariff(const MobileTariff& tariff);
    
    // �������� ������
    void sortTariffsBySubscriptionFee();
    std::vector<MobileTariff> findTariffsInPriceRange(double minPrice, double maxPrice);
    void saveTariffsToFile(const std::string& filename, char encryptionKey);
    void printSortedTariffs();
};

#endif