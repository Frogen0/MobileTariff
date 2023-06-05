#include <iostream>
#include "MobileOperator.h"
#include "MobileTariff.h"
#include "Logger.h"

int main() {
    // Створення об'єкту класу Logger
    Logger logger;

    // Створення об'єкту класу MobileOperator
    MobileOperator mobileOperator;

    // Додавання тарифів до оператора
    mobileOperator.addTariff(MobileTariff("Tariff 1", "Country 1", 100, 10.0, 500, 2));
    mobileOperator.addTariff(MobileTariff("Tariff 2", "Country 2", 200, 15.0, 1000, 5));
    mobileOperator.addTariff(MobileTariff("Tariff 3", "Country 3", 150, 12.0, 800, 3));

    // Виведення загальної чисельності клієнтів
    int totalUserCount = mobileOperator.getTotalUserCount();
    std::cout << "Total User Count: " << totalUserCount << std::endl;

    // Сортування тарифів за абонентською платою
    mobileOperator.sortTariffsBySubscriptionFee();

    // Виведення відсортованих тарифів
    mobileOperator.printSortedTariffs();

    // Пошук тарифу в заданому діапазоні абонентської плати
    double minFee = 10.0;
    double maxFee = 15.0;
    std::cout << "Tariffs in the price range $" << minFee << " - $" << maxFee << ":" << std::endl;
    std::vector<MobileTariff> foundTariffs = mobileOperator.findTariffsInPriceRange(minFee, maxFee);
    for (const MobileTariff& tariff : foundTariffs) {
        std::cout << tariff << std::endl;
    }

    // Запис даних всіх тарифів у файл з шифруванням XOR
    mobileOperator.saveTariffsToFile("tariffs.txt", 'A');

    // Логування важливого моменту роботи програми
    logger.log("Program executed successfully.");

    return 0;
}