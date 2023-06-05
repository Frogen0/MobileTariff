#ifndef MOBILETARIFF_H
#define MOBILETARIFF_H

#include <string>

class MobileTariff {
private:
    std::string m_name;
    std::string m_country;
    int m_userCount;
    double m_subscriptionFee;
    int m_minutesToOtherNumbers;
    int m_internetData;

public:
    // Конструктор за замовчуванням
    MobileTariff();

    // Конструктор з параметрами
    MobileTariff(const std::string& name, const std::string& country, int userCount, double subscriptionFee,
        int minutesToOtherNumbers, int internetData);

    // Методи гетери
    std::string getName() const;
    std::string getCountry() const;
    int getUserCount() const;
    double getSubscriptionFee() const;
    int getMinutesToOtherNumbers() const;
    int getInternetData() const;

    // Методи сетери
    void setName(const std::string& name);
    void setCountry(const std::string& country);
    void setUserCount(int userCount);
    void setSubscriptionFee(double subscriptionFee);
    void setMinutesToOtherNumbers(int minutesToOtherNumbers);
    void setInternetData(int internetData);

    // Метод для шифрування даних тарифу з використанням XOR
    std::string encryptData(char encryptionKey) const;

    // Перевантаження оператора виводу
    friend std::ostream& operator<<(std::ostream& os, const MobileTariff& tariff);
};

#endif