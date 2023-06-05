#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger {
private:
    std::ofstream logfile;

public:
    // Конструктор
    Logger();

    // Деструктор
    ~Logger();

    // Метод для логування повідомлення
    void log(const std::string& message);
};

#endif