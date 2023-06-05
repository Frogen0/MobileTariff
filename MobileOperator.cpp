#include "MobileOperator.h"
#include <algorithm>
#include <fstream>
#include <iostream>

// ����������� �� �������������
MobileOperator::MobileOperator() {
}

// ����� ����� ��� ��������� ������ �������
std::vector<MobileTariff> MobileOperator::getTariffs() const {
    return tariffs;
}

// ����� ����� ��� ��������� �������� ������� ������������
int MobileOperator::getTotalUserCount() const {
    int totalUserCount = 0;
    for (const MobileTariff& tariff : tariffs) {
        totalUserCount += tariff.getUserCount();
    }
    return totalUserCount;
}

// ����� ����� ��� ��������� ������
void MobileOperator::addTariff(const MobileTariff& tariff) {
    tariffs.push_back(tariff);
}

// ����� ��� ���������� ������� �� ������������ ������
void MobileOperator::sortTariffsBySubscriptionFee() {
    std::sort(tariffs.begin(), tariffs.end(),
        [](const MobileTariff& t1, const MobileTariff& t2) {
            return t1.getSubscriptionFee() < t2.getSubscriptionFee();
        });
}

// ����� ��� ������ ������� � �������� ������� ���
std::vector<MobileTariff> MobileOperator::findTariffsInPriceRange(double minPrice, double maxPrice) {
    std::vector<MobileTariff> matchingTariffs;
    for (const MobileTariff& tariff : tariffs) {
        if (tariff.getSubscriptionFee() >= minPrice && tariff.getSubscriptionFee() <= maxPrice) {
            matchingTariffs.push_back(tariff);
        }
    }
    return matchingTariffs;
}

// ����� ��� ���������� ����� ������� � ���� � ����������� XOR
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
    // ���������� ������� �� ������������ ������
    std::sort(tariffs.begin(), tariffs.end(),
        [](const MobileTariff& a, const MobileTariff& b) {
            return a.getSubscriptionFee() < b.getSubscriptionFee();
        });

    // ��������� ������������ �������
    std::cout << "Sorted Tariffs:" << std::endl;
    for (const MobileTariff& tariff : tariffs) {
        std::cout << tariff << std::endl;
    }
}