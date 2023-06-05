#include "MobileTariff.h"
#include <iostream>

// Конструктор за замовчуванням
MobileTariff::MobileTariff() {
    m_userCount = 0;
    m_subscriptionFee = 0.0;
    m_minutesToOtherNumbers = 0;
    m_internetData = 0;
}

// Конструктор з параметрами
MobileTariff::MobileTariff(const std::string& name, const std::string& country, int userCount, double subscriptionFee,
    int minutesToOtherNumbers, int internetData) {
    m_name = name;
    m_country = country;
    m_userCount = userCount;
    m_subscriptionFee = subscriptionFee;
    m_minutesToOtherNumbers = minutesToOtherNumbers;
    m_internetData = internetData;
}

// Методи гетери
std::string MobileTariff::getName() const {
    return m_name;
}

std::string MobileTariff::getCountry() const {
    return m_country;
}

int MobileTariff::getUserCount() const {
    return m_userCount;
}

double MobileTariff::getSubscriptionFee() const {
    return m_subscriptionFee;
}

int MobileTariff::getMinutesToOtherNumbers() const {
    return m_minutesToOtherNumbers;
}

int MobileTariff::getInternetData() const {
    return m_internetData;
}

// Методи сетери
void MobileTariff::setName(const std::string& name) {
    m_name = name;
}

void MobileTariff::setCountry(const std::string& country) {
    m_country = country;
}

void MobileTariff::setUserCount(int userCount) {
    m_userCount = userCount;
}

void MobileTariff::setSubscriptionFee(double subscriptionFee) {
    m_subscriptionFee = subscriptionFee;
}

void MobileTariff::setMinutesToOtherNumbers(int minutesToOtherNumbers) {
    m_minutesToOtherNumbers = minutesToOtherNumbers;
}

void MobileTariff::setInternetData(int internetData) {
    m_internetData = internetData;
}

// Метод для шифрування даних тарифу з використанням XOR
std::string MobileTariff::encryptData(char encryptionKey) const {
    std::string encryptedData = "";
    for (char c : m_name) {
        encryptedData += c ^ encryptionKey;
    }
    encryptedData += "|";
    for (char c : m_country) {
        encryptedData += c ^ encryptionKey;
    }
    encryptedData += "|";
    encryptedData += std::to_string(m_userCount ^ encryptionKey);
    encryptedData += "|";
    encryptedData += std::to_string(static_cast<int>(m_subscriptionFee) ^ encryptionKey);
    encryptedData += "|";
    encryptedData += std::to_string(m_minutesToOtherNumbers ^ encryptionKey);
    encryptedData += "|";
    encryptedData += std::to_string(m_internetData ^ encryptionKey);

    return encryptedData;
}

// Перевантаження оператора виводу
std::ostream& operator<<(std::ostream& os, const MobileTariff& tariff) {
    os << "Name: " << tariff.m_name << std::endl;
    os << "Country: " << tariff.m_country << std::endl;
    os << "User Count: " << tariff.m_userCount << std::endl;
    os << "Subscription Fee: " << tariff.m_subscriptionFee << std::endl;
    os << "Minutes to Other Numbers: " << tariff.m_minutesToOtherNumbers << std::endl;
    os << "Internet Data: " << tariff.m_internetData << std::endl;

    return os;
}