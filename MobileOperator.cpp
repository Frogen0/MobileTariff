#include "MobileOperator.h"
#include <algorithm>
#include <fstream>
#include <iostream>

// Конструктор за замовчуванням
MobileOperator::MobileOperator() {
}

// Метод гетер для отримання списку тарифів
std::vector<MobileTariff> MobileOperator::getTariffs() const {
    return tariffs;
}

// Метод гетер для отримання загальної кількості користувачів
int MobileOperator::getTotalUserCount() const {
    int totalUserCount = 0;
    for (const MobileTariff& tariff : tariffs) {
        totalUserCount += tariff.getUserCount();
    }
    return totalUserCount;
}

// Метод сетер для додавання тарифу
void MobileOperator::addTariff(const MobileTariff& tariff) {
    tariffs.push_back(tariff);
}

// Метод для сортування тарифів за абонентською платою
void MobileOperator::sortTariffsBySubscriptionFee() {
    std::sort(tariffs.begin(), tariffs.end(),
        [](const MobileTariff& t1, const MobileTariff& t2) {
            return t1.getSubscriptionFee() < t2.getSubscriptionFee();
        });
}

// Метод для пошуку тарифів в заданому діапазоні цін
std::vector<MobileTariff> MobileOperator::findTariffsInPriceRange(double minPrice, double maxPrice) {
    std::vector<MobileTariff> matchingTariffs;
    for (const MobileTariff& tariff : tariffs) {
        if (tariff.getSubscriptionFee() >= minPrice && tariff.getSubscriptionFee() <= maxPrice) {
            matchingTariffs.push_back(tariff);
        }
    }
    return matchingTariffs;
}

// Метод для збереження даних тарифів у файл з шифруванням XOR
void MobileOperator::saveTariffsToFile(const std::string& filename, char encryptionKey) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const MobileTariff& tariff : tariffs) {
            std::string encryptedData = tariff.encryptData(encryptionKey);
            file << encryptedData << std::endl;
        }
        file.close();
    }
}

void MobileOperator::printSortedTariffs() {
    // Сортування тарифів за абонентською платою
    std::sort(tariffs.begin(), tariffs.end(),
        [](const MobileTariff& a, const MobileTariff& b) {
            return a.getSubscriptionFee() < b.getSubscriptionFee();
        });

    // Виведення відсортованих тарифів
    std::cout << "Sorted Tariffs:" << std::endl;
    for (const MobileTariff& tariff : tariffs) {
        std::cout << tariff << std::endl;
    }
}